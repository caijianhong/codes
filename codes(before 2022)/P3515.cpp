#include <cmath> 
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
#define l first
#define r second
typedef long long LL;
typedef pair<int,int> node; 
//f[i]=max{-a[i]+a[j]+sqrt(i,j)}
int n,a[500010],q[500010];
double f[500010],sq[500010];
node ra[500010];
double calc(int i,int j){return a[j]+sq[i-j];}
int binary(int L,int R,int i,int j){
	int ans=0;
	while(L<=R){
		int mid=(L+R)>>1;
		if(calc(mid,i)>=calc(mid,j)) ans=mid,R=mid-1;
		else L=mid+1;
	}
	return ans;
}
void dp(){
	int L=1,R=0;
	for(int i=1;i<=n;i++){
		int pos=i;ra[R].l=max(ra[R].l,i);
		while(L<=R&&calc(ra[R].l,i)>=calc(ra[R].l,q[R])) R--;
		if(L<=R) pos=binary(ra[R].l,ra[R].r,i,q[R]);
		if(pos) ra[R].r=pos-1,ra[++R]=node(pos,n),q[R]=i;
		while(L<=R&&ra[L].r<i) L++;
		f[i]=max(f[i],calc(i,q[L]));
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sq[i]=sqrt(i);
	dp(),reverse(a+1,a+n+1),reverse(f+1,f+n+1),dp();
	for(int i=n;i>=1;i--) printf("%.0f\n",max(ceil(f[i]-a[i]),.0));
	return 0;
}

