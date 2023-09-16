#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n;
char a[200010],s[200010];
int mian(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		s[i]=a[i];
		if(a[i]=='(') cnt++;
		else if(a[i]==')') cnt--;
		else{
			cnt++;//'('
			s[i]='(';
		}
	}
	int sum=0;
	for(int i=n;i>=1;i--) if(a[i]=='?') sum++;
	puts(cnt&&sum>cnt/2?"NO":"YES");
	return 0;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%s",a+1);n=strlen(a+1),mian());
	return 0;
}
