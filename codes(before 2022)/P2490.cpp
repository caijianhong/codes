#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int P=1e9+7;
LL qpow(LL a,LL b,int p=P){LL res=1;for(;b;b>>=1,a=a*a%p) if(b&1) res=res*a%p;return res;}
template<int N,int p=P> struct C{
	LL fac[N+10],ifac[N+10];
	C(){
		for(int i=fac[0]=ifac[0]=1;i<=N;i++) fac[i]=fac[i-1]*i%p;
		ifac[N]=qpow(fac[N],p-2,p);
		for(int i=N-1;i>=1;i--) ifac[i]=ifac[i+1]*(i+1)%p;
	}
	LL operator()(int n,int m){return fac[n]*ifac[n-m]%p*ifac[m]%p;}
};
int n,k,d;
LL ans=0,f[16][10010]; 
C<10010> c;
LL dfs(int now,int res){
	if(res==0||now==-1) return !res;
	LL &ans=f[now][res];
	if(~ans) return ans; else ans=0;
	for(int j=0;j*(d+1)<<now<=res&&j*(d+1)<=k/2;j++){
		ans=(ans+dfs(now-1,res-(j*(d+1)<<now))*c(k/2,j*(d+1))%P)%P;
	}
	return ans;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%d",&n,&k,&d);
	memset(f,-1,sizeof f);
	for(int i=0;i<=n-k;i++) ans=(ans+dfs(15,i)*c(n-i-k/2,k/2)%P)%P;
	printf("%lld\n",(c(n,k)-ans+P)%P); 
	return 0;
}

