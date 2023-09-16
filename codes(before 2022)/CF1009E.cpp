#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int P=998244353;
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
int n;
LL a[1000010],ans;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]=(a[i]+a[i-1])%P;
	for(int i=1;i<=n-1;i++){
		//卡边：n-i-1 任选 =>1
		//不卡边：n-i-2 任选 =>n-i
		ans=(ans+a[i]*qpow(2,n-i-1,P))%P;//尾 
		ans=(ans+a[i]*qpow(2,n-i,P))%P;//头 
		ans=(ans+a[i]*(n-i-1)%P*qpow(2,max(n-i-2,0)))%P;
	}
	ans=(ans+a[n])%P;
	printf("%lld\n",ans); 
	return 0;
}
/*
............aaaaaaa........
a[i]*(n-i+1)*2^(n-i-1)
*/
