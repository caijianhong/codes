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
int n,m,f[8][110][110],ans=1e9;
void floyed(int f[110][110],int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
}
void cdq(int l,int r,int dep){
//	if(l==r){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(l!=i&&l!=j&&i!=j) ans=min(ans,f[0][l][i]+f[0][l][j]+f[dep-1][i][j]);
//				//强制不经过 l 
//			}
//		}
//		return ;
//	}
//	int mid=(l+r)>>1; 
//	memcpy(f[dep],f[dep-1],sizeof f[dep]);
//	for(int i=mid+1;i<=r;i++) floyed(f[dep],i);
//	cdq(l,mid,dep+1);
//	memcpy(f[dep],f[dep-1],sizeof f[dep]);
//	for(int i=l;i<=mid;i++) floyed(f[dep],i);
//	cdq(mid+1,r,dep+1);
	memcpy(f[1],f[0],sizeof f[0]);
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(l!=i&&l!=j&&i!=j&&f[1][i][j]<1e9&&f[0][l][i]<1e9&&f[0][l][j]<1e9) ans=min(ans,f[0][l][i]+f[0][l][j]+f[1][i][j]);
				//强制不经过 l 
			}
		}
		floyed(f[1],l);
	}
	//强制一个环在编号最大的点计算贡献 
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[0][i][i]=0;
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),f[0][u][v]=f[0][v][u]=min(f[0][u][v],w);
	cdq(1,n,1);
	if(ans==1e9) puts("No solution.");
	else printf("%d\n",ans);
	return 0;
}

