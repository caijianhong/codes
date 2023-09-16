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
int n,m; 
graph<500010,2000010> g,t;
int dfn[500010],low[500010],stk[500010],cnt,top,col[500010],dcc,siz[500010];
bool vis[2000010<<1];
void tarjan(int u){
	dfn[u]=low[stk[++top]=u]=++cnt;
	for(int i=g.head[u];i;i=g.nxt[i]){
		if(vis[i]||vis[i^1]) continue;
		int v=g[i].v;
		if(!dfn[v]) vis[i]=vis[i^1]=1,tarjan(v),low[u]=min(low[u],low[v]);
		else low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		col[u]=++dcc;
		do col[stk[top]]=dcc; while(stk[top--]!=u);
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	g.add(0,0);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),g.link(u,v);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) t.add(col[i],i),siz[col[i]]++;
	printf("%d\n",dcc);
	for(int u=1;u<=dcc;u++){
		printf("%d ",siz[u]);
		for(int i=t.head[u];i;i=t.nxt[i]) printf("%d ",t[i].v);
		puts("");
	}
	return 0;
}

