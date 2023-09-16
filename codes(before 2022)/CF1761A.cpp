#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
int n,a,b;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d%d%d",&n,&a,&b);puts(a==n&&b==n||a+b<=n-2?"Yes":"No"));
	return 0;
}

