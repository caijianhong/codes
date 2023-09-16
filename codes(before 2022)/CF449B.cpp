#include <queue>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,int> node;
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
int n,m,k,ans,c[100010];
LL dis[100010];
bool vis[100010];
graph<100010,400010> g;
void dijkstra(int s){
	priority_queue<node,vector<node>,greater<node>> q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	for(q.push(node(dis[s]=0,s));!q.empty();){
		int u=q.top().second;q.pop();
		if(vis[u]) continue; else vis[u]=1;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(dis[v]>dis[u]+g[i].w){
				q.push(node(dis[v]=dis[u]+g[i].w,v));
			}
		}
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),g.link(u,v,w);
	for(int i=1,u=1,v,w;i<=k;i++) scanf("%d%d",&v,&w),g.link(u,v,w),c[v]++;
	dijkstra(1);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=m*2;i++){
		int u=g[i].u,v=g[i].v;
		if(dis[u]+g[i].w==dis[v]) vis[v]=1;
	}
	for(int i=1;i<=n;i++) if(c[i]>1) ans+=c[i]-1,c[i]=1;
	for(int i=1;i<=n;i++) ans+=vis[i]*c[i];
	printf("%d\n",ans);
	return 0;
}

