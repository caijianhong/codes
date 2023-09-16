#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct dsu{
	int fa[N+10],siz[N+10],cnt;
	dsu(int n=N):cnt(n){for(int i=1;i<=n;i++) fa[i]=i,siz[i]=0;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){if(x=find(x),y=find(y),x!=y) cnt--,siz[x]+=siz[y],fa[y]=x;}
};
int n,m,k,ans[210],cnt;
bool vis[210];
char a[60][60];
dsu<210> s;
bool check(int p,int q){
	int res=0;
	for(int i=1;i<=m;i++) res+=a[p][i]==a[q][i];
	return res>=k;
}
int calc(int p,int q){
	int res1=check(p,q);
	reverse(a[p]+1,a[p]+m+1);
	int res2=check(p,q);
	reverse(a[p]+1,a[p]+m+1);
	return res1<<4|res2;
}
int mian(){
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++) s.siz[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			switch(calc(i,j)){
				case 0x00: return puts("-1"),0;
				case 0x01: s.merge(i,j+n),s.merge(i+n,j);break;
				case 0x10: s.merge(i,j),s.merge(i+n,j+n);break;
			}
		}
	}
	for(int i=1;i<=n;i++) if(s.find(i)==s.find(i+n)) return puts("-1"),0;
	for(int i=1;i<=n;i++){
		int r=0; 
		switch(vis[s.find(i)]<<4|vis[s.find(i+n)]){
			case 0x00: r=s.siz[s.find(i)]<s.siz[s.find(i+n)]?i+n:i;break;
			case 0x01: r=i+n;break;
			case 0x10: r=i;break;
			case 0x11: return puts("-1"),0;
		}
		if(r>n) ans[++cnt]=r-n;
		vis[s.find(r)]=1;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) printf("%d%c",ans[i]," \n"[i==cnt]);
	return 0;
}
void reset(){
	memset(vis,0,sizeof vis);
	s=dsu<210>();
	cnt=0;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d%d%d",&n,&m,&k);reset(),mian());
	return 0;
}

