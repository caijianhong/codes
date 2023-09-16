#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define cap first
#define cst second
typedef long long LL;
typedef pair<LL,LL> node;
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=T()):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge& operator[](int i){return e[i];}
    void add(int u,int v,T w){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w){add(u,v,w),add(v,u,w);}
    void insert(int u,int v,LL w,LL z){add(u,v,node(w,z)),add(v,u,node(0,-z));}
};
int n,m,s0,t0,pre[100010],cur[100010];
LL dis[100010],h[100010];
bool vis[100010];
graph<100010,100010,node> g;
bool spfa(int s){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	memset(h,0,sizeof h);
	queue<int> q;
	pre[s]=1,dis[s]=0;
	for(q.push(s);!q.empty();){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(g[i].w.cap&&dis[v]>dis[u]+g[i].w.cst){
				dis[v]=dis[u]+g[i].w.cst;
				pre[v]=i;
				if(!vis[v]){
					if(++h[u]>=n) return 0;
					q.push(v),vis[v]=1;
				}
			}
		}
	}
	return 1;
}
bool dijkstra(int s,int t){
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	priority_queue<node,vector<node>,greater<node>> q;
	pre[s]=1;
	for(q.push(node(dis[s]=0,s));!q.empty();){
		int u=q.top().second;q.pop();
		if(vis[u]) continue; else vis[u]=1;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;LL w=g[i].w.cst+h[u]-h[v];
			if(g[i].w.cap&&dis[v]>dis[u]+w){
				pre[v]=i;
				q.push(node(dis[v]=dis[u]+w,v));
			}
		}
	}
	return dis[t]<dis[0];
}
LL dfs(int u,LL flow,int t){
	if(u==t||!flow) return flow;
	LL rest=flow;
	vis[u]=1;
	for(int &i=cur[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(!g[i].w.cap||vis[v]||g[i].w.cst+h[u]-h[v]) continue;
		if(LL ans=dfs(v,min(rest,g[i].w.cap),t)){
			g[i].w.cap-=ans,g[i^1].w.cap+=ans;
			rest-=ans;
			if(!rest) break;
		}
	}
	if(flow>rest) vis[u]=0;
	return flow-rest;
}
node maxflow(int s,int t){
	node flow=node(0,0);
	if(!spfa(s)) return node(-1,0);
	memcpy(h,dis,sizeof h);
	while(dijkstra(s,t)){
		for(int i=1;i<=n;i++) h[i]+=dis[i];
		memcpy(cur,g.head,sizeof cur);
		memset(vis,0,sizeof vis);
		LL res=dfs(s,1e18,t);
		flow.cap+=res,flow.cst+=res*h[t];
	}
	return flow;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	g.add(0,0,node(0,0));
	scanf("%d%d%d%d",&n,&m,&s0,&t0);
	for(int i=1,u,v,w,z;i<=m;i++) scanf("%d%d%d%d",&u,&v,&w,&z),g.insert(u,v,w,z);
	node res=maxflow(s0,t0);
	printf("%lld %lld\n",res.first,res.second);
	return 0;
}

