#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node;
int root[100010];
template<int N> struct fhqtreap{
	node val[N+10];int pri[N+10],siz[N+10],x,y,z,root;//小根堆 
	int ch[N+10][2],tot,tsh[N+10],cnt;
	fhqtreap():tot(0),cnt(0){srand(time(0)),siz[0]=0;}
	int newnode(node v=0){int p=cnt?tsh[cnt--]:++tot;return val[p]=v,pri[p]=rand(),siz[p]=1,ch[p][0]=ch[p][1]=0,p;} 
	int maintain(int p){return siz[p]=siz[ch[p][0]]+1+siz[ch[p][1]],p;}
	int merge(int p,int q){
		if(!p||!q) return p+q;
		if(pri[p]<pri[q]) return ch[p][1]=merge(ch[p][1],q),maintain(p);
		else return ch[q][0]=merge(p,ch[q][0]),maintain(q);
	}
	void split(int p,node v,int &x,int &y){
		if(!p) return void(x=y=0);
		if(val[p]<=v) x=p,split(ch[p][1],v,ch[p][1],y);//左子树和根在 x
		else split(ch[p][0],v,x,ch[p][0]),y=p;//右子树和根在 y 
		maintain(p); 
	}
	void erase(node v,int &p){split(p,node(v.first-1,0),x,y),split(y,v,y,z),tsh[++cnt]=y,p=merge(merge(x,ch[y][0]),merge(ch[y][1],z));}
	node getkth(int k,int p){int d=k-siz[ch[p][0]]-1;if(!d) return val[p]; else return d>0?getkth(d,ch[p][1]):getkth(k,ch[p][0]);}
};
int n,m;
bool vis[100010];
fhqtreap<100010> t;
int find(int x){return root[x]==x?x:find(root[x]);}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),t.newnode(node(x,i)),root[i]=i;
	for(int i=1,op,x,y;i<=m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			if(vis[x]||vis[y]) continue;
			x=find(x),y=find(y);
			if(t.val[x]>t.val[y]) swap(x,y); 
			if(x!=y) root[x]=root[y]=t.merge(x,y);
		}else{
			scanf("%d",&x);
			if(vis[x]){puts("-1");continue;}
			x=find(x);
			node res=t.getkth(1,root[x]);
			printf("%d\n",res.first);
			t.erase(res,root[x]);
		}
	} 
	return 0;
}

