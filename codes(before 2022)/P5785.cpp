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
int n,s;
dot<LL> q[300010];
LL sc[300010],st[300010],f[300010];
dot<LL> binary(int L,int R,dot<LL> p){
	int ans=R+1;
	while(L<=R){
		int mid=(L+R)>>1;
		if((q[mid+1]-q[mid])*p>0) L=mid+1;
		else R=mid-1,ans=mid;
	}
	return q[ans];
}
LL dp(){
	int L=1,R=0;q[++R]=dot<LL>(0,0);
	for(int i=1;i<=n;i++){
//		while(L<R&&(q[L+1]-q[L])*dot<LL>(1,st[i])>0) L++;
		dot<LL> pre=binary(1,R-1,dot<LL>(1,st[i]));
		f[i]=pre.y-st[i]*pre.x+st[i]*sc[i]+sc[n]*s;
		dot<LL> p=dot<LL>(sc[i],f[i]-s*sc[i]);
		while(L<R&&(p-q[R-1])*(q[R]-q[R-1])>=0) R--;
		q[++R]=p;
	}
	return f[n];
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&st[i],&sc[i]),st[i]+=st[i-1],sc[i]+=sc[i-1];
	printf("%lld\n",dp());
	return 0;
}
/*
f[i]=f[j]+st[i]*(sc[i]-sc[j])+s*(sc[n]-sc[j])
f[i]=f[j]+st[i]sc[i]-st[i]sc[j]+sc[n]s-sc[j]s
f[i]=f[j]-s*sc[j]-st[i]sc[j],k=st[i],x=sc[j]
*/

