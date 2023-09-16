#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node;
int n,fail[100010],pa[100010],kmp[100010],fa[18][100010];
char a[100010],b[100010];
node mx[100010],ans;
void manacher(char *s){
	memset(pa,0,sizeof pa);
	s[0]='~';
	for(int i=1,mid=0,r=0;i<=n;i++){
		if(i<=r) pa[i]=min(pa[mid*2-i],r-i+1);
		while(s[i-pa[i]]==s[i+pa[i]]) pa[i]++;
		if(i+pa[i]>r) r=i+pa[mid=i]-1;
	}
}
void buildfail(char *s){
	fail[0]=fail[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[j+1]!=s[i]) j=fail[j];
		fail[i]=(j+=s[j+1]==s[i]);
	}
}
void match(char *s,char *t){
	for(int i=1,j=0;i<=n;i++){
		while(j&&t[j+1]!=s[i]) j=fail[j];
		kmp[i]=(j+=t[j+1]==s[i]);
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s",a+1),n=strlen(a+1);
	memcpy(b,a,sizeof b),reverse(b+1,b+n+1);
	manacher(a),buildfail(b),match(a,b);
	for(int i=1;i<=n;i++) mx[i]=max(mx[i-1],node(kmp[i],i));
	for(int i=1;i<=n;i++){
		fa[0][i]=fail[kmp[i]];
		for(int j=1;j<=17;j++) fa[j][i]=fa[j-1][fa[j-1][i]];
	}
	for(int i=1;i<=n;i++){
		int 
	}
	return 0;
}
