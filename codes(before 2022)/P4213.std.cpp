// This code wrote by chtholly_micromaker(MicroMaker)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define reg register
#define int long long
using namespace std;
const int MaxN=3000050;
template <class t> inline void read(t &s)
{
	s=0;
	reg int f=1;
	reg char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
		s=(s<<3)+(s<<1)+(c^48),c=getchar();
	s*=f;
	return;
}
// bitset<MaxN> isp;
bool isp[MaxN];
int pr[MaxN],prn;
int phi[MaxN],mu[MaxN];
map<int,int> dp;
inline void Init(int n)
{
	phi[1]=mu[1]=1;
	for(int i=2;i<=n;++i)
	{
		// if(!isp.test(i))
		if(!isp[i])
		{
			pr[++prn]=i;
			phi[i]=i-1;
			mu[i]=-1;
		}
		for(int j=1;j<=prn&&i*pr[j]<=n;++j)
		{
			// isp.set(i*pr[j],1);
			reg int t=i*pr[j];
			isp[t]=true;
			if(i%pr[j])
			{
				phi[t]=phi[i]*(pr[j]-1);
				mu[t]=mu[i]*(-1);
			}
			else
			{
				phi[t]=phi[i]*pr[j];
				mu[t]=0;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i)
		phi[i]+=phi[i-1],mu[i]+=mu[i-1];
	return;
}
inline int calcphi(int n)
{
	if(n<=3000000)
		return phi[n];
	if(dp.find(n)!=dp.end())
		return dp[n];
	reg int ans=0;
	for(reg int l=2,r;l<=n;l=r+1)
	{
		r=n/(n/l);
		ans+=(r-l+1)*calcphi(n/l);
	}
	ans=n*(n+1)/2-ans;
	dp[n]=ans;
	return ans;
}
inline int calcmu(int n)
{
	if(n<=3000000)
		return mu[n];
	if(dp.find(n)!=dp.end())
		return dp[n];
	reg int ans=0;
	for(reg int l=2,r;l<=n;l=r+1)
	{
		r=n/(n/l);
		ans+=(r-l+1)*calcmu(n/l);
	}
	dp[n]=1-ans;
	return 1-ans;
}
inline void work()
{
	int n;cin>>n;
	dp.clear();
	reg int ansphi=calcphi(n);
	dp.clear();
	reg int ansmu=calcmu(n);
	printf("%lld %lld\n",ansphi,ansmu);
	return;
}
signed main(void)
{
	Init(3000000);
	int t;cin>>t;
	while(t--)
		work();
	return 0;
}
