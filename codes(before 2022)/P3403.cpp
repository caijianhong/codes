#include <queue>
#include <cstdio>
#include <cstring>
#include <cassert>
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
    edge operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
LL h,x,y,z,ans;
LL f[100010];
bool vis[100010];
graph<100010,100010> g;
void dijkstra(int s,int d=0){
	priority_queue<node,vector<node>,greater<node>> q;
	memset(f,0x3f,sizeof f);
	memset(vis,0,sizeof vis);
	for(q.push(node(f[s]=d,s));!q.empty();){
		int u=q.top().second;q.pop();
		if(vis[u]) continue; else vis[u]=1;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(f[v]>f[u]+g[i].w){
				q.push(node(f[v]=f[u]+g[i].w,v));
			}
		}
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%lld%lld%lld%lld",&h,&x,&y,&z);
	if(x==1||y==1||z==1) return printf("%lld\n",h),0;
	for(int i=0;i<x;i++){
		g.add(i,(i+y)%x,y);
		g.add(i,(i+z)%x,z);
	}
	dijkstra(1,1);
	for(int i=0;i<x;i++){
//		printf("f[%d]=%lld,ans+=%lld\n",i,f[i],(h-f[i])/x+1);
		if(f[i]<=h) ans+=(h-f[i])/x+1;
	}
	printf("%lld\n",ans);
	return 0;
}

