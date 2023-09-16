#include <cstdio>
#include <queue>
#include <vector>
#include <cassert>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
typedef pair<int,int> pii;
const int M=1e5+37;//[0,M]
const int P=1e9+7,Ph=998244353;
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
int pw2[M+10],pw3[M+10],sum2[M+10],sum3[M+10],__calc=[&](){
	for(int i=pw2[0]=1;i<=M;i++) pw2[i]=pw2[i-1]*2%P;
	for(int i=pw3[0]=1;i<=M;i++) pw3[i]=pw3[i-1]*3%Ph;
	for(int i=sum2[0]=1;i<=M;i++) sum2[i]=(sum2[i-1]+pw2[i])%P;
	for(int i=sum3[0]=1;i<=M;i++) sum3[i]=(sum3[i-1]+pw3[i])%Ph;
	return 0;
}();
template<int N> struct segtree{
	//接口
	//int cmp(int p,int q,int l,int r) 返回以 p,q 为根的线段树的三路比较
	//--> 每个点存下 hash 值，线段树二分。
	//int plus(int x,int p) 返回 p+2^x 的结果（节点）
	//--> 先二分找到 [x,M] 中的第一个 0，记为 p；则使得 p 位为一，[x,p) 为零；特判 x==p。
	//int eval(int p,int l,int r) 返回这棵树表示的数字模 1e9+7 的结果
	//--> 有啥好说的
	int ch[N+10][2],tot,R[N+10],H[N+10],V[N+10];
	//R 1e9+7 值，H 998244353 值，V max
	int newnode(int q=0){int p=++tot;return H[p]=H[q],R[p]=R[q],V[p]=V[q],memcpy(ch[p],ch[q],sizeof ch[0]),p;}
	segtree():tot(0){R[0]=V[0]=H[0]=0;}
	void maintain(int p){
		R[p]=(R[ch[p][0]]+R[ch[p][1]])%P;
		H[p]=(H[ch[p][0]]+H[ch[p][1]])%Ph;
		V[p]=max(V[ch[p][0]],V[ch[p][1]]);
	}
	int erase(int L,int R,int p,int l,int r){//erase the segment [L,R] on p (cover with 0)
		if(L<=l&&r<=R) return 0;
		int q=newnode(p),mid=(l+r)>>1;
		if(L<=mid) ch[q][0]=erase(L,R,ch[p][0],l,mid);
		if(mid<R) ch[q][1]=erase(L,R,ch[p][1],mid+1,r);
		maintain(q);
		return q;
	}
	int insert(int x,int p,int l,int r){//promise: t[x]=0
		int q=newnode(p);
		if(l==r) return V[q]=1,R[q]=pw2[x],H[q]=pw3[x],q;
		int mid=(l+r)>>1;
		if(x<=mid) ch[q][0]=insert(x,ch[p][0],l,mid);
		else ch[q][1]=insert(x,ch[p][1],mid+1,r);
		maintain(q);
		return q;
	}
	bool check1(int p,int l,int r){
		return V[p]==1&&R[p]==sum2[r]-sum2[l-1]&&H[p]==sum3[r]-sum3[l-1];
	}
	int find0(int L,int R,int p,int l,int r){
		if(!p) return max(l,L);
		if(check1(p,l,r)) return -1;
		int mid=(l+r)>>1;
		if(L<=l&&r<=R){
			if(check1(ch[p][0],l,mid)) return find0(L,R,ch[p][1],mid+1,r);
			else return find0(L,R,ch[p][0],l,mid);
		}else{
			int tmp;
			if(L<=mid&&(tmp=find0(L,R,ch[p][0],l,mid))!=-1) return tmp;
			else if(mid<R) return find0(L,R,ch[p][1],mid+1,r);
			return -1;
		}
	}
	int plus(int x,int p){
		int r=find0(x,M,p,0,M);
		assert(r>=0);
		if(r!=x) p=erase(x,r-1,p,0,M);
		return insert(r,p,0,M);
	}
	int compare(int p,int q,int l,int r){
		if(!p||!q) return p-q;
		if(l==r) return V[p]-V[q];
		int mid=(l+r)>>1;
		if(H[ch[p][1]]==H[ch[q][1]]&&R[ch[p][1]]==R[ch[q][1]]&&V[ch[p][1]]==V[ch[q][0]])
			return compare(ch[p][0],ch[q][0],l,mid);
		else
			return compare(ch[p][1],ch[q][1],mid+1,r);
	}
};
segtree<100010*100> t;
struct cmp{
	bool operator()(pii a,pii b){return t.compare(a.first,b.first,0,M)>0;}
};
priority_queue<pii,vector<pii>,cmp> q;
graph<1<<17,1<<17,int> g;
int pre[1<<17],dis[1<<17];//存根节点编号
bool vis[1<<17];
int dijkstra(int s0,int t0){
	memset(dis,0,sizeof dis);//=0
	memset(vis,0,sizeof vis);
	memset(pre,-1,sizeof pre);
	for(q.push({dis[s0],s0}),pre[s0]=0;!q.empty();){
		int u=q.top().second; q.pop();
		if(vis[u]) continue; else vis[u]=1;
		for(int i=g.head[u];i;i=g.nxt[i]){
			int v=g[i].v;
			int tmp=t.plus(g[i].w,dis[u]);
			if(t.compare(dis[v],tmp,0,M)<0) q.push({dis[v]=tmp,v}),pre[v]=u;
		}
	}
	return pre[t0]==-1?-1:dis[t0];
}
int n,m;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,x;i<=m;i++) scanf("%d%d%d",&u,&v,&x),g.link(u,v,x);
	int S,T;
	scanf("%d%d",&S,&T);
	if(S==T) return puts("0"),puts("0"),0;
	int root=dijkstra(S,T);
	if(root==-1) return puts("-1"),0;
	printf("%lld\n",t.R[root]);
	vector<int> path;
	for(int u=T;u;u=pre[u]) path.push_back(u);
	reverse(path.begin(),path.end());
	printf("%zu\n",path.size());
	for(int x:path) printf("%d ",x);
	puts("");
	return 0;
}
/*一个神秘的数据结构支持 
1. 可持久化 
2. 单点查询 log
3. 修改：区间覆盖 0/1 log
4. 查询：hash 值 log
5. 比较两棵线段树的大小 log 
5. 一段后缀中最长的全 1 前缀（线段树二分）log
发生 m 次加一，mlogn
堆，mlog^2m 
复杂度 log^2 吊打 1e5 
*/
