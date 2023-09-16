#include <queue>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,int> node;
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
};
int n,m,l,s0,t0,per[100010],cnt;
graph<100010,100010,LL> g;
LL dis[100010];
bool vis[100010];
LL dijkstra(int s,int t){
	priority_queue<node,vector<node>,greater<node>> q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	for(q.push(node(dis[s]=0,s));!q.empty();){
		int u=q.top().second;q.pop();
		if(vis[u]) continue; else vis[u]=1;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(dis[v]>dis[u]+g[i].w){
				q.push(node(dis[v]=dis[u]+g[i].w,v));
			}
		}
	}
	return dis[t];
}
LL calc(int i,LL k){return k/cnt+(i<=k%cnt);}
bool check(LL k){
	for(int i=1;i<=cnt;i++) g[per[i]].w=g[per[i]^1].w=calc(i,k);
	return dijkstra(s0,t0)<=l;
}
LL binary(LL L,LL R){
	LL ans=L;
	while(L<=R){
		LL mid=(L+R)>>1;
		if(check(mid)) ans=mid,L=mid+1;
		else R=mid-1;
	}
	return ans;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	g.add(0,0);
	scanf("%d%d%d%d%d",&n,&m,&l,&s0,&t0),s0++,t0++;
	for(int i=1,u,v;i<=m;i++){LL w;
		scanf("%d%d%lld",&u,&v,&w),u++,v++;
		if(!w) per[++cnt]=i*2,w=2e18;
		g.link(u,v,w);
	}
	if(dijkstra(s0,t0)<l) return puts("NO"),0;
	LL res=binary(cnt,1e18);
	if(!check(res)) return puts("NO"),0;
	else puts("YES");
	for(int i=1;i<=m;i++) printf("%d %d %lld\n",g[i*2].u-1,g[i*2].v-1,g[i*2].w);
	return 0;
}

