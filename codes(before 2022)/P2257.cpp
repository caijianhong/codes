#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
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
int n,m;
LL f[10000010];
siever<10000010> s;
LL calc(int n,int m){
	LL res=0;
	for(int l=1,r;l<=min(n,m);l=r+1){
		r=min(n/(n/l),m/(m/l));
		res+=1ll*(n/l)*(m/l)*(f[r]-f[l-1]);
	}
	return res;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(int i=1;i<=s.cnt;i++){
		for(int j=s.p[i];j<=1e7;j+=s.p[i]){
			f[j]+=s.mu[j/s.p[i]];
		}
	}
	for(int i=1;i<=1e7;i++) f[i]+=f[i-1];
	for(scanf("%*d");~scanf("%d%d",&n,&m);printf("%lld\n",calc(n,m)));
	return 0;
}

