#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node;
template<int N,class T=int,int logN=20> struct STable{
	int tot,lg[N+10];T f[logN+1][N+10];
	STable():tot(0){lg[0]=-1;for(int i=1;i<=N;i++) lg[i]=lg[i>>1]+1;}
	void insert(T x){f[0][++tot]=x;for(int j=0,i=tot-1;i>=1;i-=1<<++j) f[j+1][i]=min(f[j][i],f[j][i+(1<<j)]);}
	T query(int l,int r){int k=lg[r-l+1];return min(f[k][l],f[k][r-(1<<k)+1]);}
};
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
template<int N,int M,class T=int> struct exgraph:public graph<N,M,T>,public STable<N*2,node>{
	int fa[N+10],dep[N+10],pos[N+10],cnt,siz[N+10],smx[N+10],sum[N+10]; bool cut[N+10];
	exgraph():cnt(0){dep[0]=0;}
	void dfs(int u,int fa=0){
		sum[u]=0,pos[u]=++cnt,this->insert(node(dep[u]=dep[fa]+1,u));
		for(int i=this->head[u];i;i=this->nxt[i]){
			int v=this->e[i].v; if(v==fa||cut[v]) continue;
			dfs(v,u),sum[v]=sum[u]+this->e[i].w,++cnt,this->insert(node(dep[u],u));
		}
	}
	node getroot(int u,int fa=0,int T=1e9){
		node res=node(T,0); siz[u]=1,smx[u]=0;
		for(int i=this->head[u];i;i=this->nxt[i]){
			int v=this->e[i].v; if(v==fa||cut[v]) continue;
			res=min(res,getroot(v,u,T)),siz[u]+=siz[v],smx[u]=max(smx[u],siz[v]);
		}
		return min(res,node(smx[u]=max(T-siz[u],smx[u]),u));
	}
	int lca(int u,int v){return pos[u]>pos[v]&&(swap(u,v),0),this->query(pos[u],pos[v]).second;}
};
int n,m;
exgraph<100010,100010> g;
graph<100010,100010> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d",&u,&v,&w),g.link(u,v,w);
	return 0;
}

