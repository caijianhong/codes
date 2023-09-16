#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<class T=double> struct dot{
	T x,y;
	dot(T x=0,T y=0):x(x),y(y){}
	dot operator+(dot b){return dot(x+b.x,y+b.y);}
	dot operator-(dot b){return dot(x-b.x,y-b.y);}
	dot operator*(T k){return dot(x*k,y*k);}
	T operator*(dot b){return x*b.y-b.x*y;}
	T operator^(dot b){return x*b.x+y*b.y;}
	friend T dist(dot a){return sqrt(a^a);}
};
int n;
LL A,B,C,f[1000010],s[1000010];
dot q[1000010];
LL dp(){
	int L=1,R=0;q[++R]=0;
	for(int i=1;i<=n;i++){
		while(L<R&&)
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%lld%lld%lld",&n,&A,&B,&C);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]),s[i]+=s[i-1];
	printf("%lld\n",dp());
	return 0;
}
/*
f[i]=max{f[j]+a(s[i]-s[j])^2+b(s[i]-s[j])+c}
f[i]-as[i]^2-bs[i]-c=-2as[i]s[j]+f[j]+as[j]^2-bs[j]
*/

