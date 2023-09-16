#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int _,__;
template<int N> struct splaytree{ 
	int tot,tsh[N+10],cnt;
	int val[N+10],ch[N+10][2],fa[N+10],siz[N+10],root;
	void destroy(int p){tsh[++cnt]=p;}
	int newnode(int v=0){int p=cnt?tsh[cnt--]:++tot;return val[p]=v,siz[p]=1,ch[p][0]=ch[p][1]=fa[p]=0,p;} 
	splaytree():tot(0),cnt(0),root(0){siz[0]=0;}
	int maintain(int p){return siz[p]=siz[ch[p][0]]+1+siz[ch[p][1]],p;}
	bool getson(int p){return ch[fa[p]][1]==p;}
	void connect(int p,int q,int r){p&&(fa[p]=q),q&&(ch[q][r]=p);}//p->q
    void rotate(int p){
        int f=fa[p],g=fa[fa[p]],r=getson(p);
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
	int getrnk(int v,int p,int f=0){
		if(!p) return splay(f),1;
		int res=(v>val[p])*(siz[ch[p][0]]+1);
		return getrnk(v,ch[p][v>val[p]],p)+res;
	}
	int getkth(int k,int p){
		int lc=siz[ch[p][0]];
		if(lc+1==k) return splay(p);
		return getkth(k-(k>lc)*(lc+1),ch[p][k>lc]); 
	} 
//	int getpre(int v){int k=getrnk(v,root)-1;return getkth(k,root);}
//	int getsuf(int v){int k=getrnk(v+1,root);return getkth(k,root);}
	int find(int v,int p){
		if(val[p]==v) return splay(p);
		return find(v,ch[p][v>val[p]]);
	}
	int getpre(int v,int p,int f=0){
		if(!p) return splay(f),-(1<<30);
		int vp=val[p];
		if(v<=val[p]) return getpre(v,ch[p][0],p);
		else return max(vp,getpre(v,ch[p][1],p));
	}
	int getsuf(int v,int p,int f=0){
		if(!p) return splay(f),1<<30;
		int vp=val[p];
		if(v>=val[p]) return getsuf(v,ch[p][1],p);
		else return min(vp,getsuf(v,ch[p][0],p));
	}
	void insert(int v,int &p,int f=0){
		if(!p) return fa[p=newnode(v)]=f,splay(p),void();
		siz[p]++,insert(v,ch[p][v>val[p]],p);
	}
	void erase(int v){
		int p=splay(find(v,root));
		if(!ch[p][0]||!ch[p][1]) return fa[root=ch[p][0]+ch[p][1]]=0,destroy(p);
		int q=ch[p][1];while(ch[q][0]) q=ch[q][0];
		val[p]=val[q];int qf=fa[q];
		connect(ch[q][1],qf,getson(q));
		for(destroy(q);(q=fa[q]);maintain(q));
		splay(qf);
	} 
	void build(int a[],int l,int r,int &p,int f=0){
		if(l>r) return ; 
		int mid=(l+r)>>1;
		if(!p) p=newnode(a[mid]);
		fa[p]=f;
		if(l==r) return ;
		build(a,l,mid-1,ch[p][0],p);
		build(a,mid+1,r,ch[p][1],p);
		maintain(p);
	}
};
int n,m,a[100010];
splaytree<1500010> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
	sort(a+1,a+n+1);
	t.build(a,1,n,t.root);
	t.insert(-(1<<30),t.root),t.insert(1<<30,t.root);
	for(int i=1,op,v;i<=m;i++){
		scanf("%d%d",&op,&v),v^=_;
		switch(op){
			case 1: t.insert(v,t.root);break;
			case 2: t.erase(v);break;
			case 3: __^=(_=t.getrnk(v,t.root)-1);break;
			case 4: __^=(_=t.val[t.getkth(v+1,t.root)]);break;
			case 5: __^=(_=t.getpre(v,t.root));break;
			case 6: __^=(_=t.getsuf(v,t.root));break; 
		}
//		if(op>=3) printf("%d\n",_);
//		printf(">%d %d=%d\n",op,v,_);
	}
	printf("%d\n",__);
	return 0;
}

