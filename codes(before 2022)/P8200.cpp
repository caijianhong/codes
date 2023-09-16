#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef unsigned long long LL;
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge&operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
int n,m;
LL s[500010];
graph<500010,500010,LL> g;
void dfs(int u,int f=0){for(int i=g.head[u];i;i=g.nxt[i]) if(g[i].v!=f) s[g[i].v]=s[u]^g[i].w,dfs(g[i].v,u);}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	LL w;
	for(int i=1,u,v;i<n;i++) scanf("%d%d%llu",&u,&v,&w),g.link(u,v,w);
	dfs(1);
	for(int i=1;i<=n;i++) debug("s[%d]=%llu\n",i,s[i]);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d%llu",&u,&v,&w),puts(s[u]^s[v]^w?"No":"Yes");
	return 0;
}

