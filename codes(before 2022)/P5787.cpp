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
    graph(){memset(head,cnt=0,sizeof head);}
    edge operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<int N> struct dsu{
	int fa[N+10],siz[N+10],cnt,tot,und[N+10];
	dsu(int n=N):cnt(n),tot(0){for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int find(int x){return fa[x]==x?x:find(fa[x]);}
	void merge(int x,int y){
		if(x=find(x),y=find(y),x!=y){
			if(siz[x]<siz[y]) swap(x,y);
			assert(fa[y]==y);
			fa[y]=x,siz[x]+=siz[y],cnt--,und[++tot]=y;
		}
	}
	void revoke(int t=0){for(int y=und[tot];tot>t;y=und[--tot]) siz[fa[y]]-=siz[y],fa[y]=y,cnt++;}
}; 
int n,m,k;
graph<0,0>::edge que[200010];
graph<100010*4,200010*19> g;
dsu<200010> s;
void modify(int k,int L,int R,int p,int l,int r){
	if(L<=l&&r<=R) return g.add(p,k);
	int mid=(l+r)>>1;
	if(L<=mid) modify(k,L,R,p<<1,l,mid);
	if(mid+1<=R) modify(k,L,R,p<<1|1,mid+1,r);
}
bool crx[100010];
void solve(int hwy,int p,int l,int r){
	int tim=s.tot;
	if(hwy) for(int i=g.head[p];i;i=g.nxt[i]){
		graph<0,0>::edge &q=que[g[i].v];
		hwy&=s.find(q.u)!=s.find(q.v);
//		printf("[%d,%d]=>(%d,%d)\n",l,r,q.u,q.v);
		s.merge(q.u,q.v+n),s.merge(q.u+n,q.v);
	}
	if(l==r){
		crx[l]=hwy;
//		printf("crx[%d]=%d\n",l,crx[l]);
	}else{
		int mid=(l+r)>>1;
		solve(hwy,p<<1,l,mid),solve(hwy,p<<1|1,mid+1,r);
	}
//	printf("revoke %d opt\n",s.tot-tim);
	s.revoke(tim);
	assert(tim==s.tot);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d%d%d",&que[i].u,&que[i].v,&l,&r);
		if(l+1<=r) modify(i,l+1,r,1,1,k);
	}
	solve(1,1,1,k);
	for(int i=1;i<=k;i++) puts(crx[i]?"Yes":"No");
	return 0;
}

