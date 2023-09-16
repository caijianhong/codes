#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,m,P,cnt;
LL d[300010],f[300010];
void add(int x,LL k){
	if(x>n) return ;
	cnt-=!d[x];
	d[x]=(d[x]+k%P+P)%P;
	cnt+=!d[x];
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%d",&n,&m,&P);
	f[1]=1;for(int i=2;i<=n;i++) f[i]=(f[i-1]+f[i-2])%P;
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),d[i]=(d[i]-x+P)%P;
	for(int i=n;i>=1;i--) d[i]=(d[i]-d[i-1]-d[i-2]+P+P)%P,cnt+=!d[i];
	for(int i=1,l,r;i<=m;i++){
		char op;
		scanf(" %c%d%d",&op,&l,&r);
		int k=op=='A'?1:-1;
		add(l,k),add(r+1,-k*f[r-l+1]-k*f[r-l]),add(r+2,-k*f[r-l+1]);
		//  .......
		//---    ---
		//        --- 
		puts(cnt==n?"YES":"NO");
	}
	return 0;
}

