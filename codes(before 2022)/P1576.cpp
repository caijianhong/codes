#include <cmath>
#include <queue>
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
	struct edge{
		int u,v; T w;
		edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
	} e[M*2+10];
	edge&operator[](int i){return e[i];}
	graph(){memset(head,cnt=0,sizeof head);}
	void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
	void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
}; 
template<int N,int M,class T=int> struct spath: public graph<N,M,T>{
	graph<N,M,T> &g=*this;
	bool vis[N+10]; T dis[N+10];
	typedef pair<T,int> node;
	T dijkstra(int s,int t){
		memset(vis,0,sizeof vis);
//		memset(dis,0x3f,sizeof dis);
		fill(dis+1,dis+N+1,1e9);
		priority_queue<node,vector<node>,greater<node>> q;
		for(q.push({dis[s]=0,s});!q.empty();){
			int u=q.top().second; q.pop();
			if(vis[u]) continue; vis[u]=1;
			for(int i=g.head[u];i;i=g.nxt[i]){
				int v=g[i].v;
				if(dis[v]>dis[u]+g[i].w) q.push({dis[v]=dis[u]+g[i].w,v});
			}
		}
		return dis[t];
	}
}; 
int n,m;
spath<100010,100010,double> g;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),g.link(u,v,-log(1-w/1e2));
	int s,t;
	scanf("%d%d",&s,&t);
	printf("%.8lf\n",100*exp(g.dijkstra(s,t)));
	//-log ×Ô´øµ¹Êý 
	return 0;
}

