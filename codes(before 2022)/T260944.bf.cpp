#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
const ll p=998244353;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
ll n,m,a[N],tmp,l,r,res,ans=1;
int main()
{
	n=read(),m=read();
	for(ll i=1;i<=n;i++)
		a[i]=read();
	for(ll i=1;i<=m;i++)
	{
		l=read(),r=read();
		tmp=res=0;
		for(ll j=l;j<=r;j++)
		{
			tmp=max(tmp,a[j]);
			res=(res+tmp)%p;
		}
		ans=ans*res%p;
	}
	printf("%lld\n",ans);
	return 0;
}
