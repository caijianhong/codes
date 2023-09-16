#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,m,k,g[17][17];
LL f[17][1<<15],h[17][1<<15],ans=1e18,ansh=1;
int lowbit(int x){return x&-x;}
int getbit(int k){return 1<<(k-1);}
int conbit(int x,int k){return x&getbit(k);}
int popcount(int x){return __builtin_popcount(x);}
LL dfs(int u,int S){
	assert(conbit(S,u));
	if(S==lowbit(S)) return h[u][S]=1,f[u][S]=0;
	if(~f[u][S]) return f[u][S];
	LL ans=1e18,ansh=1;
	for(int v=1;v<=n;v++){
		for(int T=(S-1)&S;T;T=(T-1)&S){
			if(!conbit(T,u)&&conbit(S,v)&&conbit(T,v)&&u!=v){
				LL res=dfs(u,S^T)
					+dfs(v,T)
					+g[u][v]*popcount(T)
					+((S^T)!=getbit(u))*k
					+(S==getbit(n+1)-1&&(S^T)==getbit(u))*k;
				LL resh=h[u][S^T]*h[v][T];
				if(ans>res) ans=res,ansh=resh;
				else if(ans==res) ansh+=resh;
			}
		}
	}
	return h[u][S]=(ansh+1)/2,f[u][S]=ans;
}
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	memset(g,0x3f,sizeof g);
	memset(f,-1,sizeof f);
	for(int i=1,u,v,w;i<=m;i++) scanf("%d%d%d",&u,&v,&w),g[u][v]=g[v][u]=w;
	for(int i=1;i<=n;i++){
		LL res=dfs(i,getbit(n+1)-1)+k,resh=h[i][getbit(n+1)-1];
		if(ans>res) ans=res,ansh=resh;
		else if(ans==res) ansh+=resh;
	}
	printf("%lld %lld\n",ans,ansh);
	return 0;
}
