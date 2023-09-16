#include <queue>
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
};
int n,m,app[510];
LL dis[510];
bool vis[510];
graph<510,3010,LL> g;
bool spfa(int u){
	vis[u]=1;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(dis[v]>dis[u]+g[i].w){
			dis[v]=dis[u]+g[i].w;
			if(vis[v]||spfa(v)) return 1;
		}
	}
	return vis[u]=0;
}
bool check(LL k){
	for(int i=1;i<=m;i++) g[i].w-=k;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	bool flag=!spfa(dis[0]=0);
	for(int i=1;i<=m;i++) g[i].w+=k;
	return flag;
}
LL binary(LL L,LL R){
	LL ans=R;
	while(L<=R){
		LL mid=(L+R)>>1;
		if(check(mid)) ans=mid,L=mid+1;
		else R=mid-1;
	}
	return ans;
}
int mian(){
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),g.add(u,v,w);
	for(int i=1;i<=n;i++) g.add(0,i,0);
	LL res=binary(-1e9,1e9);
	if(res==1e9) puts("Infinite");
	else if(res<=0) puts("No Solution");
	else printf("%lld\n",res);
	return 0;
}
void reset(){
	memset(g.head,g.cnt=0,sizeof g.head);
}
int main(){
	#ifdef LOCAL
//	 	freopen("UVA11478.in","r",stdin);
	#endif
	for(;~scanf("%d%d",&n,&m);reset(),mian());
	return 0;
}

