#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define x first
#define y second
typedef long long LL;
typedef pair<int,int> node;
const int dx[]={0,-1,0,0,1},dy[]={0,0,-1,1,0};
template<int N> struct dsu{
	int fa[N+10],siz[N+10],cnt;
	dsu(int n=N):cnt(n){for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){if(x=find(x),y=find(y),x!=y) cnt--,siz[x]<siz[y]?fa[x]=y,siz[y]+=siz[x]:fa[y]=x,siz[x]+=siz[y];}
};
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    void init(){memset(head,cnt=0,sizeof head);}
    edge& operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<int N,int M,class T=int> struct maxflow:public graph<N,M,T>{
	graph<N,M,T> &g;
	int q[N+10],cur[N+10],dep[N+10];
	bool vis[N+10];
	maxflow():g(*this){g.add(0,0);}
    int insert(int u,int v,T w){return g.add(u,v,w),g.add(v,u,0),g.cnt-1;}
	bool bfs(int s,int t){
	    int L=1,R=0;
	    memset(dep,0,sizeof dep);
	    memcpy(cur,g.head,sizeof cur);
	    dep[q[++R]=s]=1;
	    while(L<=R){
	        int u=q[L++]; 
	        for(int i=g.head[u];i;i=g.nxt[i]){
	            int v=g.e[i].v;
	            if(!g[i].w||dep[v]) continue;
	            dep[q[++R]=v]=dep[u]+1;
	        }
	    }
	    return dep[t];
	}
	T dfs(int u,T flow,int t){
	    if(u==t||!flow) return flow;
	    T rest=flow;
	    for(int &i=cur[u];i;i=this->nxt[i]){
	        int v=g[i].v;
	        if(!g[i].w||dep[v]!=dep[u]+1) continue;
	        if(T ans=dfs(v,min(rest,g[i].w),t)){
	            g[i].w-=ans,g[i^1].w+=ans;
	            rest-=ans;
	            if(!rest) break;
	        }
	    }
	    if(flow==rest) dep[u]=-1;
	    return flow-rest;
	}
	T dinic(int s,int t){
	    T flow=0;
	    while(bfs(s,t)) flow+=dfs(s,1e9,t);
	    return flow;
	}
};
int n,m,s0,t0,id[14][14],cnt,tot;
char a[14][14];
maxflow<40010,200020,int> g;
void sshwy(int t){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='X') continue;
			if(a[i][j]=='D'){g.insert(id[i][j]+t,t0,1);continue;}
			for(int k=0;k<=4;k++){
				int tx=i+dx[k],ty=j+dy[k];
				if(1<=tx&&tx<=n&&1<=ty&&ty<=m&&a[tx][ty]!='X') g.insert(id[i][j]+t-1,id[tx][ty]+t,1e9);
			}
		}
	}
}
int mian(){
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	s0=++tot,t0=++tot;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='X') continue;
			id[i][j]=++tot,tot+=150;
			if(a[i][j]=='.') g.insert(s0,id[i][j],1),cnt++;
		}
	}
	if(!cnt) return puts("0");
	for(int t=1,res=0;t<=150;t++){
		sshwy(t);
//		printf("cnt=%d,res=%d\n",cnt,res); 
		res+=g.dinic(s0,t0);
		if(res==cnt) return printf("%d\n",t),0;
	}
	puts("impossible");
	return 0;
}
void reset(){
	g.init(),g.add(0,0);
	tot=cnt=0;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d%d",&n,&m);reset(),mian());
	return 0;
}

