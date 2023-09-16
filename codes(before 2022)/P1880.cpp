#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,a[210],s[210],f[210][210];
int dp(){
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n*2;i++) f[i][i]=0;
	for(int t=2;t<=n;t++){
		for(int l=1,r=t;r<=n*2;l++,r++){
			for(int k=l;k<r;k++){
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
			} 
		}
	}
	int res=0x3f3f3f3f;
	for(int i=1;i<=n;i++) res=min(res,f[i][i+n-1]);
	return res;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i+n]=a[i];
	for(int i=1;i<=n*2;i++) s[i]=s[i-1]+a[i];
	printf("%d\n",dp());
	for(int i=1;i<=n*2;i++) s[i]=-s[i];
	printf("%d\n",-dp());
	return 0;
}

