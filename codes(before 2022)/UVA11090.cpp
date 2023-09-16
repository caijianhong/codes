#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const double eps=1e-8;
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
int n,m;
double dis[60];
bool vis[60];
int app[60];
graph<60,10010,double> g;
bool spfa(){
	queue<int> q;
	memset(dis,0,sizeof dis);
	memset(app,0,sizeof app);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++) q.push(i),vis[i]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(dis[v]>dis[u]+g[i].w){
				dis[v]=dis[u]+g[i].w;
				if(!vis[v]){
					if(++app[v]>=n) return 1;
					vis[v]=1,q.push(v);
				}
			}
		}
	}
	return 0;
}
bool check(double k){
	for(int i=1;i<=g.cnt;i++) g[i].w-=k;
	bool flag=spfa();
	for(int i=1;i<=g.cnt;i++) g[i].w+=k;
	return flag;
}
double binary(double L,double R){
	double ans=R;
	while(R-L>eps){
		double mid=(L+R)/2.;
		if(check(mid)) ans=mid,R=mid-eps;
		else L=mid+eps;
	}
	return ans;
}
int mian(){
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),g.add(u,v,w);
	double res=binary(0,1e9);
	if(fabs(res-1e9)<eps) puts("No cycle found.");
	else printf("%.2lf\n",res);
	return 0;
}
void reset(){
	static int uva=0;
	printf("Case #%d: ",++uva);
	memset(g.head,g.cnt=0,sizeof g.head);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d%d",&n,&m);reset(),mian()); 
	return 0;
}

