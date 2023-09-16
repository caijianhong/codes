//locked
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL n,l,r;
int main(){
// 	freopen("candy.in","r",stdin);
// 	freopen("candy.out","w",stdout);
	scanf("%lld%lld%lld",&n,&l,&r);
	if(l/n!=r/n) printf("%lld\n",n-1);
	else printf("%lld\n",r%n);
	return 0;
}

