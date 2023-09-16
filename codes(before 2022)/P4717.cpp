#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
const int P=998244353;
void red(LL&x){x=(x%P+P)%P;}
void fwt_or(LL *f,int n,int op){
	for(int len=2,k=1;len<=n;len<<=1,k<<=1)
		for(int i=0;i<n;i+=len)
			for(int j=0;j<k;j++)
				red(f[i+j+k]+=f[i+j]*op);
}
void fwt_and(LL *f,int n,int op){
	for(int len=2,k=1;len<=n;len<<=1,k<<=1)
		for(int i=0;i<n;i+=len)
			for(int j=0;j<k;j++)
				red(f[i+j]+=f[i+j+k]*op);
}
void fwt_xor(LL *f,int n,int op){
	for(int len=2,k=1;len<=n;len<<=1,k<<=1)
		for(int i=0;i<n;i+=len)
			for(int j=0;j<k;j++){
				LL ta=f[i+j],tb=f[i+j+k];
				red(f[i+j]=(ta+tb)*op);
				red(f[i+j+k]=(ta-tb)*op);
			}
}
void multiple(LL *a,LL *b,LL *c,int n){
	for(int i=0;i<n;i++) red(c[i]=a[i]*b[i]);
}
int n;
LL a[1<<17],b[1<<17],c[1<<17];
int main(){
//	#ifdef LOCAL
	 	freopen("input.in","r",stdin);
//	#endif
	rewind(stdin);
	scanf("%d",&n),n=1<<n;
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<n;i++) scanf("%lld",&b[i]);
	fwt_or(a,n,1),fwt_or(b,n,1),multiple(a,b,c,n),fwt_or(c,n,-1);
	for(int i=0;i<n;i++) printf("%lld%c",c[i]," \n"[i==n-1]);
	rewind(stdin);
	scanf("%d",&n),n=1<<n;
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<n;i++) scanf("%lld",&b[i]);
	fwt_and(a,n,1),fwt_and(b,n,1),multiple(a,b,c,n),fwt_and(c,n,-1);
	for(int i=0;i<n;i++) printf("%lld%c",c[i]," \n"[i==n-1]);
	rewind(stdin);
	scanf("%d",&n),n=1<<n;
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<n;i++) scanf("%lld",&b[i]);
	fwt_xor(a,n,1),fwt_xor(b,n,1),multiple(a,b,c,n),fwt_xor(c,n,499122177);
	for(int i=0;i<n;i++) printf("%lld%c",c[i]," \n"[i==n-1]);
	return 0;
}

