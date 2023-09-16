#include <queue>
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
int n;
int query(int x,int y){
	return printf("? %d %d\n",x+1,y+1),fflush(stdout),scanf("%d",&x),x;
}
void report(int x,int y){
	printf("! %d %d\n",x+1,y+1),fflush(stdout),scanf("%*d");
}
int mian(){
	vector<int> a(n);
	iota(a.begin(),a.end(),0);
	while(a.size()>=3){
		int x=a.back(); a.pop_back();
		int y=a.back(); a.pop_back();
		int z=a.back(); a.pop_back();
		int q1=query(x,y),q2=query(x,z);
		if(q1==q2) a.push_back(y),a.push_back(z);
		else if(q1>q2) a.push_back(x),a.push_back(y);
		else a.push_back(x),a.push_back(z);
	}
	report(a[0],a[1]);
	return 0;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	for(scanf("%*d");~scanf("%d",&n);mian());
	return 0;
}
