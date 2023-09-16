#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
void kmp(char *s,int fail[]){
	int n=strlen(s+1); fail[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[j+1]!=s[i]) j=fail[j];
		j+=s[j+1]==s[i];
		fail[i]=j;
	}
}
int n,f[500010],las[500010],fail[500010];
char s[500010];
int dp(){
	for(int i=1;i<=n;i++){
		f[i]=i;
		if(las[f[fail[i]]]>=i-fail[i]) f[i]=f[fail[i]];
		las[f[i]]=i;
	}
	return f[n];
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s",s+1),n=strlen(s+1),kmp(s,fail),printf("%d\n",dp());
	return 0;
}

