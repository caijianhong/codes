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
int n,m,k,f[510][510],a[510];
void floyed(int f[510][510],int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
}
LL calc(int u){
	LL res=0;
	for(int i=1;i<=k;i++) res+=f[u][a[i]];
	return res; 
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=k;i++) scanf("%d",&a[i]);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),f[u][v]=f[v][u]=min(f[u][v],w);
	for(int i=1;i<=n;i++) floyed(f,i);
	int ans=0;
	for(int i=1;i<=n;i++) if(calc(ans)>calc(i)) ans=i;
	printf("%d\n",ans);
	return 0;
}

