#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef int LL;
LL qpow(LL a,LL b){LL ans=1;for(;b;b>>=1,a=a*a) if(b&1) ans=ans*a;return ans;}
int n,m,f[17];//2~16
LL a[100010],b[100010],s[100010];
void reset(int l,int r,LL v){
	for(int i=l;i<=r;i++) a[i]+=v;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
//	memset(f,0,sizeof f);
//	for(int i=1;i<=n;i++){
//		for(int j=2;j<=16;j++){
//			int pos=lower_bound(s,s+n+1,s[i]-b[j])-s;
//			f[j]=max(f[j],i-pos);
//		}
//	}
	for(int j=2;j<=16;j++){
		LL sum=0;f[j]=0;
		for(int L=1,R=0;L<=n;sum-=a[L++]){
			while(R<n&&sum+a[R+1]<=b[j]) sum+=a[++R];
			f[j]=max(f[j],R-L+1); 
		}
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=2;i<=16;i++) b[i]=qpow(i,i-1)-1;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	reset(0,0,0);
	for(int i=1,l,r,k;i<=m;i++){char op;
		if(scanf(" %c",&op),op=='A') scanf("%d%d%d",&l,&r,&k),reset(l,r,k);
		else scanf("%d",&k),printf("%d\n",k<=16?f[k]:n); 
	}
	return 0;
}
/*
5 5
1 2 3 4 5
Q 2
1
Q 3
3
A 1 3 2
Q 2
0
Q 3
2
*/

