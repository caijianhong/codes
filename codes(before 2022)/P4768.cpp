#include <queue>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
int _,__,___;
typedef long long LL;
typedef pair<int,int> node;
//a path doesn't need >=n edges so we use int
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=T()):u(u),v(v),w(w){}
        bool operator<(edge b)const{return w>b.w;}//when p++,road--
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge operator[](int i){return e[i];}
    void add(int u,int v,T w=T()){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=T()){add(u,v,w),add(v,u,w);}
};
int n,m,q,a[400010],fa[20][400010];
graph<200010,400010,node> g;
graph<400010,400010> t;
int dis[400010];
bool vis[200010];
void dijkstra(int s){
	memset(dis,0x3f,sizeof dis);
	priority_queue<node,vector<node>,greater<node> > q;
	for(q.push(node(dis[s]=0,s));!q.empty();){
		int u=q.top().second;q.pop();
		if(vis[u]) continue; else vis[u]=1;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			if(dis[v]>dis[u]+g[i].w.second){
				q.push(node(dis[v]=dis[u]+g[i].w.second,v));
			}
		} 
	} 
}
template<int N> struct dsu{
    int fa[N+10],cnt;
    dsu(int n=N):cnt(n){for(int i=1;i<=n;i++) fa[i]=i;}
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    void merge(int x,int y,int f){
		if(x=find(x),y=find(y),x!=y){
			cnt--,fa[x]=fa[y]=f;
			t.link(x,f),t.link(y,f);
			dis[f]=min(dis[x],dis[y]);
		}
	}
};
dsu<400010> s;
int kruskal(){
	sort(g.e+1,g.e+g.cnt+1);
	int tot=0;
	for(int i=1;i<=g.cnt;i++){
		int u=g[i].u,v=g[i].v;
		if(s.find(u)!=s.find(v)) tot++,a[tot+n]=g[i].w.first,s.merge(u,v,tot+n);
	}
	assert(tot==n-1);
	return tot;
}
void dfs(int u,int f=0){
	fa[0][u]=f;for(int j=1;j<=19;j++) fa[j][u]=fa[j-1][fa[j-1][u]];
	for(int i=t.head[u];i;i=t.nxt[i]){
		int v=t[i].v;
		if(v==f) continue;
		dfs(v,u);
	}
}
int solve(int u,int k){
	for(int j=19;j>=0;j--) if(a[fa[j][u]]>k) u=fa[j][u];
	return dis[u];
}
int mian(){
	for(int i=1,u,v,x,y;i<=m;i++) scanf("%d%d%d%d",&u,&v,&x,&y),g.link(u,v,node(y,x));
	dijkstra(1);
	dfs(kruskal()+n);
	scanf("%d%d%d",&q,&__,&___);
	for(int i=1,u,k;i<=q;i++){
		scanf("%d%d",&u,&k);
		u=(u+_*__-1)%n+1;
		k=(k+_*__)%(___+1);
		printf("%d\n",_=solve(u,k));
	}
	return 0;
}
void reset(){
	_=0;
	memset(a,0x3f,sizeof a),a[0]=0;
	memset(vis,0,sizeof vis);
	memset(fa,0,sizeof fa);
	#ifndef LOCAL
		s=dsu<400010>();
		g=graph<200010,400010,node>();
		t=graph<400010,400010>();
	#endif
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d%d",&n,&m);reset(),mian());
	return 0;
}

