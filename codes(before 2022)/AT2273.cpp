#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,a[100010],c[100010],pos[100010],cnt;
LL sum[100010],ans[100010],res;
LL qsum(int l,int r){return sum[r]-sum[l-1];}
LL qans(int l,int r){return ans[r]-ans[l-1];}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	c[1]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){char op;
		if(i!=1) scanf(" %c",&op),c[i]=(op=='-'?-1:1);
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+c[i]*a[i];
		ans[i]=ans[i-1]+a[i];
		if(c[i]==-1) pos[++cnt]=i;
	}
	for(int i=1;i<cnt;i++){
		res=max(
			res,
			qsum(1,pos[i]-1)
			-qans(pos[i],pos[i+1]-1)
			+qans(pos[i+1],n)
		);
	}
	printf("%lld\n",max(res,sum[n]));
	return 0;
}
/*
a+b-(c+d-(e+f))
*/
