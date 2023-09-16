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
    edge& operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<int N,int M,class T=int> struct maxflow:public graph<N,M,T>{
	int q[N+10],cur[N+10],dep[N+10];
	bool vis[N+10];
	maxflow(){this->add(0,0);}
    int insert(int u,int v,T w){return this->add(u,v,w),this->add(v,u,0),this->cnt-1;}
	bool bfs(int s,int t){
	    int L=1,R=0;
	    memset(dep,0,sizeof dep);
	    memcpy(cur,this->head,sizeof cur);
	    dep[q[++R]=s]=1;
	    while(L<=R){
	        int u=q[L++]; 
	        for(int i=this->head[u];i;i=this->nxt[i]){
	            int v=this->e[i].v;
	            if(!this->e[i].w||dep[v]) continue;
	            dep[q[++R]=v]=dep[u]+1;
	        }
	    }
	    return dep[t];
	}
	LL dfs(int u,LL flow,int t){
	    if(u==t||!flow) return flow;
	    LL rest=flow;
	    for(int &i=cur[u];i;i=this->nxt[i]){
	        int v=this->e[i].v;
	        if(!this->e[i].w||dep[v]!=dep[u]+1) continue;
	        if(LL ans=dfs(v,min(rest,this->e[i].w),t)){
	            this->e[i].w-=ans,this->e[i^1].w+=ans;
	            rest-=ans;
	            if(!rest) break;
	        }
	    }
	    if(flow==rest) dep[u]=-1;
	    return flow-rest;
	}
	LL dinic(int s,int t){
	    LL flow=0;
	    while(bfs(s,t)) flow+=dfs(s,1e18,t);
	    return flow;
	}
};
int n,m,k,s0,t0,inn[110],out[110],pos[2][110],tot;
maxflow<110*4,30010,LL> g;
int main(){
//  #ifdef LOCAL
//      freopen("input.in","r",stdin);
//  #endif
    scanf("%d%d%d",&n,&m,&k);
    s0=++tot,t0=++tot;
    for(int i=1;i<=n;i++) inn[i]=++tot,out[i]=++tot,g.insert(inn[i],out[i],1);
    for(int i=1;i<=m;i++) g.insert(s0,pos[0][i]=++tot,1);
    for(int i=1;i<=k;i++) g.insert(pos[1][i]=++tot,t0,1);
    for(int i=1,c1,c2,x;i<=n;i++){
    	scanf("%d%d",&c1,&c2);
    	for(int j=1;j<=c1;j++) scanf("%d",&x),g.insert(pos[0][x],inn[i],1);
    	for(int j=1;j<=c2;j++) scanf("%d",&x),g.insert(out[i],pos[1][x],1);	
	}
	printf("%lld\n",g.dinic(s0,t0));
    return 0;
}
