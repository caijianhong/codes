#include <cstdio>
#include <cstring>
#include <cassert> 
#include <algorithm>
using namespace std;
typedef long long LL;
int n,m,pa[22000010];
char buf[11000010],a[22000010];
int manacher(char *a){
	int len=strlen(a+1);
	for(int i=1,mid=0,r=0;i<=len;i++){
		if(i<=r) pa[i]=min(pa[mid*2-i],r-i+1);
		while(a[i-pa[i]]==a[i+pa[i]]) pa[i]++;
		if(i+pa[i]>r) r=i+pa[mid=i]-1; 
	}
	return *max_element(pa+1,pa+len+1)-1; 
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s",buf+1),n=strlen(buf+1);
	a[0]='~',a[m=1]='|';
	for(int i=1;i<=n;i++) a[++m]=buf[i],a[++m]='|';
	a[++m]=0;
	printf("%d\n",manacher(a));
	return 0;
}

