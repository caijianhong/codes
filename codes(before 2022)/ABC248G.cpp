#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cassert>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
const int P=998244353;
template<int N> struct siever{
	vector<int> d[N+10];
	siever(){
		for(int i=1;i<=N;i++){
			for(int j=i;j<=N;j+=i) d[j].push_back(i);
		}
	}
};
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    int vis[N+10],tag; 
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head),memset(vis,tag=0,sizeof vis);}
    edge&operator[](int i){return e[i];}
    void add(int u,int v,T w=0){
		if(vis[u]!=tag) vis[u]=tag,head[u]=0;
		e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;
	}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int n,a[100010];
LL ans,cnt,f[100010];
int vis[100010];
graph<100010,100010> t,g;
vector<int> e[100010];
siever<100010> s; 
LL calc(pair<LL,LL> a,pair<LL,LL> b){
	return ((a.first*b.second+b.first*a.second-a.second*b.second%P+P))%P;
}
pair<LL,LL> dfs(int u,int fa,LL &ans){
	vis[u]=g.tag;
	pair<LL,LL> tot={1,1};
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa) continue;
		pair<LL,LL> res=dfs(v,u,ans);
		res={(res.first+res.second)%P,res.second};
		ans=(ans+calc(tot,res))%P;
		tot={(tot.first+res.first)%P,(tot.second+res.second)%P};
	}
	return tot;
}
void dp(int d){
	g.tag++,g.cnt=0;
	for(int i:e[d]) g.link(t[i].u,t[i].v),debug("link (%d,%d)\n",t[i].u,t[i].v);
	for(int i:e[d]) if(vis[t[i].u]!=g.tag) dfs(t[i].u,0,f[d]);
	for(int i:e[d]) if(vis[t[i].v]!=g.tag) dfs(t[i].v,0,f[d]);
	if(f[d]) debug("f[%d]=%lld\n",d,f[d]);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		t.add(u,v);
		for(int d:s.d[gcd(a[u],a[v])]) e[d].push_back(i),debug("(%d,%d) belongs to tree %d\n",u,v,d); 
	}
	for(int i=1;i<=1e5;i++) dp(i);
	for(int i=1e5;i>=1;i--){
		for(int j=i+i;j<=1e5;j+=i) f[i]=(f[i]-f[j]+P)%P;
		ans=(ans+f[i]*i)%P;
	}
	printf("%lld\n",ans);
	return 0;
}

