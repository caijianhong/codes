#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,m;
template<int N,class T=int> struct splaytree{
	bool rev[N+10];T val[N+10],sum[N+10];
	int tot,root,ch[N+10][2],siz[N+10],fa[N+10];
	splaytree():tot(-1),root(0){newnode(0),siz[0]=0;}
	int newnode(int v){int p=++tot;return rev[p]=ch[p][0]=ch[p][1]=fa[p]=0,siz[p]=1,val[p]=sum[p]=v,p;}
	void maintain(int p){sum[p]=val[p]^sum[ch[p][0]]^sum[ch[p][1]];}
	void pushdown(int p){if(rev[p]) swap(ch[p][0],ch[p][1]),rev[ch[p][0]]^=1,rev[ch[p][1]]^=1,rev[p]=0;}
	void update(int p){if(fa[p]) update(fa[p]); pushdown(p);}
	bool getson(int p){return ch[fa[p]][1]==p;}
	void connect(int p,int q,int r){if(p) fa[p]=q; if(q) ch[q][r]=p;}
	void rotate(int p){int f=fa[p],r=getson(p);pushdown(f),pushdown(p),connect(p,fa[f],getson(f)),connect(ch[p][r^1],f,r),connect(f,p,r^1),maintain(f),maintain(p);}
	int splay(int p,int f=0){for(;fa[p]!=f;rotate(p)) if(fa[fa[p]]!=f) rotate(getson(p)==getson(fa[p])?fa[p]:p);return !f?root=p:p;}
	int getkth(int k,int p){int slc=siz[ch[p][0]];return pushdown(p),slc+1==k?splay(p):getkth(k-(k>slc)*(slc+1),ch[p][k>slc]);}
	void insert(int v,int &p,int f=0){if(!p) fa[p=newnode(v)]=f,splay(p); else pushdown(p),insert(v,ch[p][v>val[p]],p);}
	int split(int L,int R){int l=getkth(L-1,root),r=getkth(R+1,root);return splay(l),splay(r,l),ch[r][0];}
	void dfs(int p){if(p) pushdown(p),dfs(ch[p][0]),1<=val[p]&&val[p]<=n&&printf("%d ",val[p]),dfs(ch[p][1]);}
};
splaytree<100010,int> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;i++) t.insert(i,t.root);
	for(int i=1,l,r;i<=m;i++) scanf("%d%d",&l,&r),t.rev[t.split(l+1,r+1)]^=1;
	t.dfs(t.root);
	return 0;
}

