
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
#define uint unsigned int
uint seed;
inline uint getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
int n;
bool isp[20000010];
unsigned int a[20000010],ans;
int main(){
	scanf("%d%u",&n,&seed);
	for(int i=1;i<=n;i++) a[i]=getnext();
	isp[1]=1;
	for(int i=1;i<=n;i++){
		if(isp[i]) continue;
		for(int j=1;j*i<=n;j++){
			a[j*i]+=a[j],isp[j*i]=1;
		}
	}
	for(int i=1;i<=n;i++) ans^=a[i];
	printf("%u\n",ans);
	return 0;
}

