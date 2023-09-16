#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int popcount(int x){return (x&1)+(x>>1&1)+(x>>2&1)+(x>>3&1);}
const int P=5557; 
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<int N,int M,class T=LL> struct matrix{
	T a[N+3][M+3];
	matrix(bool f=0){
		memset(a,0,sizeof a);
		if(f) for(int i=1;i<=N;i++) a[i][i]=1;
	}
	T* operator[](int i){return a[i];}
	void print(int n,int m){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d%c",a[i][j]," \n"[j==m]);
			}
		}	
	}
};
template<int N,int M,int R,class T=LL> matrix<N,R,T> operator*(matrix<N,M,T> a,matrix<M,R,T> b){
	matrix<N,R,T> c=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=R;j++){
			for(int k=1;k<=M;k++){
				c[i][j]+=a[i][k]*b[k][j];
			}
			c[i][j]%=P;
		}
	}
	return c;
}
template<int N,class T=LL> matrix<N,N,T> operator^(matrix<N,N,T> a,LL b){
	matrix<N,N,T> ans=1;
	for(;b;b>>=1,a=a*a) if(b&1) ans=ans*a;
	return ans;
}
int n,m,t,tb[128];
char buf[110];
graph<30,510,int> g;
matrix<60,60,int> o;
matrix<1,60,int> e;
int has(char *s){int res=0;for(int i=1,len=strlen(s+1);i<=len;i++) res+=tb[s[i]];return res;}
void binprt(int x){for(int i=3;i>=0;i--) putchar((x>>i&1)+'0');}
int solve(int sta){
	o=0,e=0;
	e[1][1]=1,o[n*2+1][n*2+1]=o[n+1][n*2+1]=1;//e={0,1}
	for(int i=1;i<=n;i++) o[i+n][i]=1;
	for(int i=1;i<=g.cnt;i++){
		//(u,v)=>f[n][u]=f[n-1][v]+f[n-2][v]
		int u=g[i].u,v=g[i].v;
		o[u+n][v+n]++;
		if(u==1) e[1][v+n]++;
		if((~sta&g[i].w)==0) o[u][v+n]++;
	}
	return (e*(o^t))[1][n*2+1];
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	tb['B']=1,tb['J']=2,tb['M']=4,tb['P']=8;
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++) scanf("%d%d%s",&u,&v,buf+1),g.add(u,v,has(buf));
	scanf("%d",&t);
	int all=solve(15),res=0;
	for(int i=1;i<=15;i++) res+=solve(15-i)*(popcount(i)&1?1:-1);//,printf("ban=%d,ans%c=%d\n",i,"-+"[popcount(i)&1],solve(15-i));
//	printf("all=%d,res=%d\n",all,res);
	printf("%d\n",((all-res)%P+P)%P);
	return 0;
}
/*
1011=>0100
	  1010=>0101
t in s=> ~s&t==0
