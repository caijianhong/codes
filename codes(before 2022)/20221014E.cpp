#include <map>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
const int P=998244353;
typedef pair<int,int> node;
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
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
int n,a[100010],ans;
graph<100010,100010> g;
node o(node a,node b){return node((a.first+b.first)%P,(a.second+b.second)%P);}
LL calc(map<int,node> &a,map<int,node> &b){
	LL res=0; 
//	printf("a:");for(pair<int,node> x: a) printf("(%d,{%d,%d}),",x.first,x.second.first,x.second.second);puts("");
//	printf("b:");for(pair<int,node> x: b) printf("(%d,{%d,%d}),",x.first,x.second.first,x.second.second);puts("");
	for(pair<int,node> x: a){
		for(pair<int,node> y: b){
			res=(res+1ll*gcd(x.first,y.first)*(1ll*x.second.second*y.second.first%P+1ll*x.second.first*y.second.second%P+1ll*x.second.second*y.second.second%P)%P)%P;
		}
	}
	return res;
}
void merge(map<int,node> &a,map<int,node> &b){for(pair<int,node> y: b) a[y.first]=o(a[y.first],y.second);}
map<int,node> add(map<int,node> a,int w){
	map<int,node> r;
	for(pair<int,node> x: a){
		r[gcd(x.first,w)]=o(r[gcd(x.first,w)],node(x.second.first+x.second.second,x.second.second));
	}
	return r;
}
map<int,node> dfs(int u,int fa=0){
	map<int,node> tot={{a[u],{0,1}}};
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa) continue;
		map<int,node> res=add(dfs(v,u),a[u]);
//		printf(">u=%d,v=%d\n",u,v);
		ans=(ans+calc(tot,res))%P;
//		printf("%lld\n",ans);
		merge(tot,res);
	}
	return tot;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g.link(u,v);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
/*
考虑枚举 lca=k 怎么做
考虑爆搜所有路径，以 gcd 分类，路径长度加一起
考虑有多少个 gcd，由于 gcd 包含 a[k]，所以 gcd|a[k]
10^5 内大概只有 90 个因数
于是对于每棵子树，90^2 的统计答案，90 的合并上去
点分治做到 O(90^2 n\log n) = 6e9
很不好，考虑直接 dfs，去掉 \log
O(90^2 n)=8e7 的复杂度完成 

相信常数的力量吧！！！ 菊花！！！ 
*/ 
