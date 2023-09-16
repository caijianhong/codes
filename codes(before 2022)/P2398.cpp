#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct siever{
	int cnt,p[N+10],phi[N+10],mu[N+10];
	sieve():cnt(0){
		memset(p,phi[1]=mu[1]=1,sizeof p),p[1]=0;
		for(int i=1;i<=N;i++){
			if(p[i]) p[++cnt]=i,phi[i]=i-1,mu[i]=-1;
			for(int j=1;j<=cnt&&p[j]*i<=N;j++){
				p[p[j]*i]=0;
				if(i%p[j]==0){phi[p[j]*i]=p[j]*phi[i],mu[p[j]*i]=0;break;}
				else phi[p[j]*i]=phi[p[j]]*phi[i],mu[p[j]*i]=-mu[i];
			}
		}
	}
}; 
template<int N> struct summy{
	LL s[N+10];
	void build(int a[]){s[0]=0;for(int i=1;i<=N;i++) s[i]=s[i-1]+a[i];}
	LL operator()(int l,int r){return s[r]-s[l-1];}
};
int n,m;
LL ans;
siever<1000010> s; 
summy<1000010> sphi;
LL sid(int l,int r){return (l+r)*(r-l+1)/2;}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	sphi.build(s.phi);
	scanf("%d%d",&n,&m);
	for(int l=1,r;l<=min(n,m);l=r+1) r=min(n/(n/l),m/(m/l)),ans+=1ll*(n/l)*(m/l)*sphi(l,r);
	printf("%lld\n",ans*2-1ll*n*m);
	return 0;
}

