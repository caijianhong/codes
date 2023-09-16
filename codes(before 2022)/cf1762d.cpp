
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
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
int query(int x,int y,int d){
	printf("? %d %d\n",x,y),fflush(stdout);
	scanf("%d",&x); return x/d;
}
void report(int x,int y){
	printf("! %d %d\n",x,y);
	fflush(stdout),scanf("%*d");
}
void solve(vector<int> a,int d){
	static vector<int> g[20010];
	for(int i=1;i<=a.size();i++) g[i].clear();
	if(a.size()==2){
		report(a[0],a[1]);
		return ;
	}
	int tot=1;
	for(int x:a) if(x!=a[0]){
		int r=query(x,a[0],d);
		g[r].push_back(x);
		tot=tot/gcd(tot,r)*r;
	}
	bool flag=0;
	for(int i=1;i<=a.size();i++) if(g[i].size()>1) flag=1;
	if(!flag) return report(a[0],a[0]);
	vector<int> b;
	if(a.size()!=g[1].size()-1) b.push_back(a[0]);
	for(int x:g[tot]) b.push_back(x);
	solve(b,tot*d);
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%*d");
	while(~scanf("%d",&n)){
		vector<int> a(n);
		iota(a.begin(),a.end(),1);
		solve(a,1);
	}
	return 0;
}
