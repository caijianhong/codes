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
    edge operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
int n,c[100010];
LL f[100010];
graph<100010,100010,int> g; 
void dfs(int u,int fa=0){
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa) continue;
		dfs(v,u);
		c[u]+=c[v];
		f[u]+=f[v]+1ll*c[v]*g[i].w;
	}
}
void solve(int u,int fa=0){
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa) continue;
		f[v]=f[u]+1ll*(c[1]-c[v])*g[i].w-1ll*c[v]*g[i].w;
		solve(v,u);
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d",&u,&v,&w),g.link(u,v,w);
	dfs(1),solve(1),printf("%lld\n",*min_element(f+1,f+n+1)); 
	return 0;
}

