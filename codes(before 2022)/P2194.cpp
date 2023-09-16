#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int P=1e9+7;
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
struct node{
	LL mn,num;
	node(LL mn=1e18,LL num=1):mn(mn),num(num){}
	node operator+(LL x){
		if(x<mn) mn=x,num=0;
		if(x==mn) num++;
		return *this;
	}
	node operator*(node b){
		return node(mn+b.mn,num*b.num%P);
	}
};
int n,m,a[100010];
node ans[100010],tot;
graph<100010,300010> g;
int dfn[100010],low[100010],stk[100010],co[100010],col,top,cnt;
void tarjan(int u){
	dfn[stk[++top]=u]=low[u]=++cnt;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(!co[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){co[u]=++col;do co[stk[top]]=col; while(stk[top--]!=u);}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),g.add(u,v);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) ans[co[i]]=ans[co[i]]+a[i];
	tot=node(0,1);
	for(int i=1;i<=col;i++) tot=tot*ans[i];
	printf("%lld %lld\n",tot.mn,tot.num);
	return 0;
}

