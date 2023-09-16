#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
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
	edge& operator[](int i){return e[i];}
	graph(){memset(head,cnt=0,sizeof head);}
	void add(int u,int v,int w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
	void link(int u,int v,int w=0){add(u,v,w),add(v,u,w);}
};
int n,w[1000010];
graph<1000010,1000010> g; 
bool vis[1000010],sit[1000010<<1];//vis 判点，sit 判边 
int find_cycle(int u,int p=0){
	vis[u]=1;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if((i^p)==1) continue;
		if(vis[v]) return i;
		if(int res=find_cycle(v,i)) return res;
	}
	return 0;
}
LL dp(int e){//强制不选 s 
//	int s=g[e].u,t=g[e].v;
	function<pair<LL,LL>(int,int)> dfs=[&](int u,int f)->pair<LL,LL>{
		pair<LL,LL> ans={0,w[u]}; vis[u]=1;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v; if(v==f||(i^e)<=1) continue;
			pair<LL,LL> res=dfs(v,u);
			ans.first+=max(res.first,res.second);
			ans.second+=res.first;
		}
		return ans;
	};
	return dfs(g[e].u,0).first;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n),g.add(0,0);
	for(int u=1,v;u<=n;u++) scanf("%d%d",&w[u],&v),g.link(u,v);
	LL ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int e=find_cycle(i);
			ans+=max(dp(e),dp(e^1));
		}
	}
	printf("%lld\n",ans);
	return 0;
}

