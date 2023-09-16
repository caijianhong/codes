#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef long long LL;
template<int N,int M,class T=LL> struct matrix{
	T a[N][M];
	matrix(T flag=1e18){memset(a,0x3f,sizeof a);for(int i=0;i<N&&i<M;i++) a[i][i]=flag;}
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
LL a[200010],b[200010];
int n,m,sshwy,fa[19][200010],dep[200010];
graph<200010,200010> g;
matrix<3,3> dw[19][200010],up[19][200010];
matrix<1,3> f0;
matrix<3,3> gettrans(int i,LL del=1e18){
	matrix<3,3> c=1e18; 
	switch(sshwy){
		case 1: c[0][0]=a[i]; break;
		case 2: c[0][1]=0,c[0][0]=c[1][0]=a[i]; break;
		case 3: c[0][0]=c[1][0]=c[2][0]=a[i],c[0][1]=c[1][2]=0,c[1][1]=min(b[i],del); break;
	}
	return c;
}
void dfs(int u,int f=0){
	dep[u]=dep[fa[0][u]=f]+1,b[u]=1e18;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==f) continue;
		dfs(v,u),b[u]=min(b[u],a[v]);
	}
	dw[0][u]=up[0][u]=gettrans(u);
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v); int d=dep[u]-dep[v];
	for(int j=18;j>=0;j--) if(d>>j&1) u=fa[j][u];
	if(u==v) return u;
	for(int j=18;j>=0;j--) if(fa[j][u]!=fa[j][v]) u=fa[j][u],v=fa[j][v];
	return fa[0][u];
}
matrix<3,3> query_dw(int u,int k){
	matrix<3,3> res=0;
	for(int j=18;j>=0;j--) if(k>>j&1) res=dw[j][u]*res,u=fa[j][u];
	return res;
}
matrix<3,3> query_up(int u,int k){
	matrix<3,3> res=0;
	for(int j=18;j>=0;j--) if(k>>j&1) res=res*up[j][u],u=fa[j][u];
	return res;
}
LL query(int u,int v){
	int k=lca(u,v);
	matrix<1,3> res=f0*query_up(u,dep[u]-dep[k])*gettrans(k,a[fa[0][k]])*query_dw(v,dep[v]-dep[k]);
	return min({res[0][0]-a[v],res[0][1],res[0][2]})+a[v];
}
int main(){
	scanf("%d%d%d",&n,&m,&sshwy);
	f0[0][sshwy-1]=0,a[0]=1e18;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	dfs(1);
	for(int j=1;j<=18;j++){
		for(int i=1;i<=n;i++) fa[j][i]=fa[j-1][fa[j-1][i]];
		for(int i=1;i<=n;i++) dw[j][i]=dw[j-1][fa[j-1][i]]*dw[j-1][i];
		for(int i=1;i<=n;i++) up[j][i]=up[j-1][i]*up[j-1][fa[j-1][i]];
	}
	for(int u,v;m--;) scanf("%d%d",&u,&v),printf("%lld\n",query(u,v));
	return 0;
}

