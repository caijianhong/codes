#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cap first
#define cst second
typedef long long LL;
typedef pair<LL,LL> node;
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
int n,m,s0,t0,q[100010],pre[100010];
LL dep[100010];
graph<100010,100010,LL> g;
bool bfs(int s,int t){
	int L=1,R=0;
	memset(dep,-1,sizeof dep);
	dep[q[++R]=s]=1e18;
	while(L<=R){
		int u=q[L++];
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(!g[i].w||~dep[v]) continue;
			dep[v]=min(dep[u],g[i].w),pre[v]=i;
			q[++R]=v; 
		}
	}
	return dep[t]>0;
} 
LL update(int t){
	LL flow=dep[t];
	for(int i=pre[t];i;i=pre[g[i].u]){
		g[i].w-=flow;
		g[i^1].w+=flow;
	}
	return flow;
}
LL ekarp(int s,int t){
	LL flow=0;
	while(bfs(s,t)) flow+=update(t);
	return flow;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	g.add(0,0);
	scanf("%d%d%d%d",&n,&m,&s0,&t0);
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),g.insert(u,v,w);
	printf("%lld\n",ekarp(s0,t0));
	return 0;
}

