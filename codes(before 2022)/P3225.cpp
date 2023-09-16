#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node; 
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
template<int N> struct dsu{
	int fa[N+10],siz[N+10],cnt;
	dsu(int n=N):cnt(n){for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){if(x=find(x),y=find(y),x!=y) cnt--,siz[x]<siz[y]?(fa[x]=y,siz[y]+=siz[x]):(fa[y]=x,siz[x]+=siz[y]);}
};
int n,m;
LL ansf,ansg=1;
dsu<100010> s;
graph<100010,100010> g;
int dfn[100010],low[100010],cut[100010],cnt,vis[100010];
void tarjan(int u){
	dfn[u]=low[u]=++cnt,cut[u]=1;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]),cut[u]+=low[v]>=dfn[u];
		else low[u]=min(low[u],dfn[v]);
	}
}
node dfs(int u,int T){
	node ans=node(1,0);
	vis[u]=T;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(vis[v]==T) continue;
		if(cut[v]>=2){ans.second++,vis[v]=T;continue;}
		node res=dfs(v,T);
		ans.first+=res.first;
		ans.second+=res.second;
	}
	return ans;
}
int mian(){
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),g.link(u,v),n=max({n,u,v});
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i),cut[i]--;
	for(int i=1;i<=n;i++){
		if(cut[i]==1&&!vis[i]){
			node res=dfs(i,i);
//			printf("i=%d,res=(%d,%d)\n",i,res.first,res.second);
			switch(res.second){
				case 0:ansf+=2,ansg*=1ll*res.first*(res.first-1)/2;break;
				case 1:ansf++,ansg*=res.first;break;
			}
		}
	}
	printf("%lld %lld\n",ansf,ansg); 
	return 0;
}
void reset(){
	n=0,ansf=0,ansg=1;
	s=dsu<100010>();
	memset(g.head,g.cnt=0,sizeof g.head);
	memset(dfn,cnt=0,sizeof dfn);
	memset(cut,0,sizeof cut);
	memset(vis,0,sizeof vis);
} 
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(int t=0;scanf("%d",&m),m;printf("Case %d: ",++t),reset(),mian());
	return 0;
}

