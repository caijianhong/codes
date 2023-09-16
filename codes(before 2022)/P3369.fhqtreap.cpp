#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct fhqtreap{
	int val[N+10],pri[N+10],siz[N+10],x,y,z,root;//小根堆 
	int ch[N+10][2],tot,tsh[N+10],cnt;
	fhqtreap():tot(0),cnt(0){srand(time(0)),siz[0]=0;}
	int newnode(int v=0){int p=cnt?tsh[cnt--]:++tot;return val[p]=v,pri[p]=rand(),siz[p]=1,ch[p][0]=ch[p][1]=0,p;} 
	void destroy(int p){tsh[++cnt]=p;}
	int maintain(int p){return siz[p]=siz[ch[p][0]]+1+siz[ch[p][1]],p;}
	int merge(int p,int q){
		if(!p||!q) return p+q;
		if(pri[p]<pri[q]) return ch[p][1]=merge(ch[p][1],q),maintain(p);
		else return ch[q][0]=merge(p,ch[q][0]),maintain(q);
	}
	void split(int p,int v,int &x,int &y){
		if(!p) return void(x=y=0);
		if(val[p]<=v) x=p,split(ch[p][1],v,ch[p][1],y);//左子树和根在 x
		else split(ch[p][0],v,x,ch[p][0]),y=p;//右子树和根在 y 
		maintain(p); 
	}
	void insert(int v){split(root,v,x,y),root=merge(merge(x,newnode(v)),y);}
	void erase(int v){split(root,v-1,x,y),split(y,v,y,z),destroy(y),root=merge(merge(x,ch[y][0]),merge(ch[y][1],z));}
	int getrnk(int v){split(root,v-1,x,y);int res=siz[x]+1;return root=merge(x,y),res;}
	int getkth(int k,int p){
		if(siz[ch[p][0]]+1==k) return val[p];
		if(k<=siz[ch[p][0]]) return getkth(k,ch[p][0]);
		else return getkth(k-siz[ch[p][0]]-1,ch[p][1]); 
	}
	int getpre(int v){return getkth(getrnk(v)-1,root);}
	int getsuf(int v){return getkth(getrnk(v+1),root);}
};
int n;
fhqtreap<100010> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1,op,v;i<=n;i++){
		scanf("%d%d",&op,&v);
		switch(op){
			case 1: t.insert(v);break;
			case 2: t.erase(v);break;
			case 3: printf("%d\n",t.getrnk(v));break;
			case 4: printf("%d\n",t.getkth(v,t.root));break;
			case 5: printf("%d\n",t.getpre(v));break;
			case 6: printf("%d\n",t.getsuf(v));break;
		}
	} 
	return 0;
}

