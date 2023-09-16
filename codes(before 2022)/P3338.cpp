#include <cmath>
#include <cstdio>
#include <complex>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef complex<double> comp;
const double PI=acos(-1);
template<int N> struct rever{
	int rev[1<<N];
	rever(){for(int i=rev[0]=0;i<1<<N;i++) rev[i]=rev[i>>1]>>1|(i&1)<<(N-1);}
	template<class T> void make(T a[]){for(int i=0;i<1<<N;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);}
};
rever<18> rev;
template<int N> struct poly{
	comp a[N];
	comp& operator[](int i){return a[i];}
	poly& operator*=(poly &b){for(int i=0;i<N;i++) a[i]*=b[i];return *this;}
	void fft(int flag){
		rev.make(a);
		for(int mid=1;mid<N;mid<<=1){
			comp wn(cos(PI/mid),flag*sin(PI/mid));
			for(int j=0;j<N;j+=mid<<1){
				comp w(1,0);
				for(int k=0;k<mid;k++,w=w*wn){
					comp x=a[j+k],y=w*a[j+mid+k];
					a[j+k]=x+y,a[j+mid+k]=x-y;
				}
			}
		}
		if(flag==-1) for(int i=0;i<N;i++) a[i]/=N;
	}
};
int n;
poly<1<<18> a,b,c;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){double x;
		scanf("%lf",&x);
		a[i]=x,b[n-i]=x,c[i]=1.0/i/i;
	}
	a.fft(1),b.fft(1),c.fft(1),a*=c,b*=c,a.fft(-1),b.fft(-1);
	for(int i=1;i<=n;i++) printf("%.6lf\n",real(a[i])-real(b[n-i]));
	return 0;
}

