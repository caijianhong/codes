#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
int n,minh,a[100010],b[100010];
LL solve(int k){
	if(k>minh||k<0) return -1;
	debug("solve(%d)\n",k);
	memcpy(b,a,sizeof b);
	LL ans=0;
	for(int i=1;i<n;i++){
		int d=b[i]-k;
		if(d<0) return -1;
		b[i]-=d,b[i+1]-=d,ans+=d<<1;
	}
	return b[n]==k?ans:-1;
}
int binary(int L,int R,function<bool(int)> check){
	int ans=-1;
	for(int mid=(L+R)>>1;debug("[%d,%d]\n",L,R),L<=R;mid=(L+R)>>1){
		if(check(mid)) ans=mid,L=mid+1;
		else R=mid-1;
	}
	return ans;
}
int mian(){
	int d=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),d^=a[i]&1;
	if(n==1) return puts("0"),0;
	if(n==2) return puts(a[1]==a[2]?"0":"-1"),0;
	minh=*min_element(a+1,a+n+1);
	if(n%2) printf("%lld\n",solve(binary(0,1e9,[&](int k){return solve(k<<1|d)>=0;})<<1|d));
	else printf("%lld\n",solve(binary(0,1e9,[&](int k){return solve(k)>=0;})));
	return 0;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d",&n);mian());
	return 0;
}

