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
int n,m,f[9][210][210],dis[210][210],cnt;
void floyed(int f[][210],int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
}
void add(int u,int v,int w){f[0][u][v]=dis[u][v]=min(f[0][u][v],w);}
void link(int u,int v,int w){add(u,v,w),add(v,u,w);}
void print(int f[][210],int u){
//	debug("u=%d\n",u);
//	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) debug("%d%c",f[i][j]," \n"[j==n]);
}
bool check(int u,int dep){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=u&&j!=u&&dis[i][j]!=f[dep][i][j]) return 1;
		}
	}
	return 0;
}
void cdq(int l,int r,int dep){
	if(l==r){
		print(f[dep-1],l);
		if(check(l,dep-1)) printf("%d ",l),cnt++;
		return ;
	}
	int mid=(l+r)>>1;
	memcpy(f[dep],f[dep-1],sizeof f[dep]);
	for(int i=mid+1;i<=r;i++) floyed(f[dep],i);
	debug("[%d,%d] left\n",l,r);
	print(f[dep],0);
	cdq(l,mid,dep+1);
	memcpy(f[dep],f[dep-1],sizeof f[dep]);
	for(int i=l;i<=mid;i++) floyed(f[dep],i);
	debug("[%d,%d] right\n",l,r);
	print(f[dep],0);
	cdq(mid+1,r,dep+1);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	memset(f,0x3f,sizeof f);
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) f[0][i][i]=dis[i][i]=0;
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),link(u,v,w);
	for(int i=1;i<=n;i++) floyed(dis,i);
	print(dis,0);
	print(f[0],0);
	cdq(1,n,1);
	if(!cnt) puts("No important cities.");
	return 0;
}

