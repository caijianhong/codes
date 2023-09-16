#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,class T=int,int logN=20> struct STable{
	int tot,lg[N+10];T f[logN+1][N+10];
	STable():tot(0){lg[0]=-1;for(int i=1;i<=N;i++) lg[i]=lg[i>>1]+1;}
	void insert(T x){f[0][++tot]=x;for(int j=0,i=tot-1;i>=1;i-=1<<++j) f[j+1][i]=min(f[j][i],f[j][i+(1<<j)]);}
	T query(int l,int r){int k=lg[r-l+1];return min(f[k][l],f[k][r-(1<<k)+1]);}
};
int n,m;
STable<100010> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),t.insert(-x);
	for(int i=1,l,r;i<=m;i++) scanf("%d%d",&l,&r),printf("%d\n",-t.query(l,r));
	return 0;
}

