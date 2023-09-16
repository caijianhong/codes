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
int n,m,q,a[210],f[210][210];
bool vis[210];
void floyed(int k){
	vis[k]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),u++,v++,f[u][v]=f[v][u]=w;
	int now=0;
	scanf("%d",&q);
	for(int u,v,t;q--;){
		scanf("%d%d%d",&u,&v,&t),u++,v++;
		while(now+1<=n&&a[now+1]<=t) floyed(++now);
		printf("%d\n",vis[u]&&vis[v]&&f[u][v]<=1e9?f[u][v]:-1);
		debug("now=%d\n",now);
	}
	return 0;
}

