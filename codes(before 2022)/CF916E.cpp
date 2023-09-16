#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
int lowbit(int x){return x&-x;}
template<int N,int M,class T=int> struct graph{
    int cnt,head[N+10],nxt[M*2+10];
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    edge operator[](int i){return e[i];}
    graph():cnt(0){memset(head,0,sizeof head);}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<int N,class T=int> struct fenwick{
	T t[N+10];
	fenwick(){memset(t,0,sizeof t);}
	void add(T k,int p){for(;p<=N;p+=p&-p) t[p]+=k;}
	T query(int p){T r=0;for(;p>=1;p-=p&-p) r+=t[p];return r;}
};
template<int N,class T=int> struct segtree{
	fenwick<N,T> s,t;
	void add(T k,int p){s.add(k,p),t.add(k*(p-1),p);}
	void add(T k,int l,int r){add(k,l),add(-k,r+1);}
	T query(int p){return s.query(p)*p-t.query(p);}
	T query(int l,int r){return t.query(r)-t.query(l-1);}
};
template<int N,int M,class T=int> struct treecut: public graph<N,M,T>{
    graph<N,M,T> &g=*this;
    int fa[N+10],dep[N+10],son[N+10],siz[N+10],
        dfn[N+10],rnk[N+10],top[N+10],cnt;
    treecut(){memset(son,cnt=siz[0]=0,sizeof son);}
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
    int lca(int u,int v){
        for(;top[u]!=top[v];u=fa[top[u]]) if(dep[top[u]]<dep[top[v]]) swap(u,v);
        if(dep[u]<dep[v]) swap(u,v); return v;
    }
};
template<int N,int M,class T=int> struct extreecut: public treecut<N,M,T>{
	
};
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	return 0;
}

