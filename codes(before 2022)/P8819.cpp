#include <cstdio>
#include <cstring>
#include <random>
#include <ctime>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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
int n,m,q,tot;
mt19937_64 rng(time(0));
ULL w[500010],sum,h[500010],inn[500010],tar[500010],ind[500010];
int main(){
//	#ifdef LOCAL
//	 	freopen("galaxy4.in","r",stdin);
//	 	freopen("galaxy4.out","w",stdout);
//	#endif
	for(int i=1;i<=1e5;i++) w[i]=rng();
	scanf("%d%d",&n,&m),tot=m;
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),sum^=w[u],h[v]^=w[u],inn[v]++;
	memcpy(tar,h,sizeof tar);
	memcpy(ind,inn,sizeof ind);
	for(int i=1;i<=n;i++) tar[0]^=w[i];
	scanf("%d",&q);
	for(int op,u,v;q--;){
		scanf("%d%d",&op,&u);
		if(op==1) scanf("%d",&v),h[v]^=w[u],sum^=w[u],inn[v]--,tot--;
		else if(op==3) scanf("%d",&v),h[v]^=w[u],sum^=w[u],inn[v]++,tot++;
		else if(op==2){
			tot-=inn[u],sum^=h[u];
			inn[u]=h[u]=0;
			tot+=inn[u],sum^=h[u];
		}else if(op==4){
			tot-=inn[u],sum^=h[u];
			inn[u]=ind[u],h[u]=tar[u];
			tot+=inn[u],sum^=h[u];
		}
		puts(tot==n&&sum==tar[0]?"YES":"NO");
	}
	return 0;
}

