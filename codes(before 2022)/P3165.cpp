#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node;
int n,a[100010];
template<int N> struct splaytree{ 
	int tot,tsh[N+10],cnt,tag[N+10];node mn[N+10];
	int val[N+10],ch[N+10][2],fa[N+10],siz[N+10],root;
	void destroy(int p){tsh[++cnt]=p;}
	int newnode(int v=0){int p=cnt?tsh[cnt--]:++tot;return val[p]=v,mn[p]=node(a[v],v),siz[p]=1,ch[p][0]=ch[p][1]=fa[p]=0,p;} 
	splaytree():tot(0),cnt(0),root(0){siz[0]=0,insert(0,root),insert(n+1,root);}
	void add(int p){tag[p]^=1;}
	void maintain(int p){siz[p]=siz[ch[p][0]]+1+siz[ch[p][1]],mn[p]=min(node(a[val[p]],p),min(mn[ch[p][0]],mn[ch[p][1]]));}
	void pushdown(int p){if(tag[p]) swap(ch[p][0],ch[p][1]),add(ch[p][0]),add(ch[p][1]),tag[p]=0;}
	bool getson(int p){return ch[fa[p]][1]==p;}
	void connect(int p,int q,int r){p&&(fa[p]=q),q&&(ch[q][r]=p);}//p->q
    void rotate(int p){
        int f=fa[p],g=fa[fa[p]],r=getson(p);
        pushdown(f),pushdown(p);
        connect(p,g,getson(f));
        connect(ch[p][r^1],f,r);
        connect(f,p,r^1);
        maintain(f),maintain(p);
    }
	int splay(int p,int f=0){
		for(;fa[p]!=f;rotate(p))
			if(fa[fa[p]]!=f) rotate(getson(p)==getson(fa[p])?fa[p]:p);
		return !f?root=p:p;
	}
	int getkth(int k,int p){
		printf("k=%d,id=%d\n",k,p); 
		pushdown(p);
		int lc=siz[ch[p][0]];
		if(lc+1==k) return splay(p);
		return getkth(k-(k>lc)*(lc+1),ch[p][k>lc]); 
	}
	void insert(int v,int &p,int f=0){
		if(!p) return fa[p=newnode(v)]=f,splay(p),void();
		insert(v,ch[p][v>val[p]],p),maintain(p);
	}
	int split(int L,int R){int l=getkth(L,root),r=getkth(R+2,root);return splay(l),splay(r,l),ch[r][0];}
	void dfs(int p){if(p) pushdown(p),dfs(ch[p][0]),1<=val[p]&&val[p]<=n&&printf("%d ",val[p]),dfs(ch[p][1]);}
};
splaytree<100010> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),t.insert(i,t.root);
	for(int l=1;l<=n;l++){
		int r=t.mn[t.split(l,n)].second;
		printf("%d ",r);
		t.add(t.split(l,r));
	}
	return 0;
}

