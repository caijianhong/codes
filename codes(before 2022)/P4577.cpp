#include <set>
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
template<int N,class T=int> struct treecut{
	graph<N,N,T> &g;
	int fa[N+10],siz[N+10],son[N+10],dep[N+10],
		dfn[N+10],rnk[N+10],top[N+10],cnt;
	treecut(graph<N,N,T> &g):g(g),cnt(0){memset(son,siz[0]=dep[0]=0,sizeof son);} 
	void dfs(int u,int f=0){
		dep[u]=dep[fa[u]=f]+1,siz[u]=1;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(v==fa[u]) continue;
			dfs(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v]) son[u]=v;
		} 
	}
	void cut(int u,int topf){
		top[rnk[dfn[u]=++cnt]=u]=topf;
		if(son[u]) cut(son[u],topf);
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(v==fa[u]||v==son[u]) continue;
			cut(v,v);
		} 
	}
};
template<int N,class T=int,class S=multiset<T>> struct ds{
	S a[N+10];int tot,tsh[N+10],cnt;
	ds():tot(0){}
	int newnode(){int k=cnt?tsh[cnt--]:++tot;return a[k].clear(),k;}
	void destroy(int &p){tsh[++cnt]=p,p=0;}
	void merge(int &x,int &y){
		if(a[x].size()<a[y].size()) swap(x,y);
		while(!a[y].empty()){
			a[x].insert(*a[y].begin());
			a[y].erase(a[y].begin()); 
		}
		destroy(y);
	}
	void insert(int x,int k){
		print(x);
		if(!a[x].empty()&&-k<*--a[x].end()) a[x].erase(a[x].lower_bound(-k));
		a[x].insert(-k);
		print(x);
	}
	void print(int x){
//		printf("[%llu]",a[x].size());
//		for(typename S::iterator it=a[x].begin();it!=a[x].end();++it) printf("%d ",-*it);
//		puts("}");
	}
};
int n,tot,id[200010],a[200010];
graph<200010,200010> g;
treecut<200010> e(g);
ds<200010,int,set<int>> s; 
void dfs(int u,int fa=0){
//	puts("hello!");
	id[u]=s.newnode();
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa) continue;
		dfs(v,u);
		s.merge(id[u],id[v]);
	}
	s.insert(id[u],a[u]);
//	printf("u=%d,s={",u),s.print(id[u]);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	e.dfs(1),dfs(1);
	printf("%llu\n",s.a[id[1]].size());
	return 0;
}
/*
1 1 2 4
1 2 3 3
1 
*/
