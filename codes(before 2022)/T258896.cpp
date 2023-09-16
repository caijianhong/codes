#include <cmath>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=500;
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge operator[](int i){return e[i];}
    void add(int u,int v,T w=0){/*printf("%d=>%d\n",u,v);*/e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
int L,R,m,b[510],c[510],tot;
graph<510,300010> g;
int siz[510],dep[510];
int dfn[510],low[510],stk[510],co[510],cnt,top,col; 
void build(){
	for(int i=1;i<=N;i++) b[i]=i*i;
	for(int i=1;i<=N;i++){
		int lb=lower_bound(b+1,b+N+1,i+L)-b,
			ub=upper_bound(b+1,b+N+1,i+R)-b-1;
		for(int j=lb;j<=ub;j++){
			assert(i+L<=j*j&&j*j<=i+R);
			g.add(i,j);
			if(i==j) c[++tot]=i;
		}
	}
}
void tarjan(int u){
	dfn[u]=low[u]=++cnt,stk[++top]=u;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(!co[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		co[u]=++col;
		do co[stk[top]]=col; while(stk[top--]!=u);
	}
}
int dfs(int u){
	if(~dep[u]) return dep[u];
	dep[u]=siz[u]==1?1:1e9;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		dep[u]=max(dep[u],dfs(v)+1);
	}
	return dep[u];
}
void rebuild(){
	for(int i=1;i<=N;i++) if(!dfn[i]) tarjan(i);
	int m=g.cnt;memset(g.head,g.cnt=0,sizeof g.head);
	for(int i=1;i<=N;i++) siz[co[i]]++; 
	for(int i=1;i<=tot;i++) siz[co[c[i]]]++;
	for(int i=1;i<=m;i++){
		if(co[g[i].u]!=co[g[i].v]) g.add(co[g[i].u],co[g[i].v]);
	}
	memset(dep,-1,sizeof dep);
	for(int i=1;i<=col;i++) if(dep[i]==-1) dfs(i);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%d",&L,&R,&m);
	build(),rebuild();
	//for(int i=1;i<=N;i++) printf("dep[%d]=%d\n",i,dep[co[i]]);
	for(int i=1,k;i<=m;i++){
		scanf("%d",&k);
		int lb=lower_bound(b+1,b+N+1,k+L)-b,
			ub=upper_bound(b+1,b+N+1,k+R)-b-1;
		int ans=-1;
		for(int j=lb;j<=ub;j++){
			ans=max(ans,dep[co[j]]);
		}
		printf("%d\n",ans>=1e9?-1:ans+1);
	}
	return 0;
}
//sqrt(2e5)<450
/*
初次操作后，值域锁定在500左右，无法更大 
提前建图，tarjan缩点，反向拓扑 
询问根号 
*/
/*
2,6,12,20,30,42,54 
*/
