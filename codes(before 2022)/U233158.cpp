#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n=2e6,m;
LL l,r,k,b[2000010];
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&m);
	for(int i=1;i<=n;i++) b[i]=1ll*i*i;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&l,&r,&k)s;
		puts(
			upper_bound(b+1,b+n+1,k+r)
		   -lower_bound(b+1,b+n+1,k+l)
		   	?"Yes":"No"
		);
	}
	return 0;
}

