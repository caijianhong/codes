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
const int P=998244353;
int lowbit(int x){return x&-x;}
void red(LL&x){x=(x%P+P)%P;}
int n,a[1<<20],sum[1<<20];
LL f[1<<20],g[1<<20];
LL dp(){
	f[0]=g[0]=1;
	for(int S=0;S<1<<n;S++){
		for(int j=0;j<n;j++){
			if(S>>j&1) continue;
			if(sum[S|1<<j]<=0) red(f[S|1<<j]+=f[S]);
			if(-sum[S|1<<j]<0) red(g[S|1<<j]+=g[S]);
		}
	}
	LL ans=0,U=(1<<n)-1;
	for(int j=0;j<n;j++){
		debug("make a[%d]=%d as the maxinum\n",j,a[1<<j]);
		for(int S=0;S<1<<n;S++){
			if(!(S>>j&1)) continue;
			debug("ans+=f[%d]*f[%d]*sum[%d], which is %lld*%lld*%d\n",S^(1<<j),U^S,U^S,f[S^(1<<j)],g[U^S],sum[U^S^(1<<j)]);
			red(ans+=f[S^(1<<j)]*g[U^S]%P*sum[U^S^(1<<j)]);
		}
	}
	return ans;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[1<<i]);
	sum[0]=0;
	for(int i=1;i<1<<n;i++) sum[i]=sum[i^lowbit(i)]+a[lowbit(i)];
	printf("%lld\n",dp());
	return 0;
}

