#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
const int P=1e9+7;
LL mod(LL x){return x%P;}
void red(LL&x){x=mod(x);}
LL getbit(int k){return 1ll<<k;}
bool conbit(LL x,int k){return x&getbit(k);} 
LL qpow(LL a,LL b,int p=P){LL r=1;for(a%=p;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p; return r;}
int n;
LL z,f[61][2][1<<10];
LL C[1<<10][1<<10];
//LL dfs(int d,bool lim,int ad){//ad<=1000
//	if(d==60) return lim&&!ad;//有进位就肯定是假的 
//	if(~f[d][lim][ad]) return f[d][lim][ad];
//	LL ans=0;
//	for(int i=0;i<=n;i++){//有 i 个 1 在这一位 
//		if(i%2!=conbit(z,d)) continue;
//		int sum=ad+i,dit=sum&1;
//		red(ans+=C[n][i]*dfs(d+1,lim?dit<=conbit(m,d):dit<conbit(m,d),sum>>1));
//	}
//	return f[d][lim][ad]=ans;
//}
//LL solve(LL m0){
//	memset(f,-1,sizeof f);
//	m=m0;
//	return dfs(0,1,0); 
//} 
LL dp(LL m){
	memset(f,0,sizeof f),f[60][1][0]=1;
	for(int d=59;d>=0;d--){
		int zd=conbit(z,d),md=conbit(m,d);
		for(int lim=0;lim<=1;lim++){
			for(int ad=0;ad<1<<10;ad++){
				for(int i=0;i<=n;i++){
					if((i&1)!=zd) continue;
					int sum=ad+i;
					red(
						f[d][lim][ad]
						+=C[n][i]*f[d+1][lim?(sum&1)<=md:(sum&1)<md][sum>>1] 
					);
				}
			}
		}
	}
	debug("dp(%lld)=%lld\n",m,f[0][1][0]);
	return f[0][1][0];
}
int main(){
	for(int i=0;i<1<<10;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	}
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	LL l,r;
	scanf("%d%lld%lld%lld",&n,&l,&r,&z);
	printf("%lld\n",mod(dp(r)-dp(l-1)+P));
	return 0;
}

