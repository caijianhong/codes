#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
unsigned s,_,__;
unsigned ___(){return s^=s<<13,s^=s>>17,s^=s<<5;}
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
int n,q,root,fa[21][500010],siz[500010],dep[500010];
graph<500010,500010> g;
int hei[500010],son[500010],top[500010],lg[500010];
vector<int> fs[500010],ss[500010];
void dfs(int u){
	dep[u]=dep[fa[0][u]]+1,siz[u]=1;
	for(int j=1;j<=20;j++) fa[j][u]=fa[j-1][fa[j-1][u]];
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa[0][u]) continue;
		dfs(v);
		siz[u]+=siz[v];
		if(hei[v]>hei[son[u]]) son[u]=v;
	}
	hei[u]=hei[son[u]]+1;
}
void cut(int u,int topf){
//	printf("u=%d,topf=%d\n",u,topf);
	if((top[u]=topf)==u){
		int v=u,z=u;
		for(int i=1;i<=hei[u];i++){
//			printf("u=%d,fs[u][%d]=%d,ss[u][%d]=%d\n",u,i-1,v,i-1,z); 
			fs[u].push_back(v),v=fa[0][v];
			ss[u].push_back(z),z=son[z];
		}
	}
	if(son[u]) cut(son[u],topf);
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa[0][u]||v==son[u]) continue;
		cut(v,v);
	} 
}
int kthanc(int u,int k){
	if(k>=dep[u]) return 0;
	if(!k) return u;
	u=fa[lg[k]][u],k-=1<<lg[k];
	int t=top[u],d=dep[t]-dep[u]+k;
	return d>=0?fs[t][d]:ss[t][-d];
} 
int main(){
	lg[0]=-1;for(int i=1;i<=5e5;i++) lg[i]=lg[i>>1]+1;
	#ifdef LOCAL
	 	freopen("input.in","r",stdin);
	#endif
	scanf("%d%d%u",&n,&q,&s);
	for(int i=1;i<=n;i++) scanf("%d",&fa[0][i]),fa[0][i]?(g.link(i,fa[0][i]),0):root=i;
	dfs(root),cut(root,root);
	for(int i=1;i<=q;i++){
		int u=(___()^_)%n+1,k=(___()^_)%dep[u];
//		printf("u=%d,k=%d\n",u,k);
		__^=i*(_=kthanc(u,k));
//		printf("ans=%d\n",_); 
	}
	printf("%u\n",__);
	return 0;
}

