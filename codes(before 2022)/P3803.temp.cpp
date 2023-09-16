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
rever<21> rev;
template<int N> struct poly{
	comp a[N];
	comp& operator[](int i){return a[i];}
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
	friend poly operator*(poly a,poly b){
		a.fft(1),b.fft(1);
		for(int i=0;i<N;i++) a[i]*=b[i];
		return a.fft(-1),a;
	}
};
int n,ans[1<<21];
char buf[1<<21];
poly<1<<21> a;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s",buf);
	n=strlen(buf);for(int i=0;i<n;i++) a[i]=buf[n-i-1]-'0';
	scanf("%s",buf);
	n=strlen(buf);for(int i=0;i<n;i++) a[i]+=comp(0,buf[n-i-1]-'0');
	a.fft(1);for(int i=0;i<1<<21;i++) a[i]*=a[i]; a.fft(-1);
	for(int i=0;i<1<<21;i++){
		ans[i]+=imag(a[i])/2+0.5;
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	int len=(1<<21)-1;for(;!ans[len];len--);
	for(int i=len;i>=0;i--) putchar(ans[i]+'0');
	return 0;
}

