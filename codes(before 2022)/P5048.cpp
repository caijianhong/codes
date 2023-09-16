//have seen the solution
#include <cmath>
#include <vector> 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,class T=int> struct flower{
    T b[N+10];int cnt;
    flower():cnt(0){}
    T operator+=(T x){return b[++cnt]=x;}
    void work(){sort(b+1,b+cnt+1),cnt=unique(b+1,b+cnt+1)-b-1;}
    int operator()(T x){return lower_bound(b+1,b+cnt+1,x)-b;}
    T operator[](int x){return b[x];}
};
template<int N> struct counter{
	int t[N+10],ans,u[N+10][2],tot;
//	counter(){memset(t,ans=0,sizeof t);}
	int operator[](int i){return t[i];}
	void insert(int x,int v=1){u[++tot][0]=x,u[tot][1]=v,ans=max(ans,t[x]+=v);}
	void rollback(){for(ans=0;tot>0;tot--) t[u[tot][0]]-=u[tot][1];}
};
int n,m,a[500010],_,f[2010][2010],id[500010];
int unit,bel[500010],lpos[2010];
flower<500010> b;
counter<500010> c;
vector<int> p[500010];
void divide(double u){
	unit=max(1,(int)ceil(u));
	for(int i=1;i<=n;i++) bel[i]=(i-1)/unit+1;
	for(int i=(lpos[1]=1)+1;i<=bel[n];i++) lpos[i]=lpos[i-1]+unit;
}
void init(){
	for(int i=1;i<=bel[n];i++){
		c.rollback();
		for(int j=lpos[i];j<=n;j++){
			c.insert(a[j]);
			if(bel[j]!=bel[j+1]) f[i][bel[j]]=c.ans;
		}
	}
	for(int i=1;i<=n;i++) p[a[i]].push_back(i),id[i]=p[a[i]].size()-1;
}
int count(int l,int r,int x){
	return upper_bound(p[x].begin(),p[x].end(),r)
		  -lower_bound(p[x].begin(),p[x].end(),l);
}
int solve(int l,int r){
	if(bel[l]==bel[r]){
		c.rollback();
		for(int i=l;i<=r;i++) c.insert(a[i]);
		return c.ans;
	}
	int res=f[bel[l]+1][bel[r]-1];
	//orz lxl
	//sol：预处理整块答案，剩下2sqrtn个值，答案最多增加2sqrtn，vector存下标，从a[i]被插入的地方往后res位，一直到l/r都增加答案 
	for(int i=l;bel[i]==bel[l];i++) for(int j=id[i]+res;p[a[i]][j]<=r&&j<p[a[i]].size();res++,j++);
	for(int i=r;bel[i]==bel[r];i--) for(int j=id[i]-res;p[a[i]][j]>=l&&j>=0;res++,j--);
	return res;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	divide(sqrt(n));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b+=a[i];
	b.work();
	for(int i=1;i<=n;i++) a[i]=b(a[i]);
	init();
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",_=solve(l^_,r^_));
	}
	return 0;
}

