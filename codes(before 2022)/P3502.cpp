#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,int M,class T=LL> struct matrix{
    T a[N+10][M+10];
    matrix(T f=1e18){memset(a,0x3f,sizeof a);for(int i=1;i<=N;i++) a[i][i]=f;}
    T* operator[](int i){return a[i];}
};
template<int N,int M,int R,class T=LL> matrix<N,R,T> operator*(const matrix<N,M,T> &a,const matrix<M,R,T> &b){
    matrix<N,R,T> res=1e18;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=R;j++){
            for(int k=1;k<=M;k++){
                res[i][j]=min(res[i][j],a[i][k]+b[k][j]);
            }
        }
    }
    return res;
}
template<int N,class T> matrix<N,N,T> operator^(matrix<N,N,T> a,LL k){
    matrix<N,N,T> res=0;
    for(;k;k>>=1,a=a*a){
        if(k&1) res=res*a;
    }
    return res;
}
template<int N> struct mpam{
	int n,fail[N+10];char *a;
	void build(char *s){
		a=s,n=strlen(s+1),fail[0]=fail[1]=0;
		for(int i=2,j=0;i<=n;i++){
			while(j&&a[j+1]!=a[i]) j=fail[j];
			j+=a[j+1]==a[i];
			fail[i]=j;
		}
	}
	char& operator[](int i){return a[i];}
	int operator+(mpam &b){
		int j=0;
		for(int i=1;i<=n;i++){
			while(j&&b[j+1]!=a[i]) j=b.fail[j];
			j+=b[j+1]==a[i];
		}
		return b.n-j;
	} 
};
int n,m;
char a[210][100010];
mpam<100010> t[210];
matrix<1,210,LL> I;
matrix<210,210,LL> E;
LL ans=1e18;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1),t[i].build(a[i]); 
	for(int i=1;i<=n;i++) I[1][i]=t[i].n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) E[i][j]=t[i].n-t[i].fail[t[i].n];
			else E[i][j]=t[i]+t[j];
//			printf("E[%d][%d]=%lld\n",i,j,E[i][j]);
		}
	}
	I=I*(E^(m-1));
	for(int i=1;i<=n;i++) ans=min(ans,I[1][i]);
	printf("%lld\n",ans);
	return 0;
}
/*

*/
