#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <random> 
#include <cstring> 
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge&operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
int n,m,cnt[60],pri[60],tmp[60];
graph<60,610,int> g;
vector<int> now,bes;
int f(vector<int> pos){
	memcpy(tmp,pri,sizeof tmp);
	int ans=0;
	for(int u: pos){
		ans+=tmp[u];
		for(int i=g.head[u];i;i=g.nxt[i]) tmp[g[i].v]=min(tmp[g[i].v],g[i].w);
	}
	return ans;
}
mt19937 rnd(time(0)^2152938^21349812347ll);
const double eps=1e-7,t0=134234,dt=0.999;
void simulate(){
	auto shuff=[&](vector<int>f){
		int l,r;
		do l=rnd()%f.size(),r=rnd()%f.size(); while(l==r);
		swap(f[l],f[r]);
		return f;
	}; 
	double beg=clock();
	while((clock()-beg)/CLOCKS_PER_SEC<=0.95){
		double t=t0;
		while((t*=dt)>eps){
			vector<int> nxt=shuff(now);
			int df=f(nxt)-f(now);
			if(f(nxt)<f(bes)) bes=nxt;
			if(dt<0&&exp(-df/t)*0xffffff>rnd()%0xffffff) now=nxt;
		}
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	double w;
	for(int i=1;i<=n;i++) scanf("%lf%d",&w,&cnt[i]),pri[i]=w*10*cnt[i];
	scanf("%d",&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d%lf",&u,&v,&w);
		g.add(u,v,w*10*cnt[v]);
	}
	for(int i=1;i<=n;i++) if(cnt[i]) now.push_back(i);
	bes=now,simulate();
	printf("%.2lf\n",f(bes)/10.);
	return 0;
}

