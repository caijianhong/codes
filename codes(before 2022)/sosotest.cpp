#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n;
LL f[100010],g[100010];
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%lld%lld",&n,&f[1],&g[1]);
	for(int i=2;i<=n;i++){
		f[i]=max(2*g[i-1]-i,f[i-1]+i); 
		g[i]=max(2*f[i-1]-i,g[i-1]+i);
		printf("f[%d]=%lld,g[%d]=%lld\n",i,f[i],i,g[i]);
		printf("trans: f={%lld,%lld}, g={%lld,%lld}\n",2*g[i-1]-i,f[i-1]+i,2*f[i-1]-i,g[i-1]+i);
	}
	printf("%lld %lld\n",f[n&1],g[n&1]);
	return 0;
}

