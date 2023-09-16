#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long LL;
int _[100000010],*__=_;int* alloc(int ___){return __+=___,__-___;}
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
    void reverse(){
    	::reverse(e+1,e+cnt+1);
    	int m=cnt;memset(head,cnt=0,sizeof head);
    	for(int i=1;i<=m;i++) add(e[i].u,e[i].v,e[i].w);
	}
};
int n,k,*q,a[40010],val[40010];
int dfn[2][40010],rnk[2][40010],siz[40010],cnt,inn[40010];
graph<40010,40010/2> g;
struct node{//f[k]表示摘k个苹果获得的幸福值 
	int *f;
	node():f(NULL){}
	int& operator[](int i){return f[i];}
	void calc(node pre,node emp,int v,int c){
		f=alloc(k+1),f[0]=0;
		int L=1,R=0;q[++R]=0;
		for(int i=1;i<=k;i++){
			while(L<=R&&q[L]<i-c) L++;
			f[i]=max(emp[i],pre[q[L]]+(i-q[L])*v);
			while(L<=R&&pre[q[R]]-q[R]*v<=pre[i]-i*v) R--;
			q[++R]=i;
		}
	}
	friend int operator+(node a,node b){
		int res=0;
		for(int i=0;i<=k;i++) res=max(res,a[i]+b[k-i]);
		return res;
	}
};
node f[2][40010];
int dfs(int u,int r){
	siz[u]=1;
	for(int i=g.head[u];i;i=g.nxt[i]) siz[u]+=dfs(g[i].v,r);
	rnk[r][dfn[r][u]=++cnt]=u;
	f[r][u].calc(
		f[r][rnk[r][cnt-1]],
		f[r][rnk[r][cnt-siz[u]]],
		val[u],a[u]
	);
	return siz[u];
}
int solve(int u,int sum){
	int res=0;sum+=val[u];
	for(int i=g.head[u];i;i=g.nxt[i]) res=max(res,solve(g[i].v,sum));
	if(!inn[u]) res=max(res,f[0][rnk[0][dfn[0][u]-siz[u]]]+f[1][rnk[1][dfn[1][u]-1]]+sum);
	return res;
}
int mian(){
	for(int u=1,v;u<=n;u++){
		scanf("%d%d%d",&v,&a[u],&val[u]);
		if(v) inn[v]++,g.add(v,u);
		if(a[u]>1) inn[u+n]=1e9,a[u+n]=a[u]-1,a[u]=1,val[u+n]=val[u],g.add(u,u+n);
	}
	cnt=0,dfs(1,0),g.reverse(),cnt=0,dfs(1,1);
	printf("%d\n",solve(1,0));
	return 0;
}
void reset(){
	__=_,q=alloc(k+2);//+2 !!!
	memset(g.head,g.cnt=0,sizeof g.head);
	memset(f[0][0].f=alloc(k+1),0,sizeof(int)*(k+1));
	memset(f[1][0].f=alloc(k+1),0,sizeof(int)*(k+1));
	memset(inn,0,sizeof inn);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d%d",&n,&k);reset(),mian()); 
	return 0;
}
/*
1
5 1
0 2 1
1 3 1
1 2 3
2 2 10
3 2 4
*/

