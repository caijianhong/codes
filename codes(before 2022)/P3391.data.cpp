#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n=10,m=5;
int main(){
	#ifdef LOCAL
	 	freopen("data/input.in","w",stdout);
	#endif
	srand(time(0));
	printf("10 5\n");
	for(int i=1;i<=5;i++){
		int l=rand()%n+1,r=rand()%n+1;
		if(l>r) swap(l,r);
		printf("%d %d\n",l,r); 
	}
	return 0;
}

