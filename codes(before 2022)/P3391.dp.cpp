#include <cstdio>
#include <cstring>
#include <algorithm>
#include <windows.h>
using namespace std;
typedef long long LL;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(int i=1;;i++){
		fprintf(stderr,"Test %d:\n",i);
		system("P3391.data");
		system("P3391.fhqtreap > data/P3391.out");
		system("P3391.std > data/P3391.ans"); 
		if(system("fc data/P3391.out data/P3391.ans")) system("pause");
	}
	return 0;
}

