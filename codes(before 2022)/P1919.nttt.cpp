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
int n,m,lim,rev[1<<21];
LL a[1<<21],b[1<<21];
void ntt(LL a[],int n,int op){
	debug("ntt(?,%d,%d)\n",n,op);
	for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int len=2,k=1;len<=n;len<<=1,k<<=1){
		LL wn=qpow(op==1?G:qpow(G,P-2,P),(P-1)/len,P);
		debug("w_%d=%lld\n",len,wn);
		for(int i=0;i<n;i+=len){
			LL w=1;
			for(int j=0;j<k;j++,w=w*wn%P){
				LL x=a[i+j],y=w*a[i+j+k]%P;
				debug("use w[%d][%d]=%lld\n",k,j,w);
				a[i+j]=(x+y)%P,a[i+j+k]=(x-y+P)%P;
			}
		}
	}
	if(op==-1) for(int i=0;i<n;i++) a[i]=a[i]*qpow(n,P-2,P)%P;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(lim=1;lim<=n+m;lim<<=1);
	for(int i=0;i<lim;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(__lg(lim)-1));
	debug("len=%d\n",lim);
	for(int i=0;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<=m;i++) scanf("%lld",&b[i]);
	ntt(a,lim,1),ntt(b,lim,1);
	for(int i=0;i<lim;i++) a[i]*=b[i];
	ntt(a,lim,-1);
	for(int i=0;i<=n+m;i++) printf("%lld%c",a[i]," \n"[i==n+m]);
	return 0;
}

