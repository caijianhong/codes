#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int q[100010];
template<int N> struct bag{
	int f[N+10];
	bag(){memset(f,~0x3f,sizeof f),f[0]=0;}
	void insert(bag<N> &pre,int w,int v,int c){
		memcpy(f,pre.f,sizeof f);
//		if(!c||v<=0||w>N) return ;
//		if(!w){for(int i=0;i<=N;i++) f[i]+=v;return ;}
		for(int u=0;u<w;u++){
			for(int i=u,L=1,R=0;i<=N;i+=w){
				while(L<=R&&q[L]<i-c*w) L++;
				if(L<=R) f[i]=max(f[i],pre[q[L]]+(i/w-q[L]/w)*v);
				while(L<=R&&pre[q[R]]-q[R]/w*v<=pre[i]-i/w*v) R--;
				q[++R]=i;
			}
		} 
	}
	int& operator[](int i){return f[i];}
};
int n,m;
bag<40010> f[110];
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,w,v,c;i<=n;i++) scanf("%d%d%d",&v,&w,&c),f[i].insert(f[i-1],w,v,c);
	printf("%d\n",*max_element(f[n].f+1,f[n].f+m+1));
	return 0;
}

