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
int n,f[200010][3];
graph<200010,200010> g;
int dfs(int u,int fa=0){
	int maxd=-1e9;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa) continue;
		dfs(v,u);
		maxd=max(maxd,min(f[v][0],f[v][1])-f[v][1]);
		f[u][0]+=min(f[v][0],f[v][1]);
		f[u][1]+=min(f[v][0],min(f[v][1],f[v][2]));
		f[u][2]+=min(f[v][0],f[v][1]); 
	}
	return min(f[u][0]-=maxd,f[u][1]);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	for(int i=1;i<=n;i++) f[i][1]=1;
	printf("%d\n",dfs(1));
	return 0;
}

