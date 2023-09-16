#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long LL;
int n,a[1010],p[1010];
char ans[1010][1010];
bool cmp(int x,int y){return a[x]>a[y];}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	memset(ans,'0',sizeof ans);
	scanf("%d",&n);
	printf("%d\n",n+1);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++){
		int pos=n-i+1;
		for(int j=1;j<=a[p[i]];j++,pos=(pos-1+n+1)%(n+1)) ans[pos][p[i]]='1';
	}
	for(int i=0;i<=n;i++) ans[i][n+1]=0,puts(ans[i]+1);
	return 0;
}

