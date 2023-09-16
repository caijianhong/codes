#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long LL;
int main(int argc,char *argv[]){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	srand(stoi(argv[1])^time(0));
	printf("%d %d %d %d\n",3,3,3,rand()%3);
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				printf("%d\n",rand()%100);
			}
		}
	}
	return 0;
}

