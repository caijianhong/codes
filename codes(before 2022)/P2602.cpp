#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int dig[20];
LL f[20][2][2][20];
LL dfs(int n,bool done,bool _0,int d,int ans){//lim=0顶着上界，_0=0有前导0 
	if(!n) return ans;
	if(~f[n][done][_0][ans]) return f[n][done][_0][ans];
	LL res=0;
	for(int i=0;i<=(done?9:dig[n]);i++){
		res+=dfs(n-1,done||i<dig[n],_0||!!i,d,ans+(i==d&&(i||_0)));
	}
	return f[n][done][_0][ans]=res;
}
LL solve(LL n,int d){
	memset(f,-1,sizeof f);
	int len=0;
	for(;n;n/=10) dig[++len]=n%10;
	return dfs(len,0,0,d,0);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	LL L,R;
	scanf("%lld%lld",&L,&R);
	for(int i=0;i<=9;i++) printf("%lld ",solve(R,i)-solve(L-1,i));
	puts("");
	return 0;
}

