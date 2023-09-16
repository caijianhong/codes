#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
const int P=998244353,G=3;
LL qpow(LL a,LL b,int p){LL r=1;for(a%=p;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p; return r;}
int n,m,rev[1<<21];
LL a[1<<21],b[1<<21],w[2][1<<22];
int ntt_init(int n){
	int len=1;
	for(;len<=n;len<<=1);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|(i&1?len>>1:0);
	for(int k=1;k<<1<=len;k<<=1){
		LL wn=qpow(G,(P-1)/k/2,P);
		for(int i=w[1][k]=1;i<k;i++) w[1][k+i]=w[1][k+i-1]*wn%P;
	}
	for(int k=1;k<<1<=len;k<<=1){
		LL wn=qpow(qpow(G,P-2,P),(P-1)/k/2,P);
		for(int i=w[0][k]=1;i<k;i++) w[0][k+i]=w[0][k+i-1]*wn%P;
	}
	return len;
}
void ntt(LL a[],int n,int op){
	for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int len=2,k=1;len<=n;len<<=1,k<<=1){
		for(int i=0;i<n;i+=len){
			for(int j=0;j<k;j++){
				LL x=a[i+j],y=a[i+j+k]%P*w[op==1][k+j]%P;
				a[i+j]=x+y,a[i+j+k]=x-y+P;
			}
		}
		if(len==1<<16) for(int i=0;i<n;i++) a[i]%=P;
	}
	for(int i=0;i<n;i++) a[i]%=P;
	if(op==-1) for(int i=0;i<n;i++) a[i]=a[i]*qpow(n,P-2,P)%P;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	int lim=ntt_init(n+m);
	for(int i=0;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<=m;i++) scanf("%lld",&b[i]);
	ntt(a,lim,1),ntt(b,lim,1);
	for(int i=0;i<lim;i++) a[i]*=b[i];
	ntt(a,lim,-1);
	for(int i=0;i<=n+m;i++) printf("%lld%c",a[i]," \n"[i==n+m]);
	return 0;
}

