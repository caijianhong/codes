#include <cmath>
#include <cstdio>
#include <vector>
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
        int v;T w;
        edge(int v=0,T w=0):v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge&operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<int N> struct ds{
	int buc[N],g[N],cnt;
	void init(int k){
		auto popcount=[&](int x)->int{return __builtin_popcount(x);};
		for(int i=0;i<N;i++) if(popcount(i)==k) g[++cnt]=i;
	}
	void insert(int x){for(int i=1;i<=cnt;i++) buc[x^g[i]]++;}
	int operator[](int x){return buc[x];}
};
int n,m,k;
LL ans[1<<17],deq[1<<17][2];
int unit,bel[1<<17];
graph<1<<17,1<<25,LL*> g;
struct ask{
	int l,r,id;
	bool operator<(ask b){return bel[l]==bel[b.l]?r<b.r:l<b.l;}
} q[1<<17];
void divide(double u){
	unit=max(1,(int)ceil(u));
	for(int i=1;i<=n;i++) bel[i]=(i-1)/unit+1;
}
void moqueue(){
	int L=1,R=0;
	sort(q+1,q+m+1);
	for(int i=1;i<=m;i++){
		//deq[0] Îª¼õ£¬deq[1] Îª¼Ó 
		auto add=[&](int x)->void{g.add(L-1,x,&deq[i][0]),g.add(R,x,&deq[i][1]);};//x->[L,R]
		auto del=[&](int x)->void{g.add(L-1,x,&deq[i][1]),g.add(R,x,&deq[i][0]);};//x->[L,R]
		while(R<q[i].r) add(++R); while(q[i].l<L) add(--L);
		while(q[i].r<R) del(R--); while(L<q[i].l) del(L++);
	}
}
int main(){
	debug("sizeof g=%zu\n",sizeof g>>20);
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%d",&n,&m,&k);
	if(k>14){
		for(int i=1;i<=m;i++) puts("0");
		return 0;
	}
	divide(sqrt(n));
	for(int i=1;i<=m;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	moqueue();
	return 0;
}

