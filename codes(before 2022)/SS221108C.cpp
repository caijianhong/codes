#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int P=998244353;
void red(LL&x){x=(x%P+P)%P;}
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
struct func{
	LL k,b;
	func(LL k=0,LL b=0):k(k),b(b){}
	LL operator()(LL x){return k*x+b;}
};
struct dot{
	LL x,y;
	dot(LL x,LL y):x(x),y(y){}
	friend double slope(dot a,dot b){
		return 1.0*(a.y-b.y)/(a.x-b.x);
	}
};
LL intersect(line a,line b){
	return -(a.b-b.b)/(a.k-b.k);
}
int n,m,cnt,top;
LL f[2010][2010],ans;
func line[10010];
dot pts[10010],stk[10010];
void dp(int dep){
	for(int i=1;i<=g.cnt;i++){
		int u=g[i].u,v=g[i].v;
		f[dep][v]=max(f[dep][v],f[dep-1][u]+g[i].w);
	}
}
int mian(){
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),g.link(u,v,w);
	for(int i=1;i<=min(2000,q);i++) dp(i),red(ans+=*max_element(f[i]+1,f[i]+n+1));
	if(q<=2000) return printf("%lld\n",ans),0;
	for(int i=1;i<=m*2;i++) line[i]=func(g[i].w,max(dis[2000][g[i].u],dis[2000][g[i].v])-2000*g[i].w);
	sort(line+1,line+m*2+1,[](line a,line b){
		return a.k!=b.k?a.k<b.k:a.b>b.b;
	});
	for(int i=2;i<=m*2;i++){
		if(line[i].k!=line[i-1].k){
			LL x=intersect(line[i],line[i-1]);
			for(int k=-1;k<=1;k++){
				if(x+k>2000) pts[++cnt]=dot(x+k,max(line[i](x+k),line[i-1](x+k)));
			}
		}
	}
	sort(pts+1,pts+cnt+1,[](dot a,dot b){
		return a.x<b.x;
	});
	for(int i=1;i<=cnt;i++) append(pts[i]);
	return 0;
}
void reset(){
	memset(f,~0x3f,sizeof f),f[0][1]=0;
	memset(g.head,g.cnt=0,sizeof g.head);
}
int main(){
	for(scanf("%*d");~scanf("%d%d",&n,&m);reset(),mian());
}
