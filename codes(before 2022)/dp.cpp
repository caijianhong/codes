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
char s[100010];
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	debug("P5369 Running...\n");
	for(int i=1;;i++){
		debug("Test %d is running...\n",i);
		sprintf(s,"stoi.exe %d >input.in",i),system(s);
		system("P5369.exe <input.in >output.out");
		system("P5369.std.exe <input.in >answer.ans");
		if(system("fc answer.ans output.out")) system("pause");
	}
	return 0;
}

