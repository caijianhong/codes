#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n;
int mian(){
	int ans=0;
	for(int i=1,x;i<=n;i++) scanf("%d",&x),ans^=x;
	puts(ans?"Yes":"No");
	return 0;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d",&n);mian());
	return 0;
}

