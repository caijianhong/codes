#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node;
int n,a[210],s[210],f[210][210],p[210][210];
int dp(){
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n*2;i++) f[i][i]=0,p[i][i]=i;
	for(int t=2;t<=n;t++){
		for(int l=1,r=t;r<=n*2;l++,r++){
			if(s[1]<0){
				f[l][r]=min(f[l][r-1],f[l+1][r])+s[r]-s[l-1];
				continue; 
			}
			for(int k=p[l][r-1];k<=p[l+1][r];k++){
				if(k<r&&f[l][r]>f[l][k]+f[k+1][r]+s[r]-s[l-1]){
					f[l][r]=f[l][k]+f[k+1][r]+s[r]-s[l-1];
					p[l][r]=k;
				}
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

