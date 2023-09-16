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
template<int N,class T> struct flower{
	T b[N+10]; int cnt;
	flower():cnt(0){}
	void operator+=(T x){b[++cnt]=x;}
	void build(){sort(b+1,b+cnt+1),cnt=unique(b+1,b+cnt+1)-b-1;}
	int operator()(T x){return lower_bound(b+1,b+cnt+1,x)-b;}
};
template<int N,class T> struct fenwick{
	T c[N+10];
	fenwick(){memset(c,0,sizeof c);}
	void add(int p,T k){for(;p<=N;p+=p&-p) c[p]+=k;}
	T query(int p,T r=0){for(;p>=1;p-=p&-p) r+=c[p]; return r;}
};
int n,a[100010],L[100010],R[100010],ans;
flower<100010,int> b;
fenwick<1<<17,int> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b+=a[i];
	b.build();
	for(int i=1;i<=n;i++) a[i]=b(a[i]);
	for(int i=1;i<=n;i++){
		L[i]=t.query(1<<17)-t.query(a[i]);
		t.add(a[i],1);
	}
	memset(t.c,0,sizeof t.c);
	for(int i=n;i>=1;i--){
		R[i]=t.query(1<<17)-t.query(a[i]);
		t.add(a[i],1);
	}
	for(int i=1;i<=n;i++) ans+=max(L[i],R[i])>min(L[i],R[i])<<1;
	printf("%d\n",ans);
	return 0;
}

