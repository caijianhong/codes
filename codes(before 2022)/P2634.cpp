#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node;
LL gcd(LL x,LL y){return !y?x:gcd(y,x%y);}
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
template<int N> struct counter{
	int c[N+10],u[N+10][2],tot;
	counter():tot(0){memset(c,0,sizeof c);}
	void insert(int k,int p){u[++tot][0]=k,u[tot][1]=p,c[p]+=k;}
	int& operator[](int i){return c[i];}
	void undo(int){c[u[tot][1]]-=u[tot][0],tot--;}
	void rollback(){for(;tot>0;undo(1));}
};
int n,siz[50010],smx[50010],c[3];
bool cut[50010];
int id[50010],dis[50010],fom[50010],tot;
graph<50010,50010,int> g;
bool cmp(int x,int y){return dis[x]<dis[y];}
void getdist(int u,int fa,int w,int from){
	c[w%3]++;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(cut[v]||v==fa) continue;
		getdist(v,u,w+g[i].w,from);
	}
} 
LL calc(int u,int del){
	c[0]=c[1]=c[2]=0,c[del%3]++;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(cut[v]) continue;
		getdist(v,u,g[i].w+del,v);
	}
	return 1ll*c[0]*c[0]+2ll*c[1]*c[2];
}
node getroot(int u,int fa,int T){
	node res=node(1e9,0); 
	siz[u]=1,smx[u]=0;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa||cut[v]) continue;
		res=min(res,getroot(v,u,T));
		siz[u]+=siz[v];
		smx[u]=max(smx[u],siz[v]);
	}
	smx[u]=max(smx[u],T-siz[u]);
	return min(res,node(smx[u],u));
} 
LL solve(int u){
	cut[u]=1;
	LL res=calc(u,0);
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(cut[v]) continue;
		res-=calc(v,g[i].w);
		res+=solve(getroot(v,0,siz[v]).second);
	}
	return res;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d",&u,&v,&w),g.link(u,v,w%3);
	LL x=solve(getroot(1,0,n).second),y=1ll*n*n,k=gcd(x,y);
	printf("%lld/%lld\n",x/k,y/k);
	return 0;
}

