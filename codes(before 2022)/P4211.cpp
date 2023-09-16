#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
const int P=201314;
void red(LL&x){x=(x%P+P)%P;}
template<class T> struct Ans{
	int len; T sum;
	Ans(int len=1,T sum=0):len(len),sum(sum%P){}
	Ans operator+(Ans b){return Ans(len+b.len,sum+b.sum);}
	Ans operator+=(int k){return red(sum+=1ll*k*len),*this;}
};
template<int N,class T,class A> struct segtree{
	T tag[N<<2]; A ans[N<<2];
	segtree(){build();}
	void build(int p=1,int l=1,int r=N){
		if(l==r) return ; int mid=(l+r)>>1;
		build(p<<1,l,mid),build(p<<1|1,mid+1,r);
		ans[p]=ans[p<<1]+ans[p<<1|1];
	}
	void add(T k,int p){tag[p]+=k,ans[p]+=k;}
	void pushdown(int p){add(tag[p],p<<1),add(tag[p],p<<1|1),tag[p]=0;}
	void modify(int L,int R,int k,int p=1,int l=1,int r=N){
		if(L<=l&&r<=R) return add(k,p);
		int mid=(l+r)>>1; pushdown(p);
		if(L<=mid) modify(L,R,k,p<<1,l,mid);
		if(mid<R) modify(L,R,k,p<<1|1,mid+1,r);
		ans[p]=ans[p<<1]+ans[p<<1|1]; 
	}
	A query(int L,int R,int p=1,int l=1,int r=N){
		if(L<=l&&r<=R) return ans[p];
		int mid=(l+r)>>1; A res=A(0,0); pushdown(p);
		if(L<=mid) res=query(L,R,p<<1,l,mid);
		if(mid<R) res=res+query(L,R,p<<1|1,mid+1,r);
		return res;
	}
};
template<int N,int M,class T=int> struct graph{
	int head[N+10],nxt[M*2+10],cnt;
	struct edge{
		int u,v; T w;
		edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
	} e[M*2+10];
	edge& operator[](int i){return e[i];}
	graph(){memset(head,cnt=0,sizeof head);}
	void add(int u,int v,int w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
	void link(int u,int v,int w=0){add(u,v,w),add(v,u,w);}
};
template<int N,int M,class T=int> struct treecut:public graph<N,M,T>{
	graph<N,M,T>&g=*this;
	int fa[N+10],siz[N+10],son[N+10],dep[N+10],
		dfn[N+10],top[N+10],rnk[N+10],cnt;
	treecut():cnt(0){memset(son,siz[0]=0,sizeof son);}
	void dfs(int u,int f=0){
		dep[u]=dep[fa[u]=f]+1,siz[u]=1;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v; if(v==fa[u]) continue;
			dfs(v,u),siz[u]+=siz[v];
			if(siz[v]>siz[son[u]]) son[u]=v;
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
	void split(int u,int v,function<void(int,int)> op){
		for(;top[u]!=top[v];u=fa[top[u]]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			op(dfn[top[u]],dfn[u]);
		}
		if(dep[u]<dep[v]) swap(u,v);
		op(dfn[v],dfn[u]);
	}
};
struct ask{
	int pos,w,id,u;
	ask(int pos=0,int w=0,int id=0,int u=0):pos(pos),w(w),id(id),u(u){}
	bool operator<(ask b){return pos<b.pos;}
};
int n,m,cnt;
LL ret[50010];
ask q[100010];
treecut<50010,50010> g;
segtree<50010,int,Ans<LL>> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%*d",&n);
	for(int i=2,f;i<=n;i++) scanf("%d",&f),g.link(i,f+1);
	g.dfs(1),g.cut(1,1);
	for(int l,r,z;~scanf("%d%d%d",&l,&r,&z);){
		cnt++,z++,l++,r++;
		if(l>1) q[++m]=ask(l-1,-1,cnt,z);
		q[++m]=ask(r,1,cnt,z);
	}
	sort(q+1,q+m+1);
	for(int i=1,now=1;i<=n;i++){
		g.split(i,1,[&](int l,int r){
			assert(1<=l&&l<=r&&r<=n);
//			debug("modify(dfn)(%d,%d)\n",l,r);
			t.modify(l,r,1);
		});
		for(;now<=m&&q[now].pos==i;now++){
			g.split(q[now].u,1,[&](int l,int r){
				assert(1<=l&&l<=r&&r<=n);
//				debug("query(dfn)(%d,%d)\n",l,r);
				red(ret[q[now].id]+=t.query(l,r).sum*q[now].w);
			});
		}
	}
	for(int i=1;i<=cnt;i++) printf("%lld\n",ret[i]);
	return 0;
}

