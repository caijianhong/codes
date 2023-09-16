#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge& operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
    void insert(int u,int v,T w=0){add(u,v,w),add(v,u,0);}
};
int n,m,s0,t0,q[210],cur[210],dep[210]; 
graph<210,5010,LL> g;
bool bfs(int s,int t){
	int L=1,R=0;
	memset(dep,-1,sizeof(int)*(n+10));
	memcpy(cur,g.head,sizeof(int)*(n+10));
	dep[q[++R]=s]=0;
	while(L<=R){
		int u=q[L++]; 
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(!g[i].w||~dep[v]) continue;
			dep[v]=dep[u]+1;
			q[++R]=v;
		    if(v==t) return 1;
		}
	}
	return ~dep[t];
}
LL dfs(int u,LL flow){
	if(u==t0) return flow;
	LL rest=flow;
	for(int &i=cur[u];i&&rest;i=g.nxt[i]){
		int v=g[i].v;
		if(!g[i].w||dep[v]!=dep[u]+1) continue;
		if(LL ans=dfs(v,min(rest,g[i].w))){
			g[i].w-=ans,g[i^1].w+=ans;
			rest-=ans;
		}
	}
	if(flow==rest) dep[u]=-1;
	return flow-rest;
}
LL dinic(int s,int t){
	LL flow=0;
	while(bfs(s,t)) while(LL res=dfs(s,1e18)) flow+=res;
	return flow;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	g.add(0,0);
	scanf("%d%d%d%d",&n,&m,&s0,&t0);
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),g.insert(u,v,w);
	printf("%lld\n",dinic(s0,t0));
	return 0;
}

