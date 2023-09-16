#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,m,z[20000010],p[20000010];
char a[20000010],b[20000010];
void getz(char *a,int n){
	z[1]=n;
	for(int i=2,l=0,r=0;i<=n;i++){
		if(i<=r) z[i]=min(z[i-l+1],r-i+1);
		while(i+z[i]<=n&&a[i+z[i]]==a[z[i]+1]) z[i]++;
		if(i+z[i]-1>r) r=i+z[l=i]-1; 
	}
}
void match(char *a,int n,char *b,int m){
	b[m+1]='?';
	for(int i=1,l=0,r=0;i<=n;i++){
		if(i<=r) p[i]=min(z[i-l+1],r-i+1);
		while(i+p[i]<=n&&a[i+p[i]]==b[p[i]+1]) p[i]++;
		if(i+p[i]-1>r) r=i+p[l=i]-1;
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s%s",a+1,b+1),n=strlen(a+1),m=strlen(b+1);
	getz(b,m),match(a,n,b,m);
	LL ans1=0,ans2=0;
	for(int i=1;i<=n;i++) ans1^=1ll*i*(p[i]+1);
	for(int i=1;i<=m;i++) ans2^=1ll*i*(z[i]+1);
	printf("%lld\n%lld\n",ans2,ans1);
	return 0;
}

