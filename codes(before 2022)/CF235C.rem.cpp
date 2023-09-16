#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,int M=26> struct suffixam{
	int tot,last,ch[N*2+10][M],fail[N*2+10],len[N*2+10],siz[N*2+10];
	suffixam():tot(1),last(1){ch[1][0]=ch[1][1]=fail[1]=len[1]=siz[1]=0;}
	int expand(int r){
		int u=++tot,p=last;last=u;memset(ch[u],0,sizeof ch[u]);
		len[u]=len[p]+1,siz[u]=1;
		while(p&&!ch[p][r]) ch[p][r]=u,p=fail[p];
		if(!p) return fail[u]=1,u;
		int q=ch[p][r];
		if(len[q]==len[p]+1) return fail[u]=q,u;
		int cq=++tot;memcpy(ch[cq],ch[q],sizeof ch[cq]);
		fail[cq]=fail[q],len[cq]=len[p]+1,siz[cq]=0;
		fail[u]=fail[q]=cq;
		while(p&&ch[p][r]==q) ch[p][r]=cq,p=fail[p];
		return u;
	}
};
template<int N,int M=26> struct exsuffixam:public suffixam<N,M>{
	suffixam<N,M> &s=*this;
	int inn[N*2+10],f[N*2+10];
	void toposort(){
		queue<int> q;
		for(int i=1;i<=s.tot;i++) inn[s.fail[i]]++;
		for(int i=1;i<=s.tot;i++) if(!inn[i]) q.push(i);
		while(!q.empty()){
			int u=q.front();q.pop();
			s.siz[s.fail[u]]+=s.siz[u];
			if(--inn[s.fail[u]]==0) q.push(s.fail[u]); 
		}
	}
	void sshwysort(){
		queue<int> q;
		for(int i=1;i<=s.tot;i++){
			for(int j=0;j<M;j++){
				inn[s.ch[i][j]]++;	
				if(s.ch[i][j]) printf("%d %d %c\n",i,s.ch[i][j],j+'a');
			}
		}
		for(int i=1;i<=s.tot;i++) if(!inn[i]) q.push(i);
		f[1]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int j=0;j<M;j++){
				int v=s.ch[u][j];
				if(!v) continue;
				f[v]+=f[u];
				if(--inn[v]==0) q.push(v);
			}
		}
	} 
	void add(int &u,int &c,int r){
		while(u&&!s.ch[u][r]) u=s.fail[u],c=s.len[u];
		if(u) u=s.ch[u][r],c++;
		else u=1,c=0;
	}
	int vis[N*2+10],tim; 
	LL count(char *a){
		++tim;
		int len=strlen(a+1),u=1,c=0;
		LL ans=0;
		for(int i=1;i<=len;i++) add(u,c,a[i]-'a');
		for(int i=1;i<=len;i++){
			if(c>=len){
				while(u&&s.len[s.fail[u]]>=len) u=s.fail[u];
				if(vis[u]!=tim) ans+=s.siz[u],vis[u]=tim;
				c=len;
			}
//			printf(">u=%d\n",u);
			add(u,c,a[i]-'a');
		}
		return ans;
	}
};
int n,m;
char a[1000010],b[1000010];
exsuffixam<1000010> s;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s",a+1),n=strlen(a+1);
	for(int i=1;i<=n;i++) s.expand(a[i]-'a');
	s.toposort();
//	s.sshwysort();
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",b+1);
		printf("%lld\n",s.count(b));
	}
	return 0;
}

