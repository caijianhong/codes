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
typedef complex<double> comp;
const double PI=acos(-1);
int n,m,lim,rev[1<<21];
complex<double> a[1<<21],b[1<<21];
void fft(complex<double> a[],int n,int op){
	for(int i=0;i<n;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int len=2,k=1;len<=n;len<<=1,k<<=1){
		complex<double> wn(cos(PI/k),op*sin(PI/k));
		for(int i=0;i<n;i+=len){
			complex<double> w(1,0);
			for(int j=0;j<k;j++,w*=wn){
				complex<double> x=a[i+j],y=w*a[i+j+k];
				a[i+j]=x+y,a[i+j+k]=x-y;
			}
		}
	}
	if(op==-1) for(int i=0;i<n;i++) a[i]/=n;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(lim=1;lim<=n+m;lim<<=1);
	for(int i=0;i<lim;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(__lg(lim)-1));
	for(int i=0,x;i<=n;i++) scanf("%d",&x),a[i]=x;
	for(int i=0,x;i<=m;i++) scanf("%d",&x),b[i]=x;
	fft(a,lim,1),fft(b,lim,1);
	for(int i=0;i<lim;i++) a[i]*=b[i];
	fft(a,lim,-1);
	for(int i=0;i<=n+m;i++) printf("%d%c",(int)(a[i].real()+0.5)," \n"[i==n+m]);
	return 0;
}

