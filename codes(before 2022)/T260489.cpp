#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node; 
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
int n,m,root,a[200010];
node ans[200010];
graph<200010,200010> g;
void dfs(int u,int fa=0){
	if(u!=root) ans[u]=node(abs(a[u]-a[root]),u);
	else ans[u]=node(1e9,u);
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa) continue;
		dfs(v,u);
		ans[u]=min(ans[u],ans[v]);
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),x?(g.link(i,x),0):(root=i);
	dfs(root);
	for(int i=1,op,x,y;i<=m;i++){
		if(scanf("%d",&op),op==1){
			scanf("%d",&x);
			printf("%d\n",ans[x].second);
		}else{
			scanf("%d%d",&x,&y);
			a[x]=y,dfs(root); 
		}
	}
	return 0;
}

