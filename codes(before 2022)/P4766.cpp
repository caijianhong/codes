#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct flower{
    int b[N+10],cnt;
    flower():cnt(0){}
    void operator+=(int x){b[++cnt]=x;}
    void build(){sort(b+1,b+cnt+1),cnt=unique(b+1,b+cnt+1)-b-1;}
    int operator()(int x){return lower_bound(b+1,b+cnt+1,x)-b;}
    int operator[](int i){return b[i];}
};
struct node{
	int l,r,d;
	node(int l=0,int r=0,int d=0):l(l),r(r),d(d){}
	bool operator<(node b){return d>b.d;}
};
int n,f[610][610];
node a[310];
flower<610> b; 
node search(int l,int r){
	for(int i=1;i<=n;i++){
		if(l<=a[i].l&&a[i].r<=r) return a[i];
	}
	return node(-1);
}
int dp(){
	memset(f,0,sizeof f);
	for(int t=1;t<=b.cnt;t++){
		for(int l=1,r=t;r<=b.cnt;l++,r++){
			node x=search(l,r);
//			printf("[%d,%d] found (%d,%d)=%d\n",l,r,x.l,x.r,x.d);
			if(x.l==-1) continue;
			f[l][r]=1e9;
			for(int k=x.l;k<=x.r;k++){
				f[l][r]=min(f[l][r],f[l][k-1]+x.d+f[k+1][r]);
			}
		}
	}
	return f[1][b.cnt];
} 
int mian(){
	b.cnt=0;
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].d),b+=a[i].l,b+=a[i].r;
	sort(a+1,a+n+1),b.build();
	for(int i=1;i<=n;i++) a[i].l=b(a[i].l),a[i].r=b(a[i].r);//,printf("(%d,%d)=%d\n",a[i].l,a[i].r,a[i].d);
	printf("%d\n",dp());
	return 0;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d",&n);mian());
	return 0;
}

