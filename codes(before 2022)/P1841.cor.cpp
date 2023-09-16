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
int n,m,f[210][210],pos[210][210],ans[210];
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),f[u][v]=f[v][u]=min(f[u][v],w);
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||j==k||i==k) continue;
				if(f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j],pos[i][j]=k;
				else if(f[i][j]==f[i][k]+f[k][j]) pos[i][j]=0;
			}
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans[pos[i][j]]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++) if(ans[i]) printf("%d ",i),cnt++;
	if(!cnt) puts("No important cities.");
	return 0;
}

