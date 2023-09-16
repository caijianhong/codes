#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int P=998244353;
template<int N,class T=int,int logN=20> struct STable{
    int tot,lg[N+10];T f[logN+1][N+10];
    STable():tot(0){lg[0]=-1;for(int i=1;i<=N;i++) lg[i]=lg[i>>1]+1;}
    void insert(T x){f[0][++tot]=x;for(int j=0,i=tot-1;i>=1;i-=1<<++j) f[j+1][i]=max(f[j][i],f[j][i+(1<<j)]);}
    T query(int l,int r){int k=lg[r-l+1];return max(f[k][l],f[k][r-(1<<k)+1]);}
};
int n,a[300010];
LL f[300010];
STable<300010> t1,t2;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),t1.insert(a[i]),t2.insert(-a[i]);
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			f[i]=(f[i]+f[j]*(t1.query(j+1,i)+t2.query(j+1,i)%P+P)%P);
		}
	}
	printf("%lld\n",f[n]);
	return 0;
}

