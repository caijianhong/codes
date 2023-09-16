#include <cstdio>
#include <vector>
#include <cstring>
#include <numeric>
#include <algorithm>
using namespace std;
#ifdef LOCAL
#define debug(...) fprintf(stderr,##__VA_ARGS__)
#else
#define debug(...) void(0)
#endif
typedef long long LL;
const int P=1e9+7;
void red(LL&x){x=(x%P+P)%P;}
int n;
char buf[1000010];
vector<LL> append(vector<LL> f,int r){//假设 f.back() 是 f 的总和 
	LL sum=accumulate(f.begin(),f.end(),0ll)%P;
	vector<LL> g(27);
	for(int i=0;i<27;i++){
		red(g[i]=f[i]);
		if(i==r) red(g[i]=sum);
		red(g[i]+=f[i]);
	}
	return g;
}
void print(vector<LL>&f){
//	for(LL x:f) debug("%lld ",x);
//	puts("");
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s",buf+1),n=strlen(buf+1);
	vector<LL> f(27,0); f[26]=1;
	for(int i=1;i<=n;i++) f=append(f,buf[i]-'a'),print(f);
	printf("%lld\n",accumulate(f.begin(),prev(f.end()),0ll)%P);
	return 0;
}

