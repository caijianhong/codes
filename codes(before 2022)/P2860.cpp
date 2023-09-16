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
    edge operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
int n,m,d[100010],ans;
graph<100010,100010> g;
int dfn[100010],low[100010],stk[100010],co[100010],top,cnt,col;
void tarjan(int u,int from){
	dfn[stk[++top]=u]=low[u]=++cnt;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(i==(from^1)) continue;
		if(!dfn[v]) tarjan(v,i),low[u]=min(low[u],low[v]);
		else if(!co[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){co[u]=++col;do co[stk[top]]=col; while(stk[top--]!=u);}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	g.add(0,0);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),g.link(u,v);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
	for(int i=1;i<=g.cnt;i++){
		int u=g[i].u,v=g[i].v;
		if(co[u]!=co[v]) d[co[u]]++,d[co[v]]++;
	}
	for(int i=1;i<=col;i++) ans+=d[i]==2;
	printf("%d\n",(ans+1)/2);
	return 0;
}

