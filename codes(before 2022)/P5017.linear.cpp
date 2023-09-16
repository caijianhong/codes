#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
int q[4000010],n,m,maxk;
LL s[4000010],t[4000010],f[4000010];
LL dp(){
	f[0]=0;
	auto getx=[&](int i){return s[i];};
	auto gety=[&](int i){return f[i]+t[i];};
	auto getdx=[&](int i,int j){return getx(i)-getx(j);};
	auto getdy=[&](int i,int j){return gety(i)-gety(j);};
	auto slope=[&](int i,int j)->double{return 1.*getdy(i,j)/getdx(i,j);};
	int L=1,R=0; q[++R]=0;
	auto insert=[&](int i){
		while(L<R&&(getdx(q[R],i)?slope(q[R-1],q[R])>=slope(q[R],i):getdy(q[R],i)>=0)) R--;
//		while(L<R&&(__int128)(gety(q[R-1])-gety(q[R]))*(getx(q[R])-getx(i))>(__int128)(gety(q[R])-gety(i))*(getx(q[R-1])-getx(q[R]))) R--;
		if(getdx(q[R],i)) q[++R]=i;
		else if(getdy(q[R],i)>=0) q[R]=i;
	};
	auto cut=[&](int k){
		while(L<R&&slope(q[L],q[L+1])<k) L++;
//		while(L<R&&(gety(q[L])-gety(q[L+1]))<k*(getx(q[L])-getx(q[L+1]))); 
		return q[L];
	};
	for(int i=1;i<=maxk;i++){
		debug("i=%d\n",i);
		f[i]=i*s[i]-t[i];
		if(i-m>=1) insert(i-m);
		int j=cut(i);
//		for(int l=L;l<=R;l++){int j=q[l];
		f[i]=min(f[i],f[j]+i*(s[i]-s[j])-t[i]+t[j]);
		debug("j=%d, f[i].update(%lld), at (%d,%d)\n",j,f[j]+i*(s[i]-s[j])-t[i]+t[j],getx(j),gety(j));
//		}
//		debug("f[%d]=%lld (trans from j=%d)\n",i,f[i],j);
		for(int j=L;j<=R;j++) debug("%d,",q[j]);
		debug("\n");
//		for(int j=L;j<R;j++) debug("%.3lf,",slope(j,j+1));
//		debug("\n");
//		debug("slope(%d,%d)=%.3lf\n",i-1,i,slope(i-1,i));
	}
	return *min_element(f+maxk-m,f+maxk+1);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),x++,s[x]++,t[x]+=x,maxk=max(maxk,x+m);
	for(int i=1;i<=maxk;i++) s[i]+=s[i-1],t[i]+=t[i-1];//,debug("s[%d]=%lld,t[%d]=%lld\n",i,s[i],i,t[i]);
	printf("%lld\n",dp());
	return 0;
}

