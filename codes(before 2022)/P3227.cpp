#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int dx[]={0,-1,0,0,1},dy[]={0,0,-1,1,0};
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt,tot;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,tot=cnt=0,sizeof head);}
    edge& operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<int N,int M,class T=int> struct maxflow:public graph<N,M,T>{
	graph<N,M,T> &g=*this;
	int cur[N+10],dep[N+10]; bool vis[N+10];
	maxflow(){g.add(0,0,0);}
    int insert(int u,int v,T w){return g.add(u,v,w),g.add(v,u,0),g.cnt-1;}
	bool bfs(int s,int t){
		queue<int> q;
	    memset(dep,0,sizeof dep);
	    memcpy(cur,g.head,sizeof cur);
	    for(q.push(s),dep[s]=1;!q.empty();){
	        int u=q.front();q.pop(); 
	        for(int i=g.head[u];i;i=g.nxt[i]){
	            int v=g[i].v;
	            if(!g[i].w||dep[v]) continue;
	            q.push(v),dep[v]=dep[u]+1;
	        }
	    }
	    return dep[t];
	}
	T dfs(int u,T flow,int t){
	    if(u==t||!flow) return flow;
	    T rest=flow;
	    for(int &i=cur[u];i;i=g.nxt[i]){
	        int v=g[i].v;
	        if(!g[i].w||dep[v]!=dep[u]+1) continue;
	        if(T ans=dfs(v,min(rest,g[i].w),t)){
	            g[i].w-=ans,g[i^1].w+=ans;
	            rest-=ans;
	            if(!rest) break;
	        }
	    }
	    if(flow==rest) dep[u]=0;
	    return flow-rest;
	}
	T dinic(int s,int t,T inf=1e9){
	    T flow=0;
	    while(bfs(s,t)) flow+=dfs(s,inf,t);
	    return flow;
	}
};
int n,m,k,d,s0,t0,id[50][50];
maxflow<100010,200010,LL> g;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	s0=++g.tot,t0=++g.tot;
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			id[i][j]=g.tot,g.tot+=k;
			g.insert(s0,id[i][j]+1,1e14);
			for(int t=d+1;t<=k;t++){
				for(int dir=1;dir<=4;dir++){
					int tx=i+dx[dir],ty=j+dy[dir];
					if(1<=tx&&tx<=n&&1<=ty&&ty<=m) g.insert(id[i][j]+t,id[tx][ty]+t-d,1e14);
				}
			}
		}
	}
	for(int t=1,w;t<=k;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&w);
				g.insert(id[i][j]+t,t==k?t0:id[i][j]+t+1,w);
			}
		}
	}
	printf("%lld\n",g.dinic(s0,t0,1e18));
	return 0;
}

