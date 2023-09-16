#include <set> 
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
template<int N,int M,class T=int> struct graph{
	int head[N+10],nxt[M*2+10],cnt,tot;
	struct edge{
		int u,v; T w;
		edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
	} e[M*2+10];
	edge&operator[](int i){return e[i];}
	graph(){memset(head,cnt=0,sizeof head);}
	void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
	void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
graph<200010,200010> g,t;
int cys[200010],fa[200010],cup[200010];
int getdist_c(int k,int u,int v){int d=abs(cys[u]-cys[v]);return min(d,cys[k]-d);}
void build_c(int u,int v,int w){
	cys[v]=w;
	for(int i=v;i!=u;i=fa[i]) cys[fa[i]]=cys[i]+cup[i];
	cys[++t.tot]=cys[u],cys[u]=0;
	for(int i=v;i!=u;i=fa[i]) t.link(t.tot,i,getdist_c(t.tot,i,u));
	t.link(t.tot,u,0);
}
int dfn[100010],low[100010],cnt;
void tarjan(int u,int f=0){
	dfn[u]=low[u]=++cnt,fa[u]=f;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(!dfn[v]) cup[v]=g[i].w,tarjan(v,u),low[u]=min(low[u],low[v]);
		else if(v!=f) low[u]=min(low[u],dfn[v]);
	}
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(low[v]>dfn[u]) t.link(u,v,g[i].w);
		if(fa[v]!=u&&dfn[v]>dfn[u]) build_c(u,v,g[i].w);
	}
}
int n,f[200010],ans,h[400010],q[400010];
void dp(int cnt){//单调队列！ 
	int L=1,R=0;
	auto calc=[&](int x){return h[x]-x;};
	for(int i=1;i<=cnt;i++){
		while(L<=R&&i-q[L]>cnt>>2) L++;
		if(L<=R) ans=max(ans,calc(q[L])+h[i]+i);
		while(L<=R&&calc(q[R])<=calc(i)) R--;
		q[++R]=i;
	}
}
void dfs(int u,int _=0){
	debug("dfs(%d,%d)\n",u,_);
	fa[u]=_,f[u]=-1e9;
	for(int i=t.head[u];i;i=t.nxt[i]) if(t[i].v!=_) dfs(t[i].v,u);
	int d1=0,d2=0;
	auto insert=[&](int x){if(x>=d1) swap(d1,x); if(x>=d2) swap(x,d2);};
	for(int i=t.head[u];i;i=t.nxt[i]) if(t[i].v!=_) insert(f[t[i].v]+t[i].w);
	f[u]=d1;
	if(u<=n){
		ans=max(ans,d1+d2);
	}else{
		int cnt=0;
		for(int i=t.head[u];i;i=t.nxt[i]) h[++cnt]=f[t[i].v];//这里需要整个环的信息 
		h[1]=-1e9;
		memcpy(h+cnt+1,h+1,sizeof(int)*cnt);
		dp(cnt<<=1);
	}
	debug("f[%d]=%d\n",u,f[u]); 
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%*d",&n);
	for(int k,u,v;~scanf("%d%d",&k,&u);) for(k--;k--;scanf("%d",&v),g.link(u,v,1),u=v);
	t.tot=n,tarjan(1);
	for(int i=1;i<=t.cnt;i+=2) debug("(%d,%d)=%d\n",t[i].u,t[i].v,t[i].w);
	dfs(1);
	printf("%d\n",max(ans,*max_element(f+1,f+t.cnt+1)));
	return 0;
}
/*
11 1
12 1 2 3 4 5 6 7 8 9 10 11 3
*/
