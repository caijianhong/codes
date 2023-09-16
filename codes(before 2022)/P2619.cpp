#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node;
template<int N> struct dsu{
    int fa[N+10],siz[N+10],cnt;
    dsu(int n=N):cnt(n){for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
    int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
    void merge(int x,int y){if(x=find(x),y=find(y),x!=y) siz[x]<siz[y]&&(swap(x,y),0),cnt--,fa[y]=x,siz[x]+=siz[y];}
};
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=T()):u(u),v(v),w(w){}
        bool operator<(edge b){return w.first==b.w.first?w.second>b.w.second:w.first<b.w.first;}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge& operator[](int i){return e[i];}
    void add(int u,int v,T w=T()){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=T()){add(u,v,w),add(v,u,w);}
};
int n,m,k;
graph<50010,100010,node> g;
node check(int d){
	dsu<50010> s(n);
	for(int i=1;i<=g.cnt;i++) g[i].w.first+=g[i].w.second*d;
	sort(g.e+1,g.e+g.cnt+1);
	node res=node(0,0);
	for(int i=1;i<=g.cnt;i++){
		int u=g[i].u,v=g[i].v;
		if(s.find(u)!=s.find(v)){
			s.merge(u,v);
			res.first+=g[i].w.first;
			res.second+=g[i].w.second;
		}
	}
	for(int i=1;i<=g.cnt;i++) g[i].w.first-=g[i].w.second*d;
	return res;
}
int binary(int L,int R){
	int ans=-1e9;
	while(L<=R){
		int mid=(L+R)>>1;
		node res=check(mid);
		if(res.second>=k) ans=res.first-k*mid,L=mid+1;
		else R=mid-1;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v,w,z;i<=m;i++) scanf("%d%d%d%d",&u,&v,&w,&z),g.add(u+1,v+1,node(w,!z));
	printf("%d\n",binary(-114,514));
	return 0;
}

