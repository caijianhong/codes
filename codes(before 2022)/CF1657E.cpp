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
const int P=998244353;
void red(LL&x){x%=P;}
LL qpow(LL a,LL b,int p){LL r=1;for(a%=p;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p; return r;}
int n,m;
LL f[310][310],g[310][310],C[310][310];
LL dp(){
	for(int i=0;i<=n;i++){
		for(int j=C[i][0]=1;j<=i;j++) red(C[i][j]=C[i-1][j]+C[i-1][j-1]);
		for(int j=1;j<=n;j++) red(g[i][j]=g[i][j-1]+(i+j-1));
	}
	f[1][0]=1;
	for(int i=1;i<=m;i++){//将填数 i 
		for(int j=0;j<=n;j++){//填了 j 个数 
			debug("f[%d][%d]=%lld\n",i,j,f[i][j]);
			for(int k=0;j+k<=n;k++){//填入 k 个 i 
				red(f[i+1][j+k]+=f[i][j]*C[n-j][k]%P*qpow(i,g[n-j-k][k],P));
			}
		}
	}
	return f[m+1][n];
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m),n--;
	printf("%lld\n",dp());
	return 0;
}

