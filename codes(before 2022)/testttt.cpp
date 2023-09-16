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
int _[2000010],n,m;
void print(){
	int (&f)[n+1][m+1]=decltype(f)(_);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d%c",f[i][j]," \n"[j==m]);
		}
	}	
}
//void temprint(int &f){
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			printf("%d%c",f[i][j]," \n"[j==m]);
//		}
//	}
//}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	int (&f)[n+1][m+1]=decltype(f)(_);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=++cnt;
		}
	} 
	print();
//	temprint();
	return 0;
}

