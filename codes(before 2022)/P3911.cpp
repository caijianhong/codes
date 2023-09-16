#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int P=998244353,_2=499122177;
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
int n,c[1000010];
LL ans=0,f[1000010],sum;
siever<1000010> s;
LL calc(int t){
	LL res=0;
	for(int i=1;i<=1e6/t;i++) res=(res+1ll*c[i*t]*i)%P;
	return res;
} 
LL sid(int l,int r){
	return 1ll*(l+r)*(r-l+1)%P*_2%P;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(int i=1;i<=1e6;i++){
		for(int j=i;j<=1e6;j+=i){//i|j
			f[j]=(f[j]+1ll*i*(s.mu[i]+P))%P;
		}
	}
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),c[x]++,sum=(sum+x)%P;
	for(int i=1;i<=1e6;i++){
		LL res1=calc(i),res2=f[i];
		ans=(ans+1ll*i*res1%P*res1%P*res2)%P;
	}
	printf("%lld\n",(ans-sum+P)%P*_2%P);
	return 0;
}

