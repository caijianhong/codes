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
template<class T> struct func{
	LL k,b;
	func(LL k=0,LL b=-1e18):k(k),b(b){}
	LL operator()(LL x){return k*x+b;}
};
template<int N,class T> struct lcstree{
	func<T> tag[N<<2];
	void insert(func<T> f,int p=1,int l=1,int r=N){
		int mid=(l+r)>>1;
		switch((f(l)<=tag[p](l))+(f(r)<=tag[p](r))){
			case 0: tag[p]=f; break;
			case 1: insert(f,p<<1,l,mid),insert(f,p<<1|1,mid+1,r); break;
		}
	}
	T query(int x,int p=1,int l=1,int r=N){
		T res=tag[p](x);
		if(l==r) return res;
		int mid=(l+r)>>1;
		if(x<=mid) res=max(res,query(x,p<<1,l,mid));
		else res=max(res,query(x,p<<1|1,mid+1,r));
		return res;
	}
};
int n,m,maxk;
LL s[4000100],t[4000100],f[4000100]; 
lcstree<4000100,LL> ccf;
//LL dp(){
//	f[0]=0;
//	for(int i=1;i<=maxk;i++){
//		f[i]=i*s[i]-t[i];
//		for(int j=i-m;j>=1;j--){
//			f[i]=min(f[i],f[j]+i*(s[i]-s[j])-t[i]+t[j]);
//		}
//	}
//	return *min_element(f+maxk-m,f+maxk+1);
//}
LL dp(){
	f[0]=0;
	for(int i=1;i<=maxk;i++){
		f[i]=i*s[i]-t[i];
		if(i-m>=0) ccf.insert(func<LL>(s[i-m],-f[i-m]-t[i-m]));
		f[i]=min(f[i],-ccf.query(i)+i*s[i]-t[i]);
		debug("f[%d]=%lld\n",i,f[i]);
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

