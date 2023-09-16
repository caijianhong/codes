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
int P;
void red(LL&x){x=(x%P+P)%P;}
int n; 
LL inv[3000010];
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&P);
	inv[1]=1;
	for(int i=2;i<=n;i++) red(inv[i]=(P-P/i)*inv[P%i]);
	for(int i=1;i<=n;i++) printf("%lld\n",inv[i]);
	return 0;
}

