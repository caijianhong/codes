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
template<int N> struct mpam{
	int n,fail[N+10];
	void build(char *a){
		n=strlen(a+1),fail[0]=fail[1]=0;
		for(int i=2,j=0;i<=n;i++){
			while(j&&a[j+1]!=a[i]) j=fail[j];
			j+=a[j+1]==a[i];
			fail[i]=j;
		}
	}
};
int n,m,fa[21][1000010],dep[1000010];
char a[1000010];
mpam<1000010> t;
graph<1000010,1000010> g;
void dfs(int u,int f=0){
	dep[u]=dep[fa[0][u]=f]+1;for(int j=1;j<=20;j++) fa[j][u]=fa[j-1][fa[j-1][u]];
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==f) continue;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int j=20;j>=0;j--) if(dep[u]-(1<<j)>=dep[v]) u=fa[j][u];
	if(u==v) return u;
	for(int j=20;j>=0;j--) if(fa[j][u]!=fa[j][v]) u=fa[j][u],v=fa[j][v];
	return fa[0][u]; 
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s%d",a+1,&m),n=strlen(a+1);
	t.build(a);
	for(int i=1;i<=n;i++) g.add(t.fail[i],i);
	dfs(0);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(t.fail[u],t.fail[v]));
	} 
	return 0;
}

