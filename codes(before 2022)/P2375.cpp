#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int P=1e9+7;
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
int n,fail[1000010],num[1000010];
char a[1000010];
graph<1000010,1000010> g;
void build(){
	fail[0]=fail[1]=0,g.add(0,1);
	for(int i=2,j=0;i<=n;i++){
		while(j&&a[j+1]!=a[i]) j=fail[j];
		j+=a[j+1]==a[i];
		fail[i]=j;
		g.add(fail[i],i);
	}
}
int stk[1000010],top;
void dfs(int u,int fa=0,int j=0){
	stk[++top]=u;
	while(j<top&&stk[j+1]*2<=u) j++;
	num[u]=j;
//	printf("u=%d,fa=%d,j=%d,stk={",u,fa,j);
//	for(int i=1;i<=top;i++) printf("%d%c",stk[i],",}"[i==top]);
//	puts("");
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa) continue;
		dfs(v,u,j);
	}
	--top;
}
int mian(){
	n=strlen(a+1),build(),dfs(0,0,0);
	LL ans=1;
	for(int i=1;i<=n;i++) ans=ans*num[i]%P;//,printf("%d%c",num[i]-1," \n"[i==n]);
	printf("%lld\n",ans);
	return 0;
}
void reset(){
	memset(g.head,g.cnt=0,sizeof g.head);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%s",a+1);reset(),mian());
	return 0;
}

