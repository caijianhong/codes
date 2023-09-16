#include <queue>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,class T,int D=31> struct trie{
	int tot,ch[N+10][2],siz[N+10];T val[N+10];
	trie():tot(-1){memset(ch[0],0,sizeof ch[0]),newnode(),val[0]=0;}
	int newnode(int q=0){int p=++tot;return memcpy(ch[p],ch[q],sizeof ch[p]),siz[p]=siz[q],p;}
	void maintain(int p){siz[p]=siz[ch[p][0]]+siz[ch[p][1]];}
	void insert(T v,int &p,int q,int dep=D){
		p=newnode(q);
		if(dep>=0) insert(v,ch[p][v>>dep&1],ch[q][v>>dep&1],dep-1),maintain(p);
		else val[p]=v,siz[p]++;
	}
	T query(T v,int k,int p,int dep=D){
	    assert(p);
//		printf("query v=%u,k=%d,p=%d,siz=%d+%d,dep=%d,",v,k,p,siz[ch[p][0]],siz[ch[p][1]],dep); 
		if(dep<0) return val[p]^v;
		int r=v>>dep&1;
		if(!ch[p][r^1]) return query(v,k,ch[p][r],dep-1);
		if(k<=siz[ch[p][r^1]]) return query(v,k,ch[p][r^1],dep-1);
		else return query(v,k-siz[ch[p][r^1]],ch[p][r],dep-1);
	}
};
int n,m,root[500010];
unsigned s[500010];
LL ans;
trie<500010*33,unsigned,31> t;
struct node{
	int p,rk;unsigned v;
	node(int p=0,int rk=1):p(p),rk(rk),v(t.query(s[p],rk,root[p])){}
	bool operator<(node b)const{return v<b.v;}
}; 
priority_queue<node> q;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	t.insert(0,root[0],0);
	for(int i=1;i<=n;i++) scanf("%u",&s[i]),t.insert(s[i]^=s[i-1],root[i],root[i-1]);
	for(int i=0;i<=n;i++) q.push(node(i,1));
	for(int i=1;i<=m;i++){
		node u=q.top();q.pop();
//		printf("u={%d,%d,%u}\n",u.p,u.rk,u.v);
		ans+=u.v;
		if(u.rk<=u.p) q.push(node(u.p,u.rk+1));
	}
	printf("%lld\n",ans);
	return 0;
}
/*
3 3
1 0 998244353
2994733058
1996488706
*/
