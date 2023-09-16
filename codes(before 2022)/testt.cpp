//TLE 70 pts
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
int n,a[2010],g[2010];
bool f[2010][2010];
char h[2010][2010];
void dp_f(){
	for(int i=1;i<=n+1;i++) f[i][i-1]=1;
	for(int t=2;t<=n;t+=2){
		for(int l=1,r=t;r<=n;l++,r++){
			if(h[a[l]][a[r]]=='1') f[l][r]=f[l+1][r-1];
			for(int k=l;k<r&&!f[l][r];k++) f[l][r]|=f[l][k]&&f[k+1][r];
		}
	}
}
int dp_g(){
	int ans=n&1;
	g[0]=0;
	for(int i=1;i<=n;i++){
		g[i]=-1e9;
		for(int j=0;j<i;j++){
			if((!j||h[a[j]][a[i]]=='0')&&f[j+1][i-1]) g[i]=max(g[i],g[j]+1);
		}
		if(f[i+1][n]) ans=max(ans,g[i]);
//		debug("g[%d]=%d\n",i,g[i]);
	}
//	debug("answer:");
	return ans;
}
int mian(){
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%s",h[i]+1); 
	dp_f();
//	debug("output:"); 
	printf("%d\n",n-dp_g());
	return 0;
}
void reset(){
	memset(f,0,sizeof f);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("vmefifty.in","r",stdin);
//	 	freopen("vmefifty.out","w",stdout);
//	#endif
	for(scanf("%*d");~scanf("%d",&n);reset(),mian());
	return 0;
}
