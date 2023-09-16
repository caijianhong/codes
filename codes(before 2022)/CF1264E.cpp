#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> cont;
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=T()):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge& operator[](int i){return e[i];}
    void add(int u,int v,T w=T()){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=T()){add(u,v,w),add(v,u,w);}
};
#define cap first
#define cst second
template<int N,int M,class T=int,class F=int> struct mcmf:public graph<N,M,pair<T,F>>{
	typedef pair<T,F> node;
	graph<N,M,node> &g=*this;
	int pre[N+10]; F dis[N+10]; bool vis[N+10];
	mcmf(){g.add(0,0,node(1,0));}
    int insert(int u,int v,LL w,LL z){return g.add(u,v,node(w,z)),g.add(v,u,node(0,-z)),g.cnt-1;}
	bool spfa(int s,int t){
	    memset(vis,0,sizeof vis);
	    memset(dis,0x3f,sizeof dis);
	    queue<int> q;
	    pre[s]=1,dis[s]=0;
	    for(q.push(s);!q.empty();){
	        int u=q.front();q.pop();
	        vis[u]=0;
	        for(int i=g.head[u];i;i=g.nxt[i]){
	            int v=g[i].v;
	            if(g[i].w.cap&&dis[v]>dis[u]+g[i].w.cst){
	                dis[v]=dis[u]+g[i].w.cst;
	                pre[v]=i;
	                if(!vis[v]) q.push(v),vis[v]=1;
	            }
	        }
	    }
	    return dis[t]<dis[0];
	}
	node edkarp(int s,int t){
	    node flow=node(0,0);
	    while(spfa(s,t)){
	        T res=1e9;
	        for(int u=t;u!=s;u=g[pre[u]].u) res=min(res,g[pre[u]].w.cap);
	        for(int u=t;u!=s;u=g[pre[u]].u) g[pre[u]].w.cap-=res,g[pre[u]^1].w.cap+=res;
	        flow.cap+=res,flow.cst+=res*dis[t];
	    }
	    return flow;
	}
};
int n,m,s0,t0,tot,dop[60],id[60][60];
cont a[3010];
mcmf<30010,30010,int,int> g;
int f(int x){return x*(x-1)/2;} 
int main(){
//  #ifdef LOCAL
//      freopen("input.in","r",stdin);
//  #endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&a[i].cap,&a[i].cst);
    sort(a+1,a+m+1);
    s0=++tot,t0=++tot;
    for(int i=1;i<=n;i++){
    	dop[i]=++tot;
    	for(int j=1;j<=n;j++){
    		int p=++tot;
    		g.insert(dop[i],p,1,f(j)-f(j-1));
    		g.insert(p,t0,1,0);
		} 
	}
    for(int i=1;i<=n;i++){
    	for(int j=i+1;j<=n;j++){
    		int p=++tot;//cont=>win&lose 
    		g.insert(s0,p,1,0);
//    		if(*lower_bound(a+1,a+m+1,cont(i,j))==cont(i,j)) ig.insert(p,dop[i],1,0),g.insert(p,dop[j],0,0);
//    		else if(*lower_bound(a+1,a+m+1,cont(j,i))==cont(j,i)) g.insert(p,dop[i],0,0),g.insert(p,dop[j],1,0);
//    		else g.insert(p,dop[i],1,0),g.insert(p,dop[j],1,0);
    		id[i][j]=*lower_bound(a+1,a+m+1,cont(j,i))==cont(j,i)?1:g.insert(p,dop[i],1,0);
    		id[j][i]=*lower_bound(a+1,a+m+1,cont(i,j))==cont(i,j)?1:g.insert(p,dop[j],1,0);
		}
	}
//	printf("%d\n",n*(n-1)*(n-2)-g.edkarp(s0,t0).cst);
	g.edkarp(s0,t0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) putchar('0');
			else putchar('0'+!g[id[i][j]].w.cap);
		}
		puts("");
	}
    return 0;
}
