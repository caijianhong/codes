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
int n,f[110][110],a[110];
void floyed(int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
}
int solve(int u){
	int res=0;
	for(int i=1;i<=n;i++){
		res+=f[u][i]*a[i];
	}
	return res;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1,u,v;i<=n;i++) scanf("%d%d%d",&a[i],&u,&v),f[i][u]=f[u][i]=f[i][v]=f[v][i]=1;
	for(int i=1;i<=n;i++) floyed(i);
	int ans=1e9;
	for(int i=1;i<=n;i++) ans=min(ans,solve(i));
	printf("%d\n",ans);
	return 0;
}

