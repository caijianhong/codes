#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct buffer{
	int tot;char s[N*7+10],*o;
	buffer():tot(0),o(s){}
	~buffer(){*o=0,puts(s);}
	void print(int x){o+=sprintf(o,"%d ",x),++tot;}
};
buffer<400010> buf;
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
int n,m,k0,k1;
graph<2000010,3000010> g;
int yes(int i){return i;}
int no(int i){return i+n+m+1;}
int hwy(int i){return i+n+1;}
int crx(int i){return i+n+1+n+m+1;}
int dfn[2000010],low[2000010],stk[2000010],co[2000010],cnt,top,col;
void tarjan(int u){
	dfn[stk[++top]=u]=low[u]=++cnt;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(!co[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){co[u]=++col;do co[stk[top]]=col; while(stk[top--]!=u);}
}
bool twosat(){
	memset(dfn,cnt=top=col=0,sizeof dfn);
	for(int i=1;i<=crx(m);i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n+m+1;i++) if(co[yes(i)]==co[no(i)]) return 0;
	return 1;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%d%d",&k0,&n,&m,&k1);
	for(int i=1,u,v;i<=k0;i++){
		scanf("%d%d",&u,&v);
		g.add(no(u),yes(v)),g.add(no(v),yes(u));
	}
	for(int u=1,l,r;u<=n;u++){
		scanf("%d%d",&l,&r);
		g.add(yes(u),hwy(r)),g.add(crx(r),no(u));
		g.add(yes(u),crx(l-1)),g.add(hwy(l-1),no(u));
	}
	for(int i=1,u,v;i<=k1;i++){
		scanf("%d%d",&u,&v);
		g.add(yes(u),no(v)),g.add(yes(v),no(u));
	}
	for(int i=1;i<=m;i++) g.add(hwy(i-1),hwy(i));
	for(int i=1;i<=m;i++) g.add(crx(i),crx(i-1));
	g.add(hwy(0),crx(0));
	if(!twosat()) return puts("-1"),0;
	for(int i=1;i<=n;i++) if(co[yes(i)]<co[no(i)]) buf.print(i);
	for(int i=1;i<=m;i++) if(co[hwy(i)]<co[crx(i)]) return printf("%d %d\n",buf.tot,i),0;
	return 0;
}

