#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct mpam{
	int n,fail[N+10];
	void build(char *a){
		n=strlen(a+1),fail[0]=fail[1]=0;
		for(int i=2,j=0;i<=n;i++){
			while(j&&a[j+1]!=a[i]) j=fail[j];
			j+=a[j+1]==a[i];
			fail[i]=j;
		}
	}
};
int n,f[500010],t[500010];
char a[500010];
mpam<500010> kmp;
int dp(int s){
	for(int i=1;i<=n;i++){
		int p=kmp.fail[i];
		if(t[f[p]]>=i-p) f[i]=f[p];
		else f[i]=i;
		t[f[i]]=i;
	}
	return f[s];
} 
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s",a+1),n=strlen(a+1);
	kmp.build(a);
	printf("%d\n",dp(n));
	return 0;
}

