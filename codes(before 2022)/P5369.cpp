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
int n;
LL f[1<<20],g[1<<20],sum[1<<20],h[1<<20];
LL dp(){
	f[0]=1;
	for(int i=0;i<n;i++) g[1<<i]=1;
	for(int S=0;S<1<<n;S++){
//		debug("g[%d]=%lld\n",S,g[S]);
		for(int j=0;j<n;j++){
			if(S>>j&1) continue;
			if(sum[S]<=0&&sum[S|1<<j]<=0) red(f[S|1<<j]+=f[S]);
			if(sum[S]>0&&sum[S|1<<j]>0) red(g[S|1<<j]+=g[S]);
			if(sum[S]>0&&sum[S|1<<j]<0) red(h[S|1<<j]+=g[S]);
		}
	}
	LL ans=0,U=(1<<n)-1;
	for(int S=1;S<1<<n;S++){
		red(sum[S]);
		red(ans+=f[U^S]*(g[S]+h[S])%P*sum[S]);
//		debug("ans+=f[%d]*g[%d]*sum[%d], which is %lld*%lld*%lld\n",U^S,S,S,f[U^S],g[S],sum[S]);
	}
	return ans;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&sum[1<<i]);
	sum[0]=0;
	for(int i=1;i<1<<n;i++) sum[i]=sum[i^lowbit(i)]+sum[lowbit(i)];
	printf("%lld\n",dp());
	return 0;
}

