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
	suffixam():tot(1),last(1){len[1]=0,fail[1]=0,siz[1]=0,memset(ch[1],0,sizeof ch[1]);}
	void expand(int r){
		int u=++tot,p=last;memset(ch[u],0,sizeof ch[u]),last=u;
		len[u]=len[p]+1,siz[u]=1;
		while(p&&!ch[p][r]) ch[p][r]=u,p=fail[p];
		if(!p) return void(fail[u]=1);
		int q=ch[p][r];
		if(len[q]==len[p]+1) return void(fail[u]=q);
		int cq=++tot;memcpy(ch[cq],ch[q],sizeof ch[cq]);
		fail[cq]=fail[q],len[cq]=len[p]+1,siz[cq]=0;
		fail[u]=fail[q]=cq;
		while(p&&ch[p][r]==q) ch[p][r]=cq,p=fail[p];
	}
	int q[N*2+10],inn[N*2+10];
	LL toposort(){
		int L=1,R=0;LL ans=0;
		for(int i=1;i<=tot;i++) inn[fail[i]]++;
		for(int i=1;i<=tot;i++) if(!inn[i]) q[++R]=i;
		while(L<=R){
			int u=q[L++];
			siz[fail[u]]+=siz[u];
			if(siz[u]>1) ans=max(ans,1ll*siz[u]*len[u]);
			if(--inn[fail[u]]==0) q[++R]=fail[u];
		}
		return ans;
	}
};
int n;
char s[1000010];
suffixam<1000010> t;
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=n;i>=1;i--) t.expand(s[i]-'a');
	printf("%lld\n",t.toposort());
	return 0;
}
