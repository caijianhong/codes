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
typedef unsigned long long LL;
template<int N> struct dsy{
	int fa[N+10];
	dsy(){for(int i=1;i<=N;i++) fa[i]=i;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
};
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge&operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
typedef graph<0,0,int>::edge ask;
int n,m,t[1<<24],a[500010],sum[500010],ret[500010];
ask q[500010];
graph<500010,750010,int> g,que;
dsy<500010> s;
void dfs(int u,int fa=0){
	sum[u]=a[u]^sum[fa],t[u]=1;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa) continue;
		dfs(v,u),s.fa[v]=u;
	}
	for(int i=que.head[u];i;i=que.nxt[i]){
		if(t[que[i].v]) ret[que[i].w]=s.find(que[i].v);
	}
}
void solve(int u,int fa=0){
	t[a[u]]++;
	for(int i=que.head[u];i;i=que.nxt[i]) ret[que[i].v]+=que[i].w*t[q[que[i].v].w];
	for(int i=g.head[u];i;i=g.nxt[i]) if(g[i].v!=fa) solve(g[i].v,u);
	t[a[u]]--;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].w),que.link(q[i].u,q[i].v,i);
	dfs(1),memset(t,0,sizeof t),memset(que.head,que.cnt=0,sizeof que.head);
	for(int i=1;i<=m;i++) debug("lca(%d,%d)=%d\n",q[i].u,q[i].v,ret[i]);
	for(int i=1;i<=m;i++) q[i].w^=sum[q[i].u]^sum[q[i].v]^a[ret[i]],que.add(q[i].u,i,1),que.add(ret[i],i,-2),que.add(q[i].v,i,1),ret[i]=q[i].w==a[ret[i]];
	solve(1);
	for(int i=1;i<=m;i++) puts(ret[i]?"yes":"no");
	return 0;
}

