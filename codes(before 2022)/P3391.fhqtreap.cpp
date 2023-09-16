#include <ctime>
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct fhqtreap{
    int val[N+10],pri[N+10],siz[N+10],x,y,z,root,tag[N+10];
    int ch[N+10][2],tot,tsh[N+10],cnt;
    fhqtreap():tot(0),cnt(0){srand(time(0)),siz[0]=0;}
    int newnode(int v=0){int p=cnt?tsh[cnt--]:++tot;return val[p]=v,pri[p]=rand(),siz[p]=1,tag[p]=0,ch[p][0]=ch[p][1]=0,p;} 
    void destroy(int p){tsh[++cnt]=p;}
    void add(int p){if(p) tag[p]^=1;}
    void maintain(int p){siz[p]=siz[ch[p][0]]+1+siz[ch[p][1]];}
    void pushdown(int p){if(tag[p]) swap(ch[p][0],ch[p][1]),add(ch[p][0]),add(ch[p][1]),tag[p]=0;}
    int merge(int p,int q){
        if(!p||!q) return p+q;
        if(pri[p]<pri[q]) return pushdown(p),ch[p][1]=merge(ch[p][1],q),maintain(p),p;
        else return pushdown(q),ch[q][0]=merge(p,ch[q][0]),maintain(q),q;
    }
    void split(int p,int k,int &x,int &y){
        if(!p) return void(x=y=0);
        pushdown(p);
        int lc=siz[ch[p][0]];
        if(k>lc) x=p,split(ch[p][1],k-lc-1,ch[p][1],y);//左子树和根在 x
        else y=p,split(ch[p][0],k,x,ch[p][0]);//右子树和根在 y 
        maintain(p); 
    }
    void insert(int v){root=merge(root,newnode(v));}
    void modify(int L,int R){split(root,L-1,x,y),split(y,R-L+1,y,z),add(y),root=merge(x,merge(y,z));}
	void dfs(int p){if(p) pushdown(p),dfs(ch[p][0]),printf("%d ",val[p]),dfs(ch[p][1]);}
};
int n,m;
fhqtreap<100010> t; 
int main(){
	#ifdef LOCAL
	 	freopen("data/input.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) t.insert(i);
	for(int i=1,l,r;i<=m;i++) scanf("%d%d",&l,&r),t.modify(l,r);
	t.dfs(t.root);
	return 0;
}

