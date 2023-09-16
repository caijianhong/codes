#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,a[1010];
LL f[1010][1010];
LL dp(){
	for(int i=1;i<=n;i++) f[i][i]=-a[i];
	for(int t=2;t<=n;t++){
		for(int l=1,r=t;r<=n;l++,r++){
			if(t%2) f[l][r]=a[l]>=a[r]?f[l+1][r]-a[l]:f[l][r-1]-a[r];//robot
			else f[l][r]=max(f[l+1][r]+a[l],f[l][r-1]+a[r]);//me
		}
	}
	return f[1][n];
}
int mian(){
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%lld\n",dp());
	return 0;
}
void reset(){
	
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d",&n);reset(),mian());
	return 0;
}

