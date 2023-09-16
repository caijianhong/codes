#include <cstdio>
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
template<int N,class T=int> struct counter{
	T c[N+10],u[N+10][2],tot;
	void add(T k,int p){if(p<=N) u[++tot][0]=k,u[tot][1]=p,c[p]+=k;}
	T operator[](int i){return c[i];}
	void rollback(){for(;tot>0;tot--) c[u[tot][1]]-=u[tot][0];}
};
int n,m,siz[10010],smx[10010];
bool cut[10010];
graph<10010,10010,int> g; 
counter<10000010> c; 
int dfs(int u,int fa){//÷ÿ‘ÿ£∫getsize 
	siz[u]=1,smx[u]=0;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa||cut[v]) continue;
		siz[u]+=dfs(v,u);
		smx[u]=max(smx[u],siz[v]);
	}
	return siz[u];
}
node getcore(int u,int fa,int T){
	node res=node(max(smx[u],T-siz[u]),u);
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa) continue;
		res=max(res,getcore(v,u,T));
	} 
	return res;
}
LL dfs(int u,int fa,int k,int w){//÷ÿ‘ÿ£∫query 
	if(k<w) return 0;
	LL res=c[k-w];
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa||cut[v]) continue;
		res+=dfs(v,u,k,w+g[i].w);
	}
	return res;
}
void dfs(int u,int fa,int w){//÷ÿ‘ÿ£∫modify 
	if(w>1e7) return ;
	c.add(1,w);
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa||cut[v]) continue;
		dfs(v,u,w+g[i].w);
	}
}
LL calc(int u,int k){
	LL res=0;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(cut[v]) continue;
		res+=dfs(v,u,k,g[i].w);
		dfs(v,u,g[i].w);
	}
	return res;
}
LL solve(int u,int k){
	cut[u=getcore(u,0,dfs(u,0)).second]=1;
	LL res=calc(u,k);
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(cut[v]) continue;
		res+=solve(v,k);
	}
	return res;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d",&u,&v,&w),g.link(u,v,w);
	for(int i=1,k;i<=m;i++) scanf("%d",&k),puts(solve(1,k)?"AYE":"NAY");
	return 0;
}

