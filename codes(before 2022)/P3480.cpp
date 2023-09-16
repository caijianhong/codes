#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,a[100010];
int mian(){
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--) a[i]-=a[i-1];
	int sg=0; 
	for(int i=1;i<=n;i++) if((n-i)%2==0) sg^=a[i];//,printf("sg^=%d\n",a[i]);
	puts(sg?"TAK":"NIE");
	return 0;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d",&n);mian());
	return 0;
}

