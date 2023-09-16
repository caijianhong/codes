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
    edge operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<int N,int M=26> struct suffixam{
	int tot,ch[N*2+10][M],fail[N*2+10],len[N*2+10],siz[N*2+10],last;
	suffixam():tot(1),last(1){memset(ch,0,sizeof ch),memset(siz,0,sizeof siz),len[1]=fail[1]=0;}
	void expand(int r){
		int u=++tot,p=last;last=u;
		len[u]=len[p]+1,siz[u]=1;
		while(p&&!ch[p][r]) ch[p][r]=u,p=fail[p];
		if(!p) return void(fail[u]=1);
		int q=ch[p][r];
		if(len[q]==len[p]+1) return void(fail[u]=q);
		int cq=++tot;memcpy(ch[cq],ch[q],sizeof ch[cq]);
		len[cq]=len[p]+1,fail[cq]=fail[q];
		fail[u]=fail[q]=cq;
		while(p&&ch[p][r]==q) ch[p][r]=cq,p=fail[p];
	}
};
int n;
char s[1000010];
suffixam<1000010> t;
graph<2000010,2000010> g;
LL dfs(int u,int fa=0){
	LL ans=0;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa) continue;
		ans=max(ans,dfs(v,u)),t.siz[u]+=t.siz[v];
	}
	if(t.siz[u]>1) ans=max(ans,1ll*t.siz[u]*t.len[u]);
	return ans;
}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=n;i>=1;i--) t.expand(s[i]-'a');
	for(int i=2;i<=t.tot;i++) g.add(t.fail[i],i);
	printf("%lld\n",dfs(1));
	return 0;
}
