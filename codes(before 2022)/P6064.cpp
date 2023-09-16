#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,m,a[4010],f[4010][4010][2];
int dp(bool flag){
	memset(f,~0x3f,sizeof f);
	if(flag) f[1][0][0]=f[1][1][1]=0;//1没有，n可有可无 
	else f[1][1][1]=a[1],f[1][0][0]=0;//1熟睡，n必须入睡，当然1也可以不睡 
	for(int i=2;i<=n;i++){
		f[i][0][0]=f[i][1][1]=0;
		for(int j=1;j<=m;j++){
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1]);
			f[i][j][1]=max(f[i-1][j-1][0],f[i-1][j-1][1]+a[i]);
		}
	}
	return flag?max(f[n][m][0],f[n][m][1]):f[n][m][1];
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d\n",max(dp(0),dp(1)));
	return 0;
}

