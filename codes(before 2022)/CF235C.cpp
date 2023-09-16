#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,int M=26> struct suffixam{
	int tot,ch[N*2+10][M],fail[N*2+10],len[N*2+10],siz[N*2+10],last,q[N*2+10],inn[N*2+10];
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
	void toposort(){
		int L=1,R=0;
		for(int i=2;i<=tot;i++) inn[fail[i]]++;
		for(int i=1;i<=tot;i++) if(!inn[i]) q[++R]=i;
		while(L<=R){
			int u=q[++L];
			siz[fail[u]]+=siz[u];
			if(--inn[fail[u]]==0) q[++R]=fail[u];
		}
	}
	int tim;
	int vis[N*2+10]; 
	void add(int &u,int &l,char r){
		while(u&&!ch[u][r]) u=fail[u],l=len[u];
		if(ch[u][r]) u=ch[u][r],l++;
	}
	void del(int &u,int &l){
		if(--l==len[fail[u]]) u=fail[u];
	}
	LL solve(char *s){
		++tim;
		int len=strlen(s+1),u=1,l=0;LL ans=0;
		for(int i=1;i<=len;i++) add(u,l,s[i]-'a');
		if(l==len&&vis[u]<tim) ans+=siz[u],vis[u]=tim;
		for(int i=1;i<len;i++){
			add(u,l,s[i]-'a');
			while(l>len) del(u,l);
			if(l>=len&&vis[u]<tim) ans+=siz[u],vis[u]=tim;
		}
		return ans;
	}
};
int n,m;
char s[1000010];
suffixam<1000010> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++) t.expand(s[i]-'a');
	t.toposort();
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",s+1);
		printf("%lld\n",t.solve(s));
	}
	return 0;
}

