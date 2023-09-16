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
void kmp(char s[],int fail[]){
	int n=strlen(s+1); fail[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[j+1]!=s[i]) j=fail[j];
		fail[i]=(j+=s[j+1]==s[i]);
	}
}
struct node{
	int ans,lpos,rpos;
	node(int ans=-1,int lpos=1,int rpos=0):ans(ans),lpos(lpos),rpos(rpos){}
	friend node operator+(node l,node r){return ~l.ans&&~r.ans?node(max({l.ans,r.ans,r.lpos-l.rpos}),l.lpos,r.rpos):(~l.ans?l:r);} 
};
template<int N> struct segtree{
	int ch[N+10][2],tot,tag[N+10];
	node ans[N+10];
	int newnode(){int p=++tot;return ch[p][0]=ch[p][1]=tag[p]=0,p;}
	segtree():tot(-1){newnode();}
	void pushdown(int p){
		if(ch[p][0]) tag[ch[p][0]]+=tag[p];
		if(ch[p][1]) tag[ch[p][1]]+=tag[p];
		tag[p]=0;
	}
	void modify(int x,int &p,int l=1,int r=3e5){
		if(!p) p=newnode();
		if(l==r) return ans[p]=node(0,x,x),void();
		int mid=(l+r)>>1; pushdown(p);
		if(x<=mid) modify(x,ch[p][0],l,mid);
		else modify(x,ch[p][1],mid+1,r);
		ans[p]=ans[ch[p][0]]+ans[ch[p][1]];
	} 
	void merge(int &p,int q,int l=1,int r=3e5){
		if(!p||!q) return p+=q,void();
		int mid=(l+r)>>1; pushdown(p),pushdown(q);
		merge(ch[p][0],ch[q][0],l,mid);
		merge(ch[p][1],ch[q][1],mid+1,r);
		ans[p]=ans[ch[p][0]]+ans[ch[p][1]]; 
	}
	int query(int k,int p,int l=1,int r=3e5){
//		printf("  query(k=%d,p=%d,l=%d,r=%d),ans[%d]={%d,%d,%d}\n",k,p,l,r,p,ans[p].ans,ans[p].lpos,ans[p].rpos);
		if(l==r) return l;
		int mid=(l+r)>>1;
		if(!ch[p][0]) return query(k,ch[p][1],mid+1,r);
		if(!ch[p][1]) return query(k,ch[p][0],l,mid);
		if(max(ans[ch[p][0]].ans,ans[ch[p][1]].lpos-ans[ch[p][0]].rpos)>k) return query(k,ch[p][0],l,mid);
		//答案不可能在右子树
		else return query(k,ch[p][1],mid+1,r); 
	}
	void add(int L,int R,int k,int &p,int l=1,int r=3e5){
		//只加存在的 
		if(!p) return ;
		if(L<=l&&r<=R) return tag[p]+=k,void();
		int mid=(l+r)>>1; pushdown(p);
		if(L<=mid) add(L,R,k,ch[p][0],l,mid);
		if(mid<R) add(L,R,k,ch[p][1],mid+1,r);
	}
	void get(int &p,int l=1,int r=3e5){
		if(!p) return ;
		if(l==r) return printf("%d\n",tag[p]),void();
		int mid=(l+r)>>1; pushdown(p);
		get(ch[p][0],l,mid),get(ch[p][1],mid+1,r);
	}
	void dfs(int p,int l,int r){
		if(!p) return ;
		if(l==r) return printf("%d(%d),",l,tag[p]),void();
		int mid=(l+r)>>1; pushdown(p);
		dfs(ch[p][0],l,mid),dfs(ch[p][1],mid+1,r);
	}
};
int n,fail[300010],root[300010];
char s[300010];
segtree<300010<<5> t;
graph<300010,300010> g;
void dfs(int u){
	t.modify(u,root[u],1,n);
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v;
		dfs(v);
		t.merge(root[u],root[v],1,n);
	}
//	printf("root[%d].query\n",u);
//	int res;
//	printf("=%d\n",res=t.query(u,root[u],1,n));
	t.add(1,t.query(u,root[u],1,n),1,root[u],1,n);
//	t.add(1,res,1,root[u],1,n);
//	printf("root[%d]={",u),t.dfs(root[u],1,n),printf("}\n");
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s",s+1),n=strlen(s+1),kmp(s,fail);
	for(int i=1;i<=n;i++) g.add(fail[i],i);//,printf("fail[%d]=%d\n",i,fail[i]);
	dfs(0),t.get(root[0],1,n);
	return 0;
}

