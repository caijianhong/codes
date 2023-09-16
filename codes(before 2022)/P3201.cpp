#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
int stk[100010],top;
template<int N,int M> struct segtree{
	int ch[N+10][2],tot,tsh[N+10],cnt,ans[N+10];//ans=sum
	segtree():tot(-1),cnt(0){newnode();}
	int newnode(){int p=cnt?tsh[cnt--]:++tot;return ch[p][0]=ch[p][1]=ans[p]=0,p;}
	void modify(int x,int k,int &p,int l=0,int r=M){
		if(!p) p=newnode();
		if(l==r) return ans[p]+=k,void();
		int mid=(l+r)>>1;
		if(x<=mid) modify(x,k,ch[p][0],l,mid);
		else modify(x,k,ch[p][1],mid+1,r);
		ans[p]=ans[ch[p][0]]+ans[ch[p][1]];
	}
	int query(int x,int &p,int l=0,int r=M){
		if(!p||l==r) return ans[p];
		int mid=(l+r)>>1;
		if(x<=mid) return query(x,ch[p][0],l,mid);
		else return query(x,ch[p][1],mid+1,r); 
	}
	void dfs(int p,int l=0,int r=M){//1log
		if(!p) return ;
		if(l==r) return stk[++top]=l,void();
		int mid=(l+r)>>1;
		dfs(ch[p][0],l,mid),dfs(ch[p][1],mid+1,r);
	}
	void merge(int &p,int q,int l=0,int r=M){
		if(!p||!q) return p+=q,void(); else tsh[++cnt]=q;
		if(l==r) return ans[p]+=ans[q],void();
		int mid=(l+r)>>1;
		merge(ch[p][0],ch[q][0],l,mid);
		merge(ch[p][1],ch[q][1],mid+1,r);
		ans[p]=ans[ch[p][0]]+ans[ch[p][1]];
	}
};
int n,m,root[1000010],a[100010],ans;
segtree<100010*20,100010> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),t.modify(i,1,root[a[i]]);
	for(int i=1;i<n;i++) ans+=a[i]!=a[i+1];
	for(int i=1,x,y,op;i<=m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			if(x==y) continue;
			bool flag=0;
			if(t.ans[root[x]]>t.ans[root[y]]) swap(x,y),flag=1;
			top=0,t.dfs(root[x]);
			for(int i=1;i<=top;i++) ans-=t.query(stk[i]-1,root[y])+t.query(stk[i]+1,root[y]);
			if(flag) swap(x,y);
			t.merge(root[y],root[x]),root[x]=0;
		}else printf("%d\n",ans+1);
	}
	return 0;
}
/*
合并之前看一下两个是否有相邻的，然后线段树合并
如果用点数小的线段树查询，复杂度是两只 log 
*/
