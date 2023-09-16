#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
#define l first
#define r second
typedef long long LL;
template<int N> struct flower{
    int b[N+10],cnt;
    flower():cnt(0){}
    void operator+=(int x){b[++cnt]=x;}
    void build(){sort(b+1,b+cnt+1),cnt=unique(b+1,b+cnt+1)-b-1;}
    int operator()(int x){return lower_bound(b+1,b+cnt+1,x)-b;}
    int operator[](int i){return b[i];}
};
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
int n,c[4010],dis[4010];
pair<int,int> a[4010];
flower<4010> b;
graph<4010,100010> g;
void insert_less(int x,int y,int z){debug("s[%d]-s[%d]<=%d\n",x,y,z),g.add(b(y),b(x),z);}
void insert_greater(int x,int y,int z){debug("s[%d]-s[%d]>=%d\n",x,y,z),g.add(b(x),b(y),-z);}
bool bellman_ford(int s,int n){
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int i=1;i<=g.cnt;i++){
			int u=g[i].u,v=g[i].v;
			if(dis[v]>dis[u]+g[i].w) dis[v]=dis[u]+g[i].w,flag=1;
		}
		if(!flag) return 1;
	}
	return 0;
}
bool check(int k){
	for(int i=1;i<=n;i++) g[i].w=k;
	return bellman_ford(1,b.cnt);
}
bool xzzduang(int k){
	for(int i=1;i<=n;i++) g[i].w=k;
	for(int i=1;i<=g.cnt;i++) swap(g[i].u,g[i].v),g[i].w*=-1;
	memset(dis,~0x3f,sizeof dis);
	dis[1]=0;
	for(int i=1;i<=b.cnt;i++){
		bool flag=0;
		for(int i=1;i<=g.cnt;i++){
			int u=g[i].u,v=g[i].v;
			if(dis[v]<dis[u]+g[i].w) dis[v]=dis[u]+g[i].w,flag=1;
		}
		if(!flag) return 1;
	}
	return 0;
}
int binary(int l,int r){
	int ans=0;
	for(int mid=(l+r)>>1;l<=r;mid=(l+r)>>1){
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
void SSerxhs(){
	for(int i=1;i<=n;i++) insert_less(a[i].r,a[i].l-1,0);//modify here
	for(int i=1;i<=n;i++) insert_greater(a[i].r,a[i].l-1,1);
	for(int i=1;i<=n;i++) c[b(a[i].r)]++,c[b(a[i].l-1)]--;
	for(int i=b.cnt-1;i>=1;i--) c[i]+=c[i+1],!c[i]&&(insert_less(b[i],b[i-1],0),insert_greater(b[i],b[i-1],0),0);//,debug("c[%d]=%d\n",i,c[i]);
	for(int i=b.cnt-1;i>=1;i--) insert_less(b[i+1],b[i],b[i+1]-b[i]),insert_greater(b[i+1],b[i],0);
}
int main(){
//freopen("camera.in","r",stdin),freopen("camera.out","w",stdout);
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r),b+=a[i].l-1,b+=a[i].r;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) debug(">>> (%d,%d)\n",a[i].l,a[i].r);
	b+=0,b.build(),SSerxhs();
	int ans=binary(1,n);
//	xzzduang(ans);
	check(ans);
	debug(">>> output: "),printf("%d\n",ans);
	for(int i=1;i<=b.cnt;i++) debug("dis[%d]=%d\n",i,dis[i]);
	for(int i=b.cnt;i>=2;i--) dis[i]-=dis[i-1];
	debug("after difference...\n");
	for(int i=1;i<=b.cnt;i++) debug("dis[%d]=%d (where b[%d]=%d)\n",i,dis[i],i,b[i]);
	for(int i=2;i<=b.cnt;i++){
//		debug("dis[%d]=%d\n",i,dis[i]);
		debug("//");
		if(dis[i]){
			int p=b[i-1]+1;
			if(p>=a[n].l){
				printf("%d\n",p);
				break;
			}
			while(dis[i]--) printf("%d ",p++);
		}
	}
	return 0;
}

