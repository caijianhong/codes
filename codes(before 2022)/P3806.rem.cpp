#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node;
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
int n,m,siz[10010],smx[10010],q[110];
bool cut[10010];
int id[10010],dis[10010],fom[10010],tot;
graph<10010,10010,int> g; 
bool cmp(int x,int y){return dis[x]<dis[y];}
void getdist(int u,int fa,int w,int from){
	dis[id[++tot]=u]=w,fom[u]=from;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa||cut[v]) continue;
		getdist(v,u,w+g[i].w,from);
	}
}
LL calc(int u,int){
//	printf("calc:u=%d\n",u);
	dis[id[tot=1]=u]=0,fom[u]=u;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(cut[v]) continue;
		getdist(v,u,g[i].w,v); 
	}
	sort(id+1,id+tot+1,cmp);
	for(int i=1;i<=m;i++){
		int k=q[i];LL res=0;
		if(k<0) continue;
		for(int L=1,R=tot;L<R;){
//			printf("L=%d,R=%d,res=%d\n",L,R,res);
			if(dis[id[L]]+dis[id[R]]<k) L++;
			else if(dis[id[L]]+dis[id[R]]>k) R--;
			else res+=fom[id[L]]!=fom[id[R]],L++;
			if(res) break;
		}
		if(res) q[i]=-q[i];
	}
	return 19491001;
}
node getroot(int u,int fa,int T){
	node res=node(1e9,0); 
	siz[u]=1,smx[u]=0;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(v==fa||cut[v]) continue;
		res=min(res,getroot(v,u,T));
		siz[u]+=siz[v];
		smx[u]=max(smx[u],siz[v]);
	}
	smx[u]=max(smx[u],T-siz[u]);
	return min(res,node(smx[u],u));
} 
LL solve(int u,int k){
//	printf("u=%d,k=%d\n",u,k);
	cut[u]=1;
	LL res=calc(u,k);
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		if(cut[v]) continue;
		res+=solve(getroot(v,0,siz[v]).second,k); //T=siz[v] is correct ! 
		//https://liu-cheng-ao.blog.uoj.ac/blog/2969
	}
	return res;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d",&u,&v,&w),g.link(u,v,w);
	for(int i=1;i<=m;i++) scanf("%d",&q[i]);
	solve(getroot(1,0,n).second,19260817);
	for(int i=1;i<=m;i++) puts(q[i]<0?"AYE":"NAY");
//	for(int i=1,k;i<=m;i++) memset(cut,0,sizeof cut),scanf("%d",&k),puts(solve(getroot(1,0,n),k)?"AYE":"NAY");
	return 0;
}
/*
100 50
100 27 752
100 54 1941
99 39 1650
100 12 709
100 65 933
97 95 9594
100 19 1256
100 82 2603
100 8 507
100 60 5919
100 68 4321
100 1 97
100 26 1274
100 39 1903
100 53 340
100 28 2552
100 67 1949
100 41 291
100 25 2464
100 80 5219
100 42 3661
100 48 90
100 57 260
100 49 1970
100 18 588
91 87 3091
100 22 203
100 2 16
100 66 2889
100 71 2674
100 61 1231
100 62 5862
100 5 380
93 53 8145
100 85 7967
100 70 3318
100 24 231
100 74 205
100 32 2914
100 21 723
100 84 3657
100 89 2500
100 10 799
100 33 717
100 14 512
100 59 3516
100 63 3365
100 17 149
100 30 2049
100 44 2899
100 29 346
100 37 2159
100 20 1923
100 51 4573
100 55 4623
92 25 3272
100 75 1876
100 56 5367
100 6 430
100 88 7689
100 36 635
100 83 2866
100 46 4076
100 72 2105
100 40 2615
100 15 227
98 61 5283
100 73 4584
100 77 3674
94 58 3126
100 3 69
100 4 195
100 45 204
100 52 4389
100 9 346
100 35 3015
100 43 668
100 16 1454
100 79 1142
100 11 912
100 76 7115
100 64 2994
100 31 1031
100 58 1738
100 47 3783
100 78 4847
100 13 1129
100 50 1829
100 34 260
90 20 7448
100 86 404
95 46 7296
100 23 1292
100 38 630
100 81 1974
96 85 4742
100 87 2529
100 7 598
100 69 6213
1116777
3103
3308517
3810813
4076
346
1133103
204
3342908
1687129
7713
4296
4008534
204
2899
3873
5067
2562
1327982
3651
1869939
1751585
2092712
2931862
752
340
2662730
356
2881
430
7960
5288
3272
2387387
3657
715383
2500
4447
3661
2735624
653248
205
204
611930
1345
1355673
5423
5043
3674
2615
*/

