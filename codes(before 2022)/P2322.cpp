#include <queue>
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
		int u,v; T w;
		edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
	} e[M*2+10];
	edge& operator[](int i){return e[i];}
	graph(){memset(head,cnt=0,sizeof head);}
	void add(int u,int v,int w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
	void link(int u,int v,int w=0){add(u,v,w),add(v,u,w);}
}; 
template<int N,int M,int D='A'> struct ACAM{
	int ch[N+10][M],tot,fail[N+10];
	ACAM():tot(-1){newnode();}
	int newnode(){int p=++tot;return memset(ch[p],0,sizeof ch[p]),fail[p]=0,p;}
	int insert(char*s){
		int len=strlen(s+1),u=0;
		for(int i=1;i<=len;i++){
			int &v=ch[u][s[i]-D];
			v?u=v:u=v=newnode();
		}
		return u;
	}
	void build(){
		queue<int> q;
		for(int i=0;i<M;i++) if(ch[0][i]) q.push(ch[0][i]);
		for(;!q.empty();){
			int u=q.front(); q.pop();
			for(int i=0;i<M;i++){
				if(ch[u][i]) fail[ch[u][i]]=ch[fail[u]][i],q.push(ch[u][i]);
				else ch[u][i]=ch[fail[u]][i];
			}
		}
	}
}; 
int n,sta[1010],inn[1010];
char buf[1010];
ACAM<1010,26,'A'> t;
graph<1010,1010> g;
void dfs(int u,int f=0){
	sta[u]|=sta[f];
	for(int i=g.head[u];i;i=g.nxt[i]) dfs(g[i].v,u);
}
bool vis[600][1<<12];
int sum[600<<12],pre[600<<12],chr[600<<12],now[600<<12];
void print(int u){
	if(!pre[u]) return ;
	print(pre[u]);
	putchar(chr[u]+'A'); 
}
void bfs(int s){
	int L=1,R=0;
	sum[++R]=0,now[R]=pre[R]=0;
	for(;L<=R;){
		int u=now[L],s=sum[L];
		if(s==(1<<n)-1) return print(L);
		for(int i=0;i<26;i++){
			int v=t.ch[u][i];
			if(v&&!vis[v][s|sta[v]]){
				++R;
				sum[R]=s|sta[v];
				chr[R]=i;
				now[R]=v;
				pre[R]=L;
				vis[v][s|sta[v]]=1;
			}
		}
		L++;
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%s",buf+1),sta[t.insert(buf)]|=1<<i;
	t.build();
	for(int i=1;i<=t.tot;i++) g.add(t.fail[i],i);
	dfs(0);
	bfs(0);
	return 0;
}

