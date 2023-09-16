#include <cstdio>
#include <vector>
#include <cstring>
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
template<int N,class T=int> struct longcut{
	graph<N,N,T> &g;
	int hei[N+10],son[N+10];
	longcut(graph<N,N,T> &g):g(g){memset(son,0,sizeof son);}
	void dfs(int u,int fa=0){
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(v==fa) continue;
			dfs(v,u);
			if(hei[son[u]]<hei[v]) son[u]=v;
		}
		hei[u]=hei[son[u]]+1;
	}
};
int n;
node ans[1000010];
vector<int> f[1000010];
graph<1000010,1000010> g;
longcut<1000010> e(g); 
void dp(int u,int fa=0){
	if(e.son[u]) dp(e.son[u],u),swap(f[u],f[e.son[u]]),ans[u]=ans[e.son[u]];
	f[u].push_back(1),ans[u]=max(ans[u],node(1,f[u].size()-1));
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa||v==e.son[u]) continue;
		dp(v,u);
		for(int j=0;j<e.hei[v];j++){
			int k=j+e.hei[u]-(e.hei[v]+1);
			f[u][k]+=f[v][j];
			ans[u]=max(ans[u],node(f[u][k],k));
		}
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	e.dfs(1),dp(1);
	for(int i=1;i<=n;i++) printf("%d\n",e.hei[i]-1-ans[i].second);
	return 0;
}

