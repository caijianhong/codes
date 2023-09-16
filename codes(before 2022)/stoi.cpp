#include <cstdio>
#include <vector>
#include <cstring>
#include <random>
#include <string>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
int main(int argc,char**argv){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
mt19937 rng(stoi(argv[1]));
auto rnd=[&](int l,int r){return rng()%(r-l+1)+l;};
puts("20");
for(int i=1;i<=20;i++) printf("%d ",rnd(-10,10));
	return 0;
}

