#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<int N> struct counter{
	int t[N+10],mx,tot;LL ans=0,u[N+10][4];
	counter():ans(0),mx(0),tot(0){memset(t,0,sizeof t);}
	void insert(int k,int p){
		u[++tot][0]=k,u[tot][1]=p,u[tot][2]=ans,u[tot][3]=mx;
		if((t[p]+=k)>mx) ans=0,mx=t[p];
		if(t[p]==mx) ans+=p; 
	}
	void undo(int t0=0){for(;tot>t0;tot--) t[u[tot][1]]-=u[tot][0],ans=u[tot][2],mx=u[tot][3];}
}; 
template<int N,class T=int> struct treecut{
	graph<N,N,T> &g;
	int fa[N+10],siz[N+10],son[N+10],dep[N+10],
		dfn[N+10],rnk[N+10],top[N+10],cnt;
	treecut(graph<N,N,T> &g):g(g),cnt(0){memset(son,siz[0]=dep[0]=0,sizeof son);} 
	void dfs(int u,int f=0){
		dep[u]=dep[fa[u]=f]+1,siz[u]=1;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(v==fa[u]) continue;
			dfs(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v]) son[u]=v;
		} 
	}
	void cut(int u,int topf){
		top[rnk[dfn[u]=++cnt]=u]=topf;
		if(son[u]) cut(son[u],topf);
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(v==fa[u]||v==son[u]) continue;
			cut(v,v);
		} 
	}
};
int n,a[100010];LL ans[100010];
graph<100010,100010> g; 
counter<100010> c; 
treecut<100010> e(g);
void calc(int u,int avi){
	c.insert(1,a[u]);
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==e.fa[u]||v==avi) continue;
		calc(v,avi);
	} 
}
void dfs(int u,bool keep){
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==e.fa[u]||v==e.son[u]) continue;
		dfs(v,0);
	} 
	if(e.son[u]) dfs(e.son[u],1);
	calc(u,e.son[u]);
	ans[u]=c.ans;
	if(!keep) c.undo(0);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	e.dfs(1),e.cut(1,1),dfs(1,0);
	for(int i=1;i<=n;i++) printf("%lld%c",ans[i]," \n"[i==n]);
	return 0;
}

