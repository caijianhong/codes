#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,k,a[100010];LL f[21][100010]; 
template<int N> struct counter{
	int L,R,c[N+10];LL ans;
	counter():L(1),R(0),ans(0){memset(c,0,sizeof c);}
	LL operator()(int l,int r){
		while(L>l) ans+=c[a[--L]]++;
		while(R<r) ans+=c[a[++R]]++;
		while(L<l) ans-=--c[a[L++]];
		while(R>r) ans-=--c[a[R--]];
		return ans;
	}
};
counter<100010> c;
void solve(int l,int r,int L,int R,int d){
	if(l>r) return ;
	int mid=(l+r)>>1,pos=0;
	LL &res=f[d][mid];
	for(int i=max(1,L);i<=min(mid,R);i++){
		LL v=f[d-1][i-1]+c(i,mid);
		if(v<res) res=v,pos=i;
	}
//	assert(pos);
	solve(l,mid-1,L,pos,d),solve(mid+1,r,pos,R,d);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	memset(f,0x3f,sizeof f);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[1][0]=0;
	for(int i=1;i<=n;i++) f[1][i]=c(1,i);
	for(int i=2;i<=k;i++) f[i][0]=0,solve(1,n,1,n,i);
	printf("%lld\n",f[k][n]);
	return 0;
}

