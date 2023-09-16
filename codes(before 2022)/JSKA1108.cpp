#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,dis[10][310][310];
LL ans=0;
void insert(int k,int dep){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[dep][i][j]=min(dis[dep][i][j],dis[dep][i][k]+dis[dep][k][j]);
		}
	}
}
void cdq(int l,int r,int dep){
	if(l==r){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=l&&j!=r){
					if(dis[dep-1][i][j]>=1e9) ans--;
					else ans+=dis[dep-1][i][j];
				}
			}
		}
		return ;
	}
	int mid=(l+r)>>1;
	memcpy(dis[dep],dis[dep-1],sizeof dis[dep]);
	for(int i=mid+1;i<=r;i++) insert(i,dep);
	cdq(l,mid,dep+1);
	memcpy(dis[dep],dis[dep-1],sizeof dis[dep]);
	for(int i=l;i<=mid;i++) insert(i,dep);
	cdq(mid+1,r,dep+1);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&dis[0][i][j]);
			if(dis[0][i][j]==-1) dis[0][i][j]=1e9;
		}
	}
	cdq(1,n,1);
	printf("%lld\n",ans);
	return 0;
}

