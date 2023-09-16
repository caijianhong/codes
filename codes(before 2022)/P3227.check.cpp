#include <cstdio>
#include <cstring>
#include <algorithm>
#include <windows.h>
using namespace std;
typedef long long LL;
char s[100010];
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(int i=1;;i++){
		sprintf(s,"P3227.dp %d >P3227.in",i),system(s);
		system("P3227 <P3227.in >P3227.out");
		system("P3227.sol <P3227.in >P3227.ans");
		if(system("fc P3227.ans P3227.out")) system("pause");
	}
	return 0;
}

