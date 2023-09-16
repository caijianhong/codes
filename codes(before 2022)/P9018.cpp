#include <cstdio>
#include <vector>
#include <cstdlib>
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
LL mod(LL x){return (x%P+P)%P;}
void red(LL&x){x=mod(x);}
LL qpow(LL a,LL b,int p){LL r=1;for(a%=p;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p; return r;}
template<int N,int P> struct C_prime{
	LL fac[N+10],ifac[N+10];
	C_prime(){
		for(int i=fac[0]=ifac[0]=1;i<=N;i++) fac[i]=fac[i-1]*i%P;
		ifac[N]=qpow(fac[N],P-2,P);
		for(int i=N-1;i>=1;i--) ifac[i]=ifac[i+1]*(i+1)%P;
	}
	LL operator()(int n,int m){return fac[n]*ifac[n-m]%P*ifac[m]%P;}
};
int n,a[100010];
LL res=1;
C_prime<1000010,P> C;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]>>=1;
	for(int i=2;i<=n;i++){
		if(a[i-1]>=a[i]) red(res*=C(a[i-1],a[i]));
		else red(res*=C(a[i]-1,a[i-1]-1));
	}
	printf("%lld\n",res);
	return 0;
}

