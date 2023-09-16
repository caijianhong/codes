#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct splaytree{ 
	int tot,tsh[N+10],cnt,tag[N+10];
	int val[N+10],ch[N+10][2],fa[N+10],siz[N+10],root;
	void destroy(int p){tsh[++cnt]=p;}
	int newnode(int v=0){int p=cnt?tsh[cnt--]:++tot;return val[p]=v,siz[p]=1,ch[p][0]=ch[p][1]=fa[p]=0,p;} 
	splaytree():tot(0),cnt(0),root(0){siz[0]=0;}
	void add(int p){tag[p]^=1;}
	void maintain(int p){siz[p]=siz[ch[p][0]]+1+siz[ch[p][1]];}
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
		pushdown(p);
		int lc=siz[ch[p][0]];
		if(lc+1==k) return splay(p);
		return getkth(k-(k>lc)*(lc+1),ch[p][k>lc]); 
	} 
	void build(int l,int r,int &p,int f=0){
		if(l>r) return ; 
		int mid=(l+r)>>1;
		if(!p) fa[p=newnode(mid)]=f;
		if(l==r) return ;
		build(l,mid-1,ch[p][0],p);
		build(mid+1,r,ch[p][1],p);
		maintain(p);
	}
	void insert(int v,int &p,int f=0){
		if(!p) return fa[p=newnode(v)]=f,splay(p),void();
		insert(v,ch[p][v>val[p]],p);
	}
	void modify(int L,int R){int l=getkth(L-1,root),r=getkth(R+1,root);splay(l),splay(r,l),add(ch[r][0]);}
	void dfs(int p){if(p) pushdown(p),dfs(ch[p][0]),abs(val[p])!=1e9&&printf("%d ",val[p]),dfs(ch[p][1]);}
};
int n,m;
splaytree<100010> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	t.build(1,n,t.root);
	t.insert(-1e9,t.root),t.insert(1e9,t.root);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		t.modify(l+1,r+1);
	}
	t.dfs(t.root);
	return 0;
}

