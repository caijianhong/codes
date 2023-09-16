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
template<int N,class T=LL> struct fenwick{
	T c[N+10];
	T&operator[](int i){return c[i];}
	fenwick(){memset(c,0,sizeof c);}
	void add(T k,int p){for(;p<=N;p+=p&-p) c[p]+=k;}
	T query(int p){T r=0;for(;p>=1;p-=p&-p) r+=c[p]; return r;}
};
int n,m,buc[26];
char s[100010];
fenwick<100010,int> t[26];
bool solve(int l,int r){
	int minx=1e9,maxi=-1e9;
	for(int z=0;z<26;z++)
		if((buc[z]=t[z].query(r)-t[z].query(l-1))) minx=min(minx,z),maxi=max(maxi,z);
	for(int z=minx+1;z<maxi;z++) if(buc[z]!=t[z].query(n)) return 0;
	int now=l;
	for(int z=minx;z<=maxi;z++){
		if(t[z].query(now+buc[z]-1)-t[z].query(now-1)!=buc[z]) return 0;
		now+=buc[z];
	}
	return 1;
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++) t[s[i]-'a'].add(1,i);
	scanf("%d",&m);
	for(int i=1,op,l,r,x;i<=m;i++){
		char ch;
		scanf("%d",&op);
		if(op==1) scanf("%d %c",&x,&ch),t[s[x]-'a'].add(-1,x),s[x]=ch,t[s[x]-'a'].add(1,x);
		else scanf("%d%d",&l,&r),puts(solve(l,r)?"Yes":"No");
	}
	return 0;
}

