#include <cstdio>
#include <cstring>
#include <utility>
#include <cassert>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
template<int N,class T=int> struct BB_alpha{
	const double alpha=0.75;
	int ch[N+10][2],tot,snt,top,tsh[N+10],cnt[N+10],siz[N+10];
	pair<T,int> stk[N+10]; T val[N+10];
	BB_alpha():tot(-1),snt(0){newnode(0,0);}
	int newnode(T k=0,int c=1){int p=snt?tsh[snt--]:++tot;return ch[p][0]=ch[p][1]=0,cnt[p]=siz[p]=c,val[p]=k,p;}
	bool BB(int p){return max(siz[ch[p][0]],siz[ch[p][1]])>siz[p]*alpha+5;}
	void maintain(int p){siz[p]=siz[ch[p][0]]+cnt[p]+siz[ch[p][1]];}
	void dfs(int p){if(p) dfs(ch[p][0]),cnt[p]&&(stk[++top]={val[p],cnt[p]},0),tsh[++snt]=p,dfs(ch[p][1]);}
	void build(int &p,int l,int r){
		if(l>r) return ;
		int mid=(l+r)>>1;
		p=newnode(stk[mid].first,stk[mid].second);
		build(ch[p][0],l,mid-1),build(ch[p][1],mid+1,r); 
		maintain(p);
	}
	void remake(int &p){if(BB(p)) top=0,dfs(p),p=0,build(p,1,top);}
	void insert(T v,int &p){
		if(!p) return p=newnode(v),void();
		remake(p); 
		if(val[p]==v) return cnt[p]++,maintain(p);
		insert(v,ch[p][v>val[p]]),maintain(p);
	}
	void erase(T v,int &p){
		if(!p) return assert(0),void();
		remake(p);
		if(val[p]==v) return assert(cnt[p]),cnt[p]--,maintain(p);
		erase(v,ch[p][v>val[p]]),maintain(p);
	}
	T getkth(int k,int &p){
		int lsz=siz[ch[p][0]];
		if(k<=lsz) return getkth(k,ch[p][0]);
		else return k-=lsz,k<=cnt[p]?val[p]:getkth(k-cnt[p],ch[p][1]);
	}
	int getrnk(T v,int &p){
		int lsz=siz[ch[p][0]];
		if(!p||v==val[p]) return lsz+1;
		else if(v<val[p]) return getrnk(v,ch[p][0]);
		else return getrnk(v,ch[p][1])+lsz+cnt[p];
	}
}; 
int n,m,root;
BB_alpha<1100010> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),t.insert(x,root);
	int _last=0,_ans=0;
	for(int i=1,op,v,x;i<=m;i++){
		scanf("%d%d",&op,&v);
		v^=_last;
		switch(op){
			case 1: t.insert(v,root);break;
			case 2: t.erase(v,root);break;
			case 3: _ans^=(_last=t.getrnk(v,root));break;
			case 4: _ans^=(_last=t.getkth(v,root));break;
			case 5: x=t.getrnk(v,root)-1,_ans^=(_last=t.getkth(x,root));break;
			case 6: x=t.getrnk(v+1,root),_ans^=(_last=t.getkth(x,root));break;
		}
	} 
	printf("%d\n",_ans);
	return 0;
}
/*
114514
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
1 14
1 15
1 16
1 17
1 18
1 19
1 20
1 21
1 22
1 23
1 24
1 25
1 13
4 12
4 13
4 14
4 15
*/
