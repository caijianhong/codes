#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int P=20101009;
template<int N> struct siever{
	int cnt,p[N+10],phi[N+10],mu[N+10],g[N+10];
	siever():cnt(0){
		memset(p,phi[1]=mu[1]=g[1]=1,sizeof p),p[1]=0;
		for(int i=1;i<=N;i++){
			if(p[i]) p[++cnt]=i,phi[i]=i-1,mu[i]=-1,g[i]=(1-i+P)%P;
			for(int j=1;j<=cnt&&p[j]*i<=N;j++){
				p[p[j]*i]=0;
				if(i%p[j]==0){phi[p[j]*i]=p[j]*phi[i],mu[p[j]*i]=0,g[p[j]*i]=g[i];break;}
				else phi[p[j]*i]=phi[p[j]]*phi[i],mu[p[j]*i]=-mu[i],g[p[j]*i]=1ll*g[p[j]]*g[i]%P;
			}
		}
	}
}; 
int n,m;
LL ans=0;
siever<10000010> s;
LL sid(int l,int r){return 1ll*(l+r)*(r-l+1)%P*10050505%P;}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	if(n<m) swap(n,m);
	for(int i=1;i<=n;i++) ans=(ans+1ll*i*s.g[i]%P*sid(1,m/i)%P*sid(1,n/i)%P)%P; 
	printf("%lld\n",(ans%P+P)%P);
	return 0;
}

