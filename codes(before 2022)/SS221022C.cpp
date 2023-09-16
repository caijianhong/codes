#include <cstdio>
#include <vector> 
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,class T> struct STable{
	int n,lg[N+10]; T f[21][N+10];
	STable():n(0){lg[0]=-1;}
	void insert(T x){
		f[0][++n]=x,lg[n]=lg[n>>1]+1;
		for(int j=1;1<<j<=n;j++){
			int i=n-(1<<j)+1;
			f[j][i]=min(f[j-1][i],f[j-1][i+(1<<(j-1))]);
		} 
	}
	T query(int l,int r){int k=lg[r-l+1];return min(f[k][l],f[k][r-(1<<k)+1]);}
}; 
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
int n,m,a[200010],pos[200010],fa[200010],dfn[200010<<1],cnt;
int d[200010],las[200010];
graph<200010,200010> g; 
STable<200010<<1,pair<int,int>> t;
void dfs(int u,int f=0,int d=0){
	dfn[pos[u]=++cnt]=u,t.insert({d,u}),fa[u]=f;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==f) continue;
		dfs(v,u,d+1),dfn[++cnt]=u,t.insert({d,u});	
	}
}
int lca(int u,int v){
	if(pos[u]>pos[v]) swap(u,v);
	return t.query(pos[u],pos[v]).second;
}
void dp(){
	for(int i=1;i<=cnt;i++){
		int u=dfn[i];
		if(las[a[u]]&&las[a[u]]!=u){
			int v=las[a[u]];
			d[fa[u]]++,d[fa[v]]++,d[lca(u,v)]--,d[fa[lca(u,v)]]--;
		} 
		las[a[u]]=u;
	}
}
void getsum(int u,int f=0){
	for(int i=g.head[u];i;i=g.nxt[i]){
		if(g[i].v!=f) getsum(g[i].v,u),d[u]+=d[g[i].v];
	}
}
int ans[200010];
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	dfs(1),dp(),getsum(1),cnt=0;
	for(int i=1;i<=n;i++) if(!d[i]) ans[++cnt]=a[i];
	sort(ans+1,ans+cnt+1),printf("%d\n",cnt=unique(ans+1,ans+cnt+1)-ans-1);
	for(int i=1;i<=cnt;i++) printf("%d%c",ans[i]," \n"[i==cnt]);
	return 0;
}

