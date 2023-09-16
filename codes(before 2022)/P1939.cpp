#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int P=1e9+7;
template<int N,int M,class T=LL> struct matrix{
	T a[N+3][M+3];
	matrix(bool f=0){
		memset(a,0,sizeof a);
		if(f) for(int i=1;i<=N;i++) a[i][i]=1;
	}
	T* operator[](int i){return a[i];}
};
template<int N,int M,int R,class T=LL> matrix<N,R,T> operator*(matrix<N,M,T> a,matrix<M,R,T> b){
	matrix<N,R> c=0;
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
int n;
matrix<1,3> e;
matrix<3,3> o;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	e[1][1]=e[1][2]=e[1][3]=1;
	o[2][1]=o[3][2]=o[1][3]=o[3][3]=1;
	for(scanf("%*d");~scanf("%d",&n);printf("%lld\n",(e*(o^n-1))[1][1]));
	return 0;
}

