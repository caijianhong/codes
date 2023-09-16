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
int n,m;
char a[1000010],b[1000010];
mpam<1000010> t;
void match(){
	for(int i=1,j=0;i<=n;i++){
		while(j&&b[j+1]!=a[i]) j=t.fail[j];
		j+=b[j+1]==a[i];
		if(j==m) printf("%d\n",i-m+1);
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s%s",a+1,b+1),n=strlen(a+1),m=strlen(b+1);
	t.build(b),match();
	for(int i=1;i<=m;i++) printf("%d%c",t.fail[i]," \n"[i==m]);
	return 0;
}

