#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int dig[20];
LL f[20][2][2][2][11][11][2];
LL dfs(int n,bool done,bool _0,bool _4,bool _8,int pre1,int pre2,bool ok){
	if(!n) return ok&&!(_4&&_8);
	if(done&&~f[n][_0][_4][_8][pre1][pre2][ok]) return f[n][_0][_4][_8][pre1][pre2][ok];
	LL res=0;
	for(int i=0;i<=(done?9:dig[n]);i++){
		res+=dfs(n-1,done||i<dig[n],_0||!!i,_4||i==4,_8||i==8,pre2,i,ok||(pre1==pre2&&pre2==i&&(_0||i)));
	}
	return done?f[n][_0][_4][_8][pre1][pre2][ok]=res:res;
}
LL solve(LL n){
	int len=0;
	for(;n;n/=10) dig[++len]=n%10;
	return dfs(len,0,0,0,0,10,10,0);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	LL L,R;
	memset(f,-1,sizeof f);
	scanf("%lld%lld",&L,&R);
	printf("%lld\n",solve(R)-solve(L-1));
	return 0;
}

