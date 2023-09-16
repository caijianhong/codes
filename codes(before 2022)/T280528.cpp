#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,int M,class T=int> struct graph{
	int head[N+10],nxt[M*2+10],cnt;
	struct edge{
		int u,v;T w;
		edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
	} e[M*2+10];
	edge operator[](int i){return e[i];}
	graph(){memset(head,cnt=0,sizeof head);}
	void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
	void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
struct node{
	int len,ans;
	node(int len=1,int ans=0):len(len),ans(ans){}
	node operator+(node b){return node(len+b.len,ans+b.ans);}
	node operator~(){return node(len,len-ans);}
};
template<int N,class T=int> struct segtree{
	bool rev[N<<2];T ans[N<<2];
	segtree(){memset(rev,0,sizeof rev);}
	void add(int p){rev[p]^=1,ans[p]=~ans[p];}
	void maintain(int p){ans[p]=ans[p<<1]+ans[p<<1|1];}
	void pushdown(int p){if(rev[p]) add(p<<1),add(p<<1|1),rev[p]^=1;}
	void build(int p=1,int l=1,int r=N){
		if(l==r) return ans[p]=T(),void();
		int mid=(l+r)>>1;
		build(p<<1,l,mid),build(p<<1|1,mid+1,r);
		maintain(p);
	}
	void modify(int L,int R,int p=1,int l=1,int r=N){
		if(L>R) return ;
		if(L<=l&&r<=R) return add(p);
		pushdown(p);
		int mid=(l+r)>>1;
		if(L<=mid) modify(L,R,p<<1,l,mid);
		if(mid<R) modify(L,R,p<<1|1,mid+1,r);
		maintain(p);
	}
};
int n,n0,n1;
LL ans=0;
segtree<300010/2,node> t[2];
graph<300010,300010> g;
int fa[300010],siz[300010],son[300010],dep[300010];
void dfs(int u,int f=0){
	dep[u]=dep[fa[u]=f]+1,siz[u]=1;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa[u]) continue;
		dfs(v,u),siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
	}
}
void add(int p){
	int pos=(p+1)/2;
	if(p%2) t[1].modify(pos,n1),t[0].modify(pos,n0);//,printf("0:[%d,%d],1:[%d,%d]\n",pos,n0,pos,n1);
	else t[0].modify(pos,n0),t[1].modify(pos+1,n1);//,printf("0:[%d,%d],1:[%d,%d]\n",pos,n0,pos+1,n1);
}
void calc(int u,int no=0){
	add(u);
	for(int i=g.head[u];i;i=g.nxt[i]){
		if(g[i].v!=fa[u]&&g[i].v!=no) calc(g[i].v,no);
	}
}
LL dp(){
	int a1=t[1].ans[1].ans,a0=t[0].ans[1].ans;
//	printf("1=[%d,%d],0=[%d,%d],ans=%lld\n",a1,n1-a1,a0,n0+1-a0,1ll*a1*(n1-a1)+1ll*a0*(n0+1-a0));
	return 1ll*a1*(n1-a1)+1ll*a0*(n0+1-a0);
}
void solve(int u,int keep=0){
	for(int i=g.head[u];i;i=g.nxt[i]){
		if(g[i].v!=fa[u]&&g[i].v!=son[u]) solve(g[i].v,0);
	}
	if(son[u]) solve(son[u],1);
	calc(u,son[u]);
//	printf("u=%d:\n",u);
	ans+=dp();
	if(!keep) calc(u);
}
int main(){
	fprintf(stderr,"%llu\n",sizeof t); 
	scanf("%d",&n),n1=(n+1)/2,n0=n-n1;
	t[0].build(),t[1].build();
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	dfs(1);
	solve(1);
	printf("%lld\n",ans);
	return 0;
}
