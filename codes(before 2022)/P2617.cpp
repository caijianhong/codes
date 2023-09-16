#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct flower{
    int b[N+10],cnt;
    flower():cnt(0){}
    void operator+=(int x){b[++cnt]=x;}
    void build(){sort(b+1,b+cnt+1),cnt=unique(b+1,b+cnt+1)-b-1;}
    int operator()(int x){return lower_bound(b+1,b+cnt+1,x)-b;}
    int operator[](int i){return b[i];}
};
template<int N> struct segtree{
	int tot,ch[N+10][2],siz[N+10];
	segtree():tot(-1){siz[0]=0,newnode();}
	int newnode(){int p=++tot;return ch[p][0]=ch[p][1]=siz[p]=0,p;}
	void maintain(int p){siz[p]=siz[ch[p][0]]+siz[ch[p][1]];}
	void _modify(int k,int x,int &p,int l=1,int r=N){
		if(!p) p=newnode();
		if(x<=l&&r<=x) return void(siz[p]+=k);
		int mid=(l+r)>>1;
		if(x<=mid) _modify(k,x,ch[p][0],l,mid);
		if(mid+1<=x) _modify(k,x,ch[p][1],mid+1,r);
		maintain(p);
	}
	int calc(vector<int> &ps){
		LL res=0;
		for(int i=0;i<ps.size();i++){
			int p=ps[i];
			res+=p>0?siz[ch[p][0]]:-siz[ch[-p][0]]; 
		}
		return res;
	}
	void update(vector<int> &ps,int r){
		for(int i=0;i<ps.size();i++){
			int &p=ps[i];
			if(p>0) p=ch[p][r]; else p=-ch[-p][r];
		}
	}
	int _query(int k,vector<int> &ps,int l=1,int r=N){
		if(l==r) return l;
		int slc=calc(ps),mid=(l+r)>>1;
		if(k<=slc) return update(ps,0),_query(k,ps,l,mid);
		else return update(ps,1),_query(k-slc,ps,mid+1,r);
	}
};
template<int N> struct fenwick:public segtree<N*18*18>{
//出题人您能不能离散化？您能离散化吗？您吗？ 
//我到底维护了个什么东西？？？ 
//不用继承的可持久化算个什么可持久化？？？ 
//这是 fenwick 套 segtree 吧？？？ 
	int root[N+10];
	fenwick(){memset(root,0,sizeof root);}
	void modify(int k,int x,int p){
//		printf("modify k=%d,x=%d,p=%d\n",k,x,p);
		for(;p<=N;p+=p&-p) this->_modify(k,x,root[p]);
	}
	//modify the trees which about p with operator [x]+=k
	int query(int k,int l,int r){
//		printf("query %d %d %d\n",k,l,r);
		vector<int> ccf;
		for(int p=l-1;p>=1;p-=p&-p) ccf.push_back(-root[p]);
		for(int p=r;p>=1;p-=p&-p) ccf.push_back(root[p]);
//		for(int i=0;i<ccf.size();i++) printf("%d ",ccf[i]);puts("");
		return this->_query(k,ccf);
	}
};
int n,m,a[200010];
flower<200010> b;
fenwick<200010> t; 
char op[200010][30];
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sprintf(op[i],"C %d %d",i,a[i]),b+=a[i];
	scanf(" "); 
	for(int i=1,x;i<=m;i++){
		fgets(op[i+n],sizeof op[i+n],stdin);
		if(*op[i+n]=='C') sscanf(op[i+n]," %*c%*d%d",&x),b+=x;
	}
	b.build();
	for(int i=1,l,r,k;i<=n+m;i++){
		if(*op[i]=='C'){
			sscanf(op[i]," %*c%d%d",&l,&k);
//			printf(">C %d %d\n",l,k);
			if(i>n) t.modify(-1,b(a[l]),l);
			a[l]=k;
			t.modify(1,b(a[l]),l);
		}else{
			sscanf(op[i]," %*c%d%d%d",&l,&r,&k);
//			printf(">Q %d %d %d\n",l,r,k);
			printf("%d\n",b[t.query(k,l,r)]); 
		}
	}
	return 0;
}

