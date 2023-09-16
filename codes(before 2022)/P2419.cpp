#include <bitset>
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
int n,m;
bitset<110> f[110];
void floyed(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//				if(f[i][k]) f[i][j]|=f[k][j];
//			}
			if(f[i][k]) f[i]|=f[k];
		}
	}
}
bool check(int u){
	for(int i=1;i<=n;i++) if(!f[u][i]&&!f[i][u]) return 0;
	return 1;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),f[u][v]=1;
	for(int i=1;i<=n;i++) f[i][i]=1;
	floyed();
	int ans=0;
	for(int i=1;i<=n;i++) ans+=check(i);
	printf("%d\n",ans);
	return 0;
}

