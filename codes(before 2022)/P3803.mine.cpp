#include <cmath>
#include <cstdio>
#include <complex>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef complex<double> comp;
const double PI=acos(-1);
int n,m,len;
int rev[1<<21];
comp a[1<<21],b[1<<21];
void fft(comp a[],int flag){
	for(int i=0;i<1<<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int mid=1;mid<1<<len;mid<<=1){
		comp wn(cos(PI/mid),flag*sin(PI/mid));
		for(int j=0;j<1<<len;j+=mid<<1){
			comp w(1,0);
			for(int k=0;k<mid;k++,w=w*wn){
				comp x=a[j+k],y=w*a[j+mid+k];
				a[j+k]=x+y,a[j+mid+k]=x-y;
			}
		}
	}
} 
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=0,x;i<=n;i++) scanf("%d",&x),a[i]=x;
	for(int i=0,x;i<=m;i++) scanf("%d",&x),b[i]=x;
	while(1<<len<=n+m) len++;
	for(int i=0;i<1<<len;i++) rev[i]=rev[i>>1]>>1|(i&1)<<len-1;
	fft(a,1),fft(b,1);
	for(int i=0;i<1<<len;i++) a[i]*=b[i];
	fft(a,-1);
	for(int i=0;i<=n+m;i++) printf("%d ",(int)(real(a[i])/(1<<len)+0.5));
	return 0;
}

