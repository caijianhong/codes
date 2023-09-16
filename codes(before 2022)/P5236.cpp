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
template<int N,int M,class T=int> struct graph{
	int head[N+10],nxt[M*2+10],cnt,tot;
	struct edge{
		int u,v; T w;
		edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
	} e[M*2+10];
	edge&operator[](int i){return e[i];}
	graph(){memset(head,cnt=0,sizeof head);}
	void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
	void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
int n,m,sum[100010],fa[18][100010],up[100010],dep[100010];
graph<100010,200010> g,t;
int getdist_cycle(int u,int v,int k){if(sum[u]<sum[v]) swap(u,v);return min(sum[u]-sum[v],sum[k]-sum[u]+sum[v]);}
void make_cycle(int u,int v,int val){
	sum[v]=val;
	for(int i=v;i!=u;i=fa[0][i]) sum[fa[0][i]]=sum[i]+up[i];
	sum[++t.tot]=sum[u],sum[u]=0;
	t.link(t.tot,u,0);
	for(int i=v;i!=u;i=fa[0][i]) t.link(t.tot,i,getdist_cycle(i,u,t.tot));
}
int dfn[100010],low[100010],cnt;
void tarjan(int u,int f=0){
	dfn[u]=low[u]=++cnt,fa[0][u]=f;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(!dfn[v]) up[v]=g[i].w,tarjan(v,u),low[u]=min(low[u],low[v]);
		else if(v!=f) low[u]=min(low[u],dfn[v]);
		if(low[v]>dfn[u]) t.link(u,v,g[i].w);
	}
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(fa[0][v]!=u&&dfn[v]>dfn[u]) make_cycle(u,v,g[i].w);
	}	
}
void dfs(int u,int f=0){dep[u]=dep[fa[0][u]=f]+1;for(int i=t.head[u];i;i=t.nxt[i]) if(t[i].v!=f) up[t[i].v]=up[u]+t[i].w,dfs(t[i].v,u);}
int jump(int u,int k){for(int j=17;j>=0;j--) if(k>>j&1) u=fa[j][u]; return u;}
int lca(int u,int v){dep[u]<dep[v]?v=jump(v,dep[v]-dep[u]):u=jump(u,dep[u]-dep[v]);for(int j=17;j>=0;j--) if(fa[j][u]!=fa[j][v]) u=fa[j][u],v=fa[j][v]; return u==v?u:fa[0][u];}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%*d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),g.link(u,v,w);
	t.tot=n,tarjan(1),dfs(1);
	debug("graph t:\n");
	for(int i=1;i<=t.cnt;i+=2) debug("(%d,%d)=%d\n",t[i].u,t[i].v,t[i].w);
	for(int i=1;i<=t.tot;i++) debug("sum[%d]=%d\n",i,sum[i]);
	for(int i=1;i<=t.tot;i++) debug("up[%d]=%d\n",i,up[i]);
	for(int j=1;j<=17;j++) for(int i=1;i<=t.tot;i++) fa[j][i]=fa[j-1][fa[j-1][i]];
	for(int u,v;~scanf("%d%d",&u,&v);){
		int k=lca(u,v);
		if(k<=n) printf("%d\n",up[u]+up[v]-2*up[k]);
		else{
			int ub=jump(u,dep[u]-dep[k]-1),vb=jump(v,dep[v]-dep[k]-1);
			printf("%d\n",up[u]-up[ub]+up[v]-up[vb]+getdist_cycle(ub,vb,k));
		}
	}
	return 0;
}

