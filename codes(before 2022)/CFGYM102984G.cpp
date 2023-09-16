#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,ans;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),ans^=x-2;
	char op;
	scanf(" %c",&op);
	puts(op=='W'^ans==0?"Whiteking":"Blackking");
	return 0;
}

