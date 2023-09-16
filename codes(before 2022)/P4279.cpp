#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,sg,mx;
int mian(){
	for(int i=1,x;i<=n;i++) scanf("%d",&x),sg^=x,mx=max(mx,x);
	puts(!sg^mx>1?"John":"Brother");
	return 0;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d",&n);sg=mx=0,mian());
	return 0;
}

