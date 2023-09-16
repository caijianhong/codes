
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
template<int N> struct egoi2022{
	int ch[N+10][2],tot; LL val[N+10];
	int newnode(int q=0){int p=++tot;return memcpy(ch[p],ch[q],sizeof ch[0]),val[p]=val[q],p;}
	egoi2022():tot(0){val[0]=0,memset(ch[0],0,sizeof ch[0]);}
	void build(int &p,int l,int r){
		p=newnode();
		if(l==r) return ;
		int mid=(l+r)>>1;
		build(ch[p][0],l,mid),build(ch[p][1],mid+1,r);
	}
	int modify(int x,LL k,int p,int l,int r){
		int q=newnode(p);
		if(l==r) return val[q]+=k,q;
		int mid=(l+r)>>1;
		if(x<=mid) ch[q][0]=modify(x,k,ch[p][0],l,mid);
		else ch[q][1]=modify(x,k,ch[p][1],mid+1,r);
		return q;
	}
	LL query(int x,int p,int l,int r){
		if(!p||l==r) return val[p];
		int mid=(l+r)>>1;
		if(x<=mid) return query(x,ch[p][0],l,mid);
		else return query(x,ch[p][1],mid+1,r);
	}
};
struct node{
//	int t,u; LL s;//规定 t=0 为空状态
	int tl,tr,ul,ur; LL s;
};
node O={0,0,0,0,0};
LL calc(int lt,int rt,int u);
template<int N> struct segtree{
	node tag[N<<2];
	void build(int a[],int p,int l,int r){
		if(l==r) return tag[p]={1,1,a[l],a[l],0ll},void();
		int mid=(l+r)>>1; tag[p]=O;
		build(a,p<<1,l,mid),build(a,p<<1|1,mid+1,r);
	}
	void add(node k,int p){tag[p]+=k;}
	void pushdown(int p){add(tag[p],p<<1),add(tag[p],p<<1|1),tag[p]=O;}
	void modify(int L,int R,node k,int p,int l,int r){
		if(L<=l&&r<=R) return add(k,p);
		int mid=(l+r)>>1; pushdown(p);
		if(L<=mid) modify(L,R,k,p<<1,l,mid);
		if(mid<R) modify(L,R,k,p<<1|1,mid+1,r);
	}
	LL query(int tim,int x,int p,int l,int r){
		if(l==r) return tag[p].s+calc(tag[p].tr,tim,tag[p].ur);
		int mid=(l+r)>>1; pushdown(p);
		if(x<=mid) return query(tim,x,p<<1,l,mid);
		else return query(tim,x,p<<1|1,mid+1,r);
	}
};
int n,m,Q,a[1<<18],root[1<<18],fa[19][1<<18],dep[1<<18];
vector<int> g[1<<18];
segtree<1<<18> t;
egoi2022<1<<23> T;
void dfs(int u,int f=0){fa[0][u]=f,dep[u]=dep[f]+1; for(int v:g[u]) if(v!=f) dfs(v,u);}
int lca(int u,int v){
	int d=dep[u]-dep[v]; if(d<0) swap(u,v),d=-d;
	for(int j=18;j>=0;j--) if(d>>j&1) u=fa[j][u];
	if(u==v) return u;
	for(int j=18;j>=0;j--) if(fa[j][u]!=fa[j][v]) u=fa[j][u],v=fa[j][v];
	return fa[0][u];
}
int dist(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
LL calc(int lt,int rt,int u){return T.query(u,root[rt],1,n)-T.query(u,root[lt-1],1,n);}
bool operator==(node a,node b){
	return a.tl==b.tl&&a.tr==b.tr&&a.ul==b.ul&&a.ur==b.ur&&a.s==b.s;
}
node operator+=(node &a,node b){
	if(b==O) return a; else if(a==O) return a=b;
	return a={
		a.tl,b.tr,a.ul,b.ur,
		a.s+b.s-dist(a.ur,b.ul)+calc(a.tr,b.tl-1,a.ur)
	};
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	t.build(a,1,1,m);
	T.build(root[0],1,n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	dfs(1);
	for(int j=1;j<=18;j++) for(int i=1;i<=n;i++) fa[j][i]=fa[j-1][fa[j-1][i]];
	for(int i=2;i<=Q+1;i++){
		root[i]=root[i-1];
		char op;
		scanf(" %c",&op);
		if(op=='t'){
			int l,r,c;
			scanf("%d%d%d",&l,&r,&c);
			t.modify(l,r,{i,i,c,c,0},1,1,m);
		}else if(op=='e'){
			int c,d;
			scanf("%d%d",&c,&d);
			root[i]=T.modify(c,d,root[i],1,n);
		}else{
			int x;
			scanf("%d",&x);
			printf("%lld\n",t.query(i,x,1,1,m));
		}
	}
	return 0;
}
