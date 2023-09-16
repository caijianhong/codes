#include <cstdio>
#include <vector>
#include <cstring>
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
const int P=1e9+7;
LL mod(LL x){return (x%P+P)%P;}
void red(LL&x){x=mod(x);}
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
int n;
graph<500010,500010> g;
vector<LL> con[500010];
int siz[500010];
LL f[500010];
void dfs(int u,int fa=0){
	siz[u]=1,f[u]=0;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa) continue;
		dfs(v,u);
		siz[u]+=siz[v];
		red(f[u]+=f[v]);
		con[u].push_back(f[v]);
	}
	red(f[u]=f[u]<<1|1);
}
void moveroot(int u,int v){
	//u Ê§È¥ v
	red(f[u]-=f[v]<<1);
	//v µÃµ½ u
	red(f[v]+=f[u]<<1);
}
void dgs(int u,int fa=0){
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa) continue;
		moveroot(u,v);
		con[v].push_back(f[u]);	
		dgs(v,u);
		moveroot(v,u);
	}
}
LL calc(vector<LL> &a){
	LL sum=accumulate(a.begin(),a.end(),0ll)%P,sum2=0;
	for(LL&x:a) red(sum2+=x*x);
//	debug("[");
//	for(LL&x:a) debug("%d,",x);
//	debug("]");
	return mod((P+1)/2*(sum*sum%P-sum2)+sum);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	dfs(1),dgs(1);
//	for(int i=1;i<=n;i++) printf("%lld\n",calc(con[i]));
	LL _=0;
	for(int i=1;i<=n;i++) _^=calc(con[i])*i;
	printf("%lld\n",_);
	return 0;
}

