#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,class T=int> struct fenwick{
	T t[N+10],u[N+10],tag;
	fenwick(){memset(u,tag=0,sizeof u);}
	void add(T k,int p){for(p+=2.5e5;p<=N;p+=p&-p) u[p]!=tag&&(t[p]=0,u[p]=tag),t[p]+=k;}
	T query(int p){T ans=0;for(p+=2.5e5;p>=1;p-=p&-p) ans+=(u[p]==tag)*t[p];return ans;}
	void rollback(){tag++;}
};
struct node{
	int a[3],id,op,v;
	node(int x=0,int y=0,int z=0,int id=0,int op=0,int v=0):id(id),op(op),v(v){a[0]=x,a[1]=y,a[2]=z;}
	int& operator[](int i){return a[i];}
	bool operator<(node b){
		for(int i=0;i<3;i++) if(a[i]!=b[i]) return a[i]<b[i];
		return op<b.op;
	}
	void print(){
		printf("{%d,%d,%d}[%d]=(%d,%d)\n",a[0],a[1],a[2],id,op,v);
	}
}; 
int n,m,a[4][200010];
LL ans;
node _[2][500010];
fenwick<500010> s,t;
void prints(node a[],int l,int r){
	for(int i=l;i<=r;i++){
		a[i].print(); 
	}
}
LL cdq(int L,int R,node a[],node b[]){
	if(L==R) return 0;
	int mid=(L+R)>>1;
	LL ans=cdq(L,mid,a,b)+cdq(mid+1,R,a,b);
//	printf("L=%d,R=%d,ans=%lld\n",L,R,ans);
//	printf("a={\n"),prints(a,L,R);
	int cnt=L,j=L;
	for(int i=mid+1;i<=R;b[cnt++]=a[i++]){
		for(;j<=mid&&a[j][1]<=a[i][1];b[cnt++]=a[j++]) if(a[j].op==1) t.add(a[j].v,a[j][2]),s.add(1,a[j][2]);
		if(a[i].op==0) ans+=t.query(a[i][2])+1ll*s.query(a[i][2])*a[i].v;
	}
//	for(int i=L;i<=mid;i++) if(a[i].op==1) t.add(-a[j].v,a[j][2]),s.add(-1,a[j][2]);
	for(;j<=mid;b[cnt++]=a[j++]);
//	printf("}\nb={\n"),prints(b,L,R);
//	printf("}\nnow ans=%lld\n============\n",ans);
	memcpy(a+L,b+L,sizeof(node)*(R-L+1));
	t.rollback(),s.rollback();
	return ans;//cdq(L,R,dep+1,b,_[dep+1])+ans;
}
LL solve(int d){
	for(int i=1;i<=n;i++){
		_[0][i]=node(0,0,0,i,0,a[d][i]);
		_[0][i+n]=node(0,0,0,i+n,1,a[d][i]);
		for(int j=0,k=0;j<m;j++){
			if(j!=d){
				_[0][i][k]=a[d][i]-a[j][i];
				_[0][i+n][k]=a[j][i]-a[d][i]+(j<d);
				k++;
			}
		}
	}
	sort(_[0]+1,_[0]+2*n+1);
	return cdq(1,2*n,_[0],_[1]);
}
int main(){
	#ifdef LOCAL
	 	freopen("input.in","r",stdin);
	#endif
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<m;i++) ans+=solve(i);
	for(int i=0;i<m;i++) for(int j=1;j<=n;j++) a[i][j]=-a[i][j];
	for(int i=0;i<m;i++) ans-=solve(i);
	printf("%lld\n",ans);
	return 0;
} 
