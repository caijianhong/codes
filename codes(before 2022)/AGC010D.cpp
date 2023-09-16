#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,a[100010]; 
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
bool check(){
	int cnt[2]={0,0},pos=0;
	for(int i=1;i<=n;i++){
		if(a[i]>1) cnt[a[i]%2]++;
		if(a[i]%2&&a[pos]>a[i]) pos=i;
	}
	if(a[pos]==1) return cnt[0]%2;
	if(cnt[0]%2) return 1;
	if(cnt[1]>1) return 0;
	int k=--a[pos];
	for(int i=1;i<=n;i++) k=gcd(k,a[i]);
	for(int i=1;i<=n;i++) a[i]/=k;
	return !check();
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	a[0]=2e9;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	puts(check()?"First":"Second");
	return 0;
}

