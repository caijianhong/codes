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
template<int N,int M,class T=int> struct treecut: public graph<N,M,T>{
	graph<N,M,T> &g=*this;
	int fa[N+10],siz[N+10],dep[N+10],son[N+10],
		top[N+10],dfn[N+10],rnk[N+10],cnt;
	treecut():cnt(0){memset(son,siz[0]=0,sizeof son);}
	void dfs(int u,int f=0){
		dep[u]=dep[fa[u]=f]+1,siz[u]=1;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v; if(v==fa[u]) continue;
			dfs(v,u),siz[u]+=siz[v];
			if(siz[son[u]]<siz[v]) son[u]=v;
		}
	}
	void cut(int u,int topf){
		top[rnk[dfn[u]=++cnt]=u]=topf;
		if(son[u]) cut(son[u],topf);
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v; if(v==fa[u]||v==son[u]) continue;
			cut(v,v);
		}
	}
};
int cnt[200010],_[200010],*ans=_;
bool vaild(int x,int k){return 0<k&&k<cnt[x];}
template<int N> struct ds{
	int t[N+10],u[N+10][3],tot,sum;
	ds(){memset(t,0,sizeof t);}
	int operator[](int i){return t[i];}
	void add(int x,int k){u[++tot][0]=x,u[tot][1]=k,u[tot][2]=sum,sum-=vaild(x,t[x]),t[x]+=k,sum+=vaild(x,t[x]);}//(x>0)-(x==cnt)=0<x<cnt
	void revoke(int tim){for(int y=u[tot][0];tot>tim;y=u[--tot][0]) t[y]-=u[tot][1],sum=u[tot][2];}
};
int n,a[200010];
bool die[200010];
treecut<200010,200010> g;
ds<200010> buc;
void calc(int u){for(int i=g.dfn[u];i<g.dfn[u]+g.siz[u];i++) buc.add(a[g.rnk[i]],1);}
void solve(int u,int keep=0){
	for(int i=g.head[u];i;i=g.nxt[i]) if(g[i].v!=g.son[u]&&g[i].v!=g.fa[u]) solve(g[i].v,0);
	int t=buc.tot;
	if(g.son[u]) solve(g.son[u],1);
	for(int i=g.head[u];i;i=g.nxt[i]) if(g[i].v!=g.son[u]&&g[i].v!=g.fa[u]) calc(g[i].v);
	buc.add(a[u],1);
	if(buc.sum-vaild(a[u],buc[a[u]])) die[u]=1;
	if(buc.sum-vaild(a[g.fa[u]],buc[a[g.fa[u]]])) die[g.fa[u]]=1;
	if(!keep) buc.revoke(t);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%*d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	g.dfs(1),g.cut(1,1),solve(1);
	for(int i=1;i<=n;i++) if(!die[i]) *ans++=a[i];
	sort(_,ans),ans=unique(_,ans);
	printf("%lld\n",ans-_);for(int *pos=_;pos!=ans;pos++) printf("%d ",*pos);
	return 0;
}

