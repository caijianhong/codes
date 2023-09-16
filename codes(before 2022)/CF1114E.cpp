#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long LL;
int n,cnt,a[1000010],tot; 
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int query(int x){
	cnt++;
	printf("> %d\n",x),fflush(stdout);
	int res=0;
	scanf("%d",&res);
	return res;
} 
int get(){
	cnt++;
	printf("? %d\n",(rand()<<15|rand())%n+1),fflush(stdout);
	int res=0;
	scanf("%d",&res);
	return res;
}
int binary(int L,int R){
	int ans=-1;
	while(L<=R){
		int mid=(L+R)>>1;
		if(query(mid)) ans=mid,L=mid+1;
		else R=mid-1;
	}
	return ans+1;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	a[tot=1]=binary(0,1e9);
	for(;cnt<60;) a[++tot]=get();
	sort(a+1,a+tot+1);
	int d=a[2]-a[1];
	for(int i=1;i<tot;i++) d=gcd(d,a[i+1]-a[i]);
	printf("! %d %d\n",a[tot]-(n-1)*d,d);
	return 0;
}

