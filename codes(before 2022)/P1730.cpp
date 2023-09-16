#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
int n,m,g[60][60],f[60][60][60];
void dp(){
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[0][i][i]=0;
	for(int t=1;t<=n;t++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				for(int k=1;k<=n;k++){
					f[t][u][v]=min(f[t][u][v],f[t-1][u][k]+g[k][v]);
				}
				debug("f[%d][%d][%d]=%d\n",t,u,v,f[t][u][v]);
			}
		}
	}
}
double query(int u,int v){
	double res=1e9;
	for(int i=1;i<=n;i++) if(debug("f[%d][%d][%d]=%d\n",i,u,v,f[i][u][v]),f[i][u][v]<1e9) res=min(res,f[i][u][v]*1.0/i);
	return res;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	memset(g,0x3f,sizeof g);
//	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),g[u][v]=min(g[u][v],w);
	scanf("%*d"),dp();
	for(int u,v;~scanf("%d%d",&u,&v);){
		double res=query(u,v);
		if(res==1e9) puts("OMG!");
		else printf("%.3lf\n",res);
	}
	return 0;
}

