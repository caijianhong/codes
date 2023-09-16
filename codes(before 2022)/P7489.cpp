#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
inline char rc()
{
	static char buf[1048576],*pn=buf,*pe=buf;	
	return getchar();
//	return (pn==pe)&&(pe=(pn=buf)+fread(buf,1,1048576,stdin),pn==pe)?EOF:*pn++;
}
inline int read()
{
	int x=0;
	char cc=rc();
	while(cc<'0'||cc>'9')cc=rc();
	while(cc>='0'&&cc<='9')x=x*10+cc-'0',cc=rc();
	return x;
}
inline LL _read()
{
	LL x=0;
	char cc=rc();
	while(cc<'0'||cc>'9')cc=rc();
	while(cc>='0'&&cc<='9')x=x*10+cc-'0',cc=rc();
	return x;
}
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
LL qpow(LL a,LL b,int p){LL r=1;for(a%=p;b;b>>=1,a=a*a%p) if(b&1) r=r*a%p; return r;}
int n,P;
void red(LL&x){x=(x%P+P)%P;}
LL inv(LL a){return qpow(a,P-2,P);}
LL a[7000010],b[7000010],c[7000010],mul=1,ans,k,sum[7000010];
void linear_inv(LL a[],LL b[]){
	sum[0]=1;
	for(int i=1;i<=n;i++) red(sum[i]=sum[i-1]*a[i]);
	LL isum=inv(sum[n]),tot=1;
	for(int i=n;i>=1;i--){
		b[i]=sum[i-1]*tot%P*isum%P;
		red(tot*=a[i]);
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
//	scanf("%d%lld%d",&n,&k,&P),red(k);
	n=read(),k=_read(),P=read(),red(k); 
	for(int i=1;i<=n;i++){
//		scanf("%lld",&a[i]);
		a[i]=read();
		red(b[i]=a[i]*k+1);
	}
	int pos=min_element(b+1,b+n+1)-b;
	swap(a[pos],a[1]),swap(b[pos],b[1]);
	for(int i=1;i<=n;i++) debug("%lld/%lld\n",a[i],b[i]);
	if(!b[1]){
		ans=a[1],mul=1;
		for(int i=1;i<=n;i++) red(mul*=a[i]);
		for(int i=2;i<=n;i++) red(ans*=b[i]);
		printf("%lld\n",ans*inv(mul)%P);
	}else{
		linear_inv(b,c);
		ans=0,mul=inv(sum[n]);
		for(int i=1;i<=n;i++) red(ans+=a[i]*c[i]%P),red(mul*=a[i]);
//		for(int i=1;i<=n;i++) red(ans+=a[i]*inv(b[i])%P),red(mul*=a[i]*inv(b[i])%P);
		printf("%lld\n",ans*inv(mul)%P);
	}
	return 0;
}

