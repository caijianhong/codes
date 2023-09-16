#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,class T=int> struct fenwick{
	T t[N+10],u[N+10],tag;
	fenwick(){memset(u,tag=0,sizeof u);}
	void add(T k,int p){for(;p<=N;p+=p&-p) u[p]!=tag&&(t[p]=0,u[p]=tag),t[p]+=k;}
	T query(int p){T ans=0;for(;p>=1;p-=p&-p) ans+=(u[p]==tag)*t[p];return ans;}
	void rollback(){tag++;}
};
template<int N,class T=int> struct segtree{//exfenwick
	fenwick<N,T> s,t;
	void add(T k,int l,int r){s.add(k,l),s.add(-k,r+1),t.add(k*(l-1),l),t.add(-k*r,r+1);}
	T query(int p){return s.query(p)*p-t.query(p);}
	T query(int l,int r){return query(r)-query(l-1);}
	void rollback(){s.rollback(),t.rollback();}
};
struct node{
	int l,r,id;LL k;
	node(int l=0,int r=0,LL k=0,int id=0):l(l),r(r),id(id),k(k){}
};
int n,ans[100010];
node a[100010],b[100010],c[100010];
segtree<100010,LL> t;
void print(){
	for(int i=1;i<=10;i++) printf("%lld%c",t.query(i,i)," \n"[i==10]);
}
void binary(int L,int R,int l,int r){
	if(l==r){
		for(int i=L;i<=R;i++) if(a[i].id>0) ans[a[i].id]=l;
		return ;
	}
	int mid=(l+r)>>1,t1=0,t2=0;
	for(int i=L;i<=R;i++){
		if(a[i].id<0){
			if(a[i].k<=mid) b[++t1]=a[i],t.add(1,a[i].l,a[i].r);//,printf("[%d~%d]+=%d:",a[i].l,a[i].r,1),print();
			else c[++t2]=a[i];
		}else{
			LL d=t.query(a[i].l,a[i].r);
			if(a[i].k<=d) b[++t1]=a[i];
			else a[i].k-=d,c[++t2]=a[i];
		}
	}
	memcpy(a+L,b+1,sizeof(node)*t1);
	memcpy(a+L+t1,c+1,sizeof(node)*t2); 
	t.rollback();//puts("rollback");
	binary(L,L+t1-1,l,mid),binary(L+t1,R,mid+1,r);
}
int main(){
	#ifdef LOCAL
	 	freopen("input.in","r",stdin);
	#endif
	scanf("%*d%d",&n);
	memset(ans,~0x3f,sizeof ans);
	for(int i=1,op;i<=n;i++){
		scanf("%d%d%d%lld",&op,&a[i].l,&a[i].r,&a[i].k);
		if(op==1) a[i].id=-i,a[i].k=-a[i].k; else a[i].id=i;
	}
	binary(1,n,-5e4,5e4);
	for(int i=1;i<=n;i++) if(ans[i]!=*ans) printf("%d\n",-ans[i]);
	return 0;
}

