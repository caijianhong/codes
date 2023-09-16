#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const double eps=1e-9;
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
int n,deg[10010];
double a[10010],b[10010],c[10010],k[10010],t[10010];
graph<10010,10010> g;
int dfs(int u,int fa){
	if(deg[u]==1&&fa) return a[u]=k[u],b[u]=c[u]=t[u],1;
	double sa=0,sb=0,sc=0;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa) continue;
		if(!dfs(v,u)) return 0;
		sa+=a[v],sb+=b[v],sc+=c[v];
	}
	double del=t[u]/deg[u],tmp=1-del*sb;
	if(fabs(tmp)<eps) return 0;
	a[u]=(k[u]+del*sa)/tmp;
	b[u]=del/tmp;
	c[u]=(t[u]+del*sc)/tmp;
	return 1;
}
int mian(){
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v),deg[u]++,deg[v]++;
	for(int u=1;u<=n;u++) scanf("%lf%lf",&k[u],&t[u]),k[u]/=1e2,t[u]/=1e2,t[u]=1-t[u]-k[u];
	if(dfs(1,0)&&fabs(1-a[1])>eps) printf("%.6lf\n",c[1]/(1-a[1]));
	else puts("impossible"); 
	return 0;
}
void reset(){
	static int ccf=0;
	printf("Case %d: ",++ccf);
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	memset(k,0,sizeof k);
	memset(t,0,sizeof t);
	memset(deg,0,sizeof deg);
	memset(g.head,g.cnt=0,sizeof g.head); 
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d",&n);reset(),mian());
	return 0;
}

