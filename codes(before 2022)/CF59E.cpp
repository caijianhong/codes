#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,int> node;
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
int n,m,k,dep[40010],fail[40010];
set<node> que[3010];
graph<3010,20010> g;
graph<40010,10000010/2> t;
void rebuild(){
	for(int i=1;i<=g.cnt;i++){
		for(int j=1;j<=g.cnt;j++){
			if(g[i].v!=g[j].u) continue;
			int u=g[i].u,v=g[i].v,w=g[j].v;
			if(que[v].find(node(u,w))!=que[v].end()) continue;
			t.add(i,j);
//			printf("(%d,%d)[%d]=>(%d,%d)[%d]\n",u,v,i,v,w,j);
		}
	}
}
void bfs(int s){
	memset(dep,-1,sizeof dep);
	queue<int> q;
	for(dep[s]=0,q.push(s);!q.empty();){
		int u=q.front();q.pop();
		for(int i=t.head[u];i;i=t.nxt[i]){
			int v=t[i].v;
			if(dep[v]==-1){
				dep[v]=dep[u]+1;
				fail[v]=u;
				q.push(v);
			}
		}
	}
}
void print(int i){
	if(i!=1) print(fail[i]); 
	if(g[i].u) printf("%d ",g[i].u);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%d",&n,&m,&k);
	g.add(0,1);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),g.link(u,v);
	g.add(n,n+1);
	for(int i=1,u,v,w;i<=k;i++) scanf("%d%d%d",&u,&v,&w),que[v].insert(node(u,w));
	rebuild(),bfs(1);
	if(~dep[g.cnt]) printf("%d\n",dep[g.cnt]-1),print(g.cnt);
	else puts("-1");
	return 0;
}

