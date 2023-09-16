#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
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
int n,fa[19][1<<18],mink[19][1<<18],dep[1<<18],dfn[1<<18],cnt;
graph<1<<18,1<<18,int> g,t;
void dfs(int u,int f=0){dep[u]=dep[fa[0][u]=f]+1,dfn[u]=++cnt;for(int i=g.head[u];i;i=g.nxt[i]) if(g[i].v!=f) dfs(g[i].v,u),mink[0][g[i].v]=g[i].w;}
int jump(int u,int k){for(int j=18;j>=0;j--) if(k>>j&1) u=fa[j][u];return u;}
int query(int u,int k){int r=1e9;for(int j=18;j>=0;j--) if(k>>j&1) r=min(r,mink[j][u]),u=fa[j][u];return r;}
int lca(int u,int v){if(dep[u]<dep[v]) swap(u,v);if(u=jump(u,dep[u]-dep[v]),u==v) return u;for(int j=18;j>=0;j--) if(fa[j][u]!=fa[j][v]) u=fa[j][u],v=fa[j][v];return fa[0][u];}
int h[1<<18],stk[1<<18],vis[1<<18];
void build(int h[],int m){
	t.tag++,t.cnt=0,h[++m]=1;
//	memset(t.head,0,sizeof t.head);
	sort(h+1,h+m+1,[&](int i,int j){return dfn[i]<dfn[j];});
	int top=1; stk[1]=1;
	auto link=[&](int u,int v){debug("link(%d->%d)(%d)\n",u,v,query(u,dep[u]-dep[v])),t.link(u,v,query(u,dep[u]-dep[v]));};
	for(int i=2;i<=m;i++){
		int k=lca(h[i],stk[top]);
		vis[h[i]]=t.tag;
		if(k!=stk[top]){
			while(top>=2&&dfn[stk[top-1]]>dfn[k]) link(stk[top],stk[top-1]),top--;
			if(stk[top-1]==k) link(stk[top],k),top--;
			else link(stk[top],k),stk[top]=k;
		}
		stk[++top]=h[i];
	}
	while(top>=2) link(stk[top],stk[top-1]),top--;
}
LL solve(int u,int f=0){
	LL ans=0;
	for(int i=t.head[u];i;i=t.nxt[i]){
		int v=t[i].v; if(v==f) continue;
		LL res=solve(v,u);
		if(vis[v]==t.tag) ans+=t[i].w;
		else ans+=min(res,(LL)t[i].w);
	}
	debug("solve(%d)=%lld\n",u,ans);
	return ans;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d",&u,&v,&w),g.link(u,v,w);
	mink[0][1]=1e9,dfs(1);
	for(int j=1;j<=18;j++){
		for(int i=1;i<=n;i++) fa[j][i]=fa[j-1][fa[j-1][i]];
		for(int i=1;i<=n;i++) mink[j][i]=min(mink[j-1][i],mink[j-1][fa[j-1][i]]);
	}
	scanf("%*d");
	for(int cnt;~scanf("%d",&cnt);){
		for(int i=1;i<=cnt;i++) scanf("%d",&h[i]);
		build(h,cnt);
		printf("%lld\n",solve(1));
	}
	return 0;
}

