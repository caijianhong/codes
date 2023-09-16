#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int sqrN=1<<22;
template<int N> struct siever{
	int cnt,p[N+10],phi[N+10],mu[N+10];
	siever():cnt(0){
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
int n;
LL sphi[sqrN+10],smu[sqrN+10];
map<int,LL> mp; 
siever<sqrN> s;
LL solve1(int n){//phi*I=id
	if(n==1) return 1;
	if(n<=sqrN) return sphi[n];
	if(mp.find(n)!=mp.end()) return mp[n];
	LL ans=1ll*n*(n+1ll)/2ll;
	for(LL l=2,r;l<=n;l=r+1){
		r=n/(n/l); 
		ans-=solve1(n/l)*(r-l+1);
	}
	return mp[n]=ans;
}
LL solve2(int n){//mu*I=e
	if(n==1) return 1;
	if(n<=sqrN) return smu[n];
	if(mp.find(n)!=mp.end()) return mp[n];
	LL ans=1;
	for(LL l=2,r;l<=n;l=r+1){
		r=n/(n/l); 
		ans-=solve2(n/l)*(r-l+1);
	}
	return mp[n]=ans;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(int i=1;i<=sqrN;i++) sphi[i]=sphi[i-1]+s.phi[i];
	for(int i=1;i<=sqrN;i++) smu[i]=smu[i-1]+s.mu[i];
	for(	
		scanf("%*d");~scanf("%d",&n);
		mp.clear(),printf("%lld ",solve1(n)),
		mp.clear(),printf("%lld\n",solve2(n))
	);
	return 0;
}

