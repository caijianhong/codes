#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,int M,class T=LL> struct matrix{
	T a[N][M];
	matrix(T flag=1e18){memset(a,0,sizeof a);for(int i=0;i<N&&i<M;i++) a[i][i]=flag;}
	T* operator[](int i){return a[i];}
};
template<int N,int M,int R,class T=LL> matrix<N,R,T> operator*(matrix<N,M,T> a,matrix<M,R,T> b){
	matrix<N,R,T> c=1e18;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<R;k++){
				c[i][k]=min(c[i][k],a[i][j]+b[j][k]);
			}
		}
	}
	return c;
};
template<int N,int M,class T=int> struct graph{
	int head[N+10],nxt[M*2+10],cnt;
	struct edge{
		int u,v; T w;
		edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
	} e[M*2+10];
	graph(){memset(head,cnt=0,sizeof head);}
	edge& operator[](int i){return e[i];}
	void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
	void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
int n,m,sshwy;
LL a[200010],sum[200010];
graph<200010,200010> g;
int fa[200010],siz[200010],dep[200010],son[200010],
	dfn[200010],rnk[200010],top[200010],cnt;
int minx[200010];
void dfs(int u,int f=0){
	sum[u]=sum[fa[u]=f]+a[u],dep[u]=dep[f]+1,siz[u]=1;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa[u]) continue;
		dfs(v,u),siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]) son[u]=v;
		if(a[minx[u]]>a[v]) minx[u]=v;
	}
	if(a[minx[u]]>a[f]) minx[u]=f;
}
//matrix<2,2> tot[200010];
void cut(int u,int topf){
//	if(sshwy==2){
//		tot[u][1][1]=1ll<<60;
//		tot[u][1][2]=tot[u][2][2]=a[i];
//		tot[u][2][1]
//	}
	top[rnk[dfn[u]=++cnt]=u]=topf;
	if(son[u]) cut(son[u],topf);
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa[u]||v==son[u]) continue;
		cut(v,v);
	}
}
int lca(int u,int v){
	for(;top[u]!=top[v];u=fa[top[u]]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
	}
	if(dep[u]>dep[v]) swap(u,v);
	return u;
}
int mian1(){
	dfs(1),cut(1,1);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		int k=lca(u,v);
		printf("%lld\n",sum[u]+sum[v]-sum[k]-sum[fa[k]]);
	}
	return 0;
}
int pos[200010];
LL f[200010][2];
int split(int u,int v){
	int k=lca(u,v),cnt=0;
	for(int i=u;i!=k;i=fa[i]) pos[++cnt]=i;
	pos[++cnt]=k;
	int tim=cnt;
	for(int i=v;i!=k;i=fa[i]) pos[++cnt]=i;
	reverse(pos+tim+1,pos+cnt+1);
	return cnt;
}
LL dp2(int u,int v){
	int cnt=split(u,v);
	f[0][0]=1e18,f[1][0]=a[pos[1]];
	for(int i=2;i<=cnt;i++){
		f[i][0]=min(f[i-1][0],f[i-2][0])+a[pos[i]];
	}
	return f[cnt][0];
}
LL dp3(int u,int v){
	int cnt=split(u,v);
	f[0][0]=f[0][1]=1e18,f[1][1]=a[pos[1]]+a[minx[pos[1]]],f[1][0]=a[pos[1]];
	for(int i=2;i<=cnt;i++){
		f[i][0]=f[i][1]=1e18;
		f[i][0]=min({f[i][0],f[i-1][0],f[i-1][1],f[i-2][0],f[i-2][1]})+a[pos[i]];
		f[i][1]=min({f[i-1][0],f[i-1][1],f[i-2][0]})+a[minx[pos[i]]];
		if(i>=3) f[i][0]=min(f[i][0],f[i-3][0]+a[pos[i]]);
	}
	return min(f[cnt][0],f[cnt][1]+a[v]);
}
int mian2(){
	dfs(1),cut(1,1);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		printf("%lld\n",dp2(u,v));
	}
	return 0;
}
int mian3(){
	dfs(1),cut(1,1);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		printf("%lld\n",dp3(u,v));
	}
	return 0;
}
int main(){
//	freopen("transmit.in","r",stdin);
//	freopen("transmit.out","w",stdout);
	a[0]=1e18;
	scanf("%d%d%d",&n,&m,&sshwy);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	switch(sshwy){
		case 1: mian1();break;
		case 2: mian2();break;
		case 3: mian3();break;
	}
	return 0;
}

