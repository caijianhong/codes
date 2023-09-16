#include <cstdio>
#include <vector>
#include <cmath> 
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
double f[510][510];
int n,m,x[510],y[510];
double dist(int i,int j){
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
void floyed(double f[510][510],int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	memset(f,0x7f,sizeof f);
	debug("f[0][0]=%.12lf\n",f[0][0]);
	for(int i=1;i<=n;i++) f[i][i]=0;
	scanf("%d",&m);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d",&u,&v),f[u][v]=f[v][u]=dist(u,v);
	for(int i=1;i<=n;i++) floyed(f,i);
	int s,t;
	scanf("%d%d",&s,&t);
	printf("%.2lf\n",f[s][t]);
	return 0;
}

