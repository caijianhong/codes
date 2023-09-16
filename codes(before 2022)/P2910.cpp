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
int n,m,f[510][510],a[100010];
void floyed(int f[510][510],int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&f[i][j]);
	for(int i=1;i<=n;i++) floyed(f,i);
	int ans=0;
	for(int i=1;i<m;i++) ans+=f[a[i]][a[i+1]];
	printf("%d\n",ans);
	return 0;
}

