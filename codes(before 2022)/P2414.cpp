#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge& operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<int N> struct fenwick{
	int t[N+10];
	fenwick(){memset(t,0,sizeof t);}
	void add(int k,int p){for(;p<=N;p+=p&-p) t[p]+=k;}
	int query(int p){int ans=0;for(;p>=1;p-=p&-p) ans+=t[p];return ans;}
};
int id[100010];
graph<100010,100010> fil;
template<int N,int M=26,int D='a'> struct acam{
	int tot,ch[N+10][M],fail[N+10],q[N+10];bool rel[N+10][M];
	acam():tot(-1){newnode();}
	int newnode(){int k=++tot;return memset(ch[k],0,sizeof ch[k]),memset(rel[k],0,sizeof rel[k]),fail[k]=0,k;}
	void sshwy(char *s){
		int len=strlen(s+1),u=0,*fa=q,tot=0;
		for(int i=1;i<=len;i++){
			if(s[i]=='P') id[++tot]=u;
			else if(s[i]=='B') u=fa[u];
			else{
				int &v=ch[u][s[i]-D];
				if(!v) fa[v=newnode()]=u,rel[u][s[i]-D]=1;
				u=v;
			}
		}
	}
	void build(){
		int L=1,R=0;
		for(int i=0;i<M;i++) if(ch[0][i]) q[++R]=ch[0][i];
		while(L<=R){
			int u=q[L++];
			for(int i=0;i<M;i++){
				if(ch[u][i]) fail[ch[u][i]]=ch[fail[u]][i],q[++R]=ch[u][i];
				else ch[u][i]=ch[fail[u]][i];
			}
		}
	}
};
int n,m,siz[100010],dfn[100010],cnt;
char s[100010];
acam<100010> ac;
fenwick<100010> t;
graph<100010,100010> que;
void dfs(int u,int fa=0){
	dfn[u]=++cnt,siz[u]=1;
	for(int i=fil.head[u];i;i=fil.nxt[i]){
		int v=fil[i].v; if(v==fa) continue;
		dfs(v,u),siz[u]+=siz[v];
	}
}
int crxis(int u){return t.query(dfn[u]+siz[u]-1)-t.query(dfn[u]-1);}
void solve(int u){
	t.add(1,dfn[u]);
	for(int i=que.head[u];i;i=que.nxt[i]) que[i].w=crxis(que[i].v);
	for(int i=0;i<26;i++) if(ac.rel[u][i]) solve(ac.ch[u][i]);
	t.add(-1,dfn[u]);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s%d",s+1,&n),ac.sshwy(s),ac.build();
	for(int i=1,x,y;i<=n;i++) scanf("%d%d",&x,&y),que.add(id[y],id[x]);
	for(int i=1;i<=ac.tot;i++) fil.add(ac.fail[i],i); 
	dfs(0),solve(0);for(int i=1;i<=n;i++) printf("%d\n",que[i].w);
	return 0;
}

