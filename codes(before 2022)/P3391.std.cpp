#include<bits/stdc++.h>
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]
using namespace std;
const int N=333333;
int n,m,x,y,a,t,l,r;
int ch[N][2],val[N],pri[N],siz[N],sz,root,tag[N];
struct fhq_treap{
	void pushdown(int p){
		if(tag[p]){
			swap(lc(p),rc(p));
			if(lc(p))tag[lc(p)]^=1;
			if(rc(p))tag[rc(p)]^=1;
			tag[p]^=1;
		}
	}
	void update(int x){siz[x]=1+siz[lc(x)]+siz[rc(x)];}
	int new_node(int v){
	    siz[++sz]=1;
	    val[sz]=v;
	    pri[sz]=rand();
	    return sz;
	}
	int merge(int x,int y){
	    if(!x||!y)return x+y;
	    if(pri[x]<pri[y]){
	    	pushdown(x);
	        rc(x)=merge(rc(x),y);
	        update(x);
	        return x;
	    }
	    else{
	    	pushdown(y);
	        lc(y)=merge(x,lc(y));
	        update(y);
	        return y;
	    }
	}
	void split(int p,int k,int &x,int &y){
	    if(!p)x=y=0;
	    else{
	    	pushdown(p);
	        if(siz[lc(p)]<k)x=p,split(rc(p),k-siz[lc(p)]-1,rc(p),y);
	        else y=p,split(lc(p),k,x,lc(p));
	        update(p);
	    }
	}
	int kth(int p,int k){
		if(!p)return 0;
		pushdown(p);
		if(k<=siz[lc(p)])return kth(lc(p),k);
		else if(k<=siz[lc(p)]+1)return val[p];
		else return kth(rc(p),k-1-siz[lc(p)]);
	}
	void print(int p){
		pushdown(p);
		if(lc(p))print(lc(p));
		printf("%d ",val[p]);
		if(rc(p))print(rc(p));
	}
}q;
int main(){
	#ifdef LOCAL
	 	freopen("data/input.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		q.new_node(i);
		root=q.merge(root,i);
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);l=x,r=y;
		if(x==y)continue;
		q.split(root,y,x,y);
		q.split(x,l-1,x,r);
		tag[r]^=1;
		root=q.merge(q.merge(x,r),y);
	}
	q.print(root);
	return 0;
}

