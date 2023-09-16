#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct fenwick{
	int t[N+10],und[N+10][2],cnt;
	fenwick(){memset(t,0,sizeof t);}
	void add(int k,int p,bool u=1){for(u&&(und[++cnt][0]=k,und[cnt][1]=p);p<=N;p+=p&-p) t[p]+=k;}
	int query(int p){int ans=0;for(;p>=1;p-=p&-p) ans+=t[p];return ans;}
	void rollback(){for(;cnt>0;cnt--) add(-und[cnt][0],und[cnt][1],0);}
};
fenwick<100010> t;
struct ask{
	int l,r,k,id;
	ask(int l=0,int r=0,int k=0,int id=0):l(l),r(r),k(k),id(id){}
	bool operator<(ask b)const{return k<b.k;}
	int calc(){return t.query(r)-t.query(l-1);}
};
int n,m,ans[100010]; 
ask q[200010],q1[200010],q2[200010];
void binary(int L,int R,int l,int r){
//	printf("L=%d,R=%d,l=%d,r=%d\n",L,R,l,r);
	if(L>R) return ; 
	if(l==r){
		for(int i=L;i<=R;i++) if(q[i].l>0) ans[q[i].id]=l;
		return ;
	}
	int mid=(l+r)>>1,t1=0,t2=0;
	for(int i=L;i<=R;i++){
		if(q[i].l<0){
			if(q[i].k<=mid) t.add(1,q[i].id),q1[++t1]=q[i];
			else q2[++t2]=q[i];
		}
	}
	for(int i=L;i<=R;i++){
		if(q[i].l>0){
			if(q[i].k<=q[i].calc()) q1[++t1]=q[i];
			else q[i].k-=q[i].calc(),q2[++t2]=q[i];
		}
	}
	memcpy(q+L,q1+1,sizeof(ask)*t1);
	memcpy(q+L+t1,q2+1,sizeof(ask)*t2);
	t.rollback();
	binary(L,L+t1-1,l,mid),binary(L+t1,R,mid+1,r); 
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&q[i+m].k),q[i+m].id=i,q[i+m].l=-1;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k),q[i].id=i;
	binary(1,n+m,-1e9,1e9);
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}

