#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,w;
LL b[100010],sum,ans;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&w);
	for(int i=1,x,y;i<=n;i++) scanf("%d%d",&x,&y),b[x]+=y;
	for(int i=0;i<w;i++) sum+=b[i];
	for(int i=w;i<=1e5;i++) ans=max(ans,sum),sum+=b[i]-b[i-w];
	printf("%lld\n",ans);
	return 0;
}

