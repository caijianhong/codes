#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<bitset>
#include<complex>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
using namespace std;
typedef long long ll;
inline long long read()
{
    long long tmptmp=0,f=1;
    char tt=getchar();
    while (!isdigit(tt))
    {
        if (tt=='-') f=-1;
        tt=getchar();
    }
    while (isdigit(tt)) tmptmp=(tmptmp<<1)+(tmptmp<<3)-'0'+tt,tt=getchar();
    return tmptmp*f;
}
inline void write(long long numnum)
{
	static char buf[40];
	static int len=-1;
	if (numnum>=0)
		do
		{
			buf[++len]=numnum%10+48,numnum/=10;
		} while(numnum);
	else
	{
		putchar('-');
		do
		{
			buf[++len]=-(numnum%10)+48,numnum/=10;
		} while(numnum);
	}
	while (len>=0)
		putchar(buf[len--]);
}
inline void write(long long numnum,char cccc)
{
	static char buf[40];
	static int len=-1;
	if (numnum>=0)
		do
		{
			buf[++len]=numnum%10+48,numnum/=10;
		} while(numnum);
	else
	{
		putchar('-');
		do
		{
			buf[++len]=-(numnum%10)+48,numnum/=10;
		} while(numnum);
	}
	while (len>=0)
		putchar(buf[len--]);
	putchar(cccc);
}
ll gcd(ll a,ll b)
{
	return (b==0?a:gcd(b,a%b));
}
inline ll qpow(ll a,ll b,ll p)
{
	ll ans=1;
	while (b)
	{
		if (b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if (b==0)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
char s[500005];
ll n,kmp[20][500005],f[500005],lst[500005],ans[500005],nxt[500005];
int main()
{
//	freopen("cover.in","r",stdin);
//	freopen("cover.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=2,j=0;i<=n;++i)
	{
		while (j && s[j+1]!=s[i])
			j=kmp[0][j];
		if (s[j+1]==s[i])
			++j;
		kmp[0][i]=j;
	}
	memcpy(nxt,kmp[0],sizeof(nxt));
	for (int i=2;i<=n;++i)
		if (i-kmp[0][i]>kmp[0][i] && kmp[0][i] && kmp[0][i-kmp[0][i]])
			nxt[i]=min(nxt[i],nxt[i-kmp[0][i]]);
	for (int i=1;i<=n;++i)
	{
		f[i]=i;
		ans[i]=1;
		if (i==40)
		{
//			puts("nice");
		}
		ll p=nxt[i],q=kmp[0][i];
		if (lst[f[q]]>=i-f[q])
		{
			f[i]=f[q];
			ans[i]+=ans[p];
		}
		lst[f[i]]=i;
		write(ans[i],'\n');
	}
	return 0;
}
/*
ababa/aba/ababa/aba/ababa/
ababaabaababaabaababa

*/
