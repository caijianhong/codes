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
const int P=1e9+7; 
int n,k;
char s[510];
LL f[510][510],g[510][510],h[510][510],st[510][510];
LL F(int l,int r);
LL G(int l,int r);
LL H(int l,int r);
void red(LL&x){x=(x%P+P)%P;}
bool cmp(char a,char b){
	if(a=='?'||b=='?') return 1;
	return a==b;
}
void print(int l,int r){
	for(int i=l;i<=r;i++) debug("%c",s[i]);
	debug("\n");
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	memset(f,-1,sizeof f),memset(g,-1,sizeof g),memset(h,-1,sizeof h);
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++){
		st[i][i-1]=1;
		for(int j=i;j<=n;j++) st[i][j]=st[i][j-1]&&cmp(s[j],'*')&&j-i+1<=k;
	}
	debug("%s\n",s+1);
	for(int i=1;i<=n;i++) debug("%d",i);
	debug("\n");
	printf("%lld\n",F(1,n));
	return 0;
}
LL H(int l,int r){//f 左边接正整数个星号 
	if(l>r) return 0;
	if(l==r) return 0;
	LL &res=h[l][r]; if(~res) return res;
	res=0;
	for(int k=l;k<r;k++){
		if(!st[l][k]) break;
		red(res+=F(k+1,r));
	}
	debug("h[%d][%d]=%lld ",l,r,h[l][r]),print(l,r);
	return res;
}
LL F(int l,int r){
//	debug("call f(%d,%d)\n",l,r);
	if(l>r) return 1;
	if(l==r) return 0;
	LL &res=f[l][r]; if(~res) return res;
	res=0;
	for(int k=l;k<r;k++){
		LL glk=G(l,k),tot=0;
//		for(int p=k;p<r&&glk;p++){
//			if(!st[k+1][p]) break;
//			red(tot+=F(p+1,r));
//		}
		red(tot=F(k+1,r)+H(k+1,r));
		red(res+=tot*glk);
	}
	red(res+=G(l,r));
	debug("f[%d][%d]=%lld ",l,r,f[l][r]),print(l,r);
	return res;
}
LL G(int l,int r){
//	debug("call g(%d,%d)\n",l,r);
	if(!cmp(s[l],'(')||!cmp(s[r],')')) return 0;
	if(l>=r) return 0;
	LL &res=g[l][r]; if(~res) return res;
	l++,r--,res=F(l,r);
	if(l<=r){
		for(int k=l;k<=r;k++) red(res+=st[l][k]*F(k+1,r));
		for(int k=l;k<=r;k++) red(res+=st[k][r]*F(l,k-1));
		red(res-=st[l][r]);
	}
	debug("g[%d][%d]=%lld ",l-1,r+1,res),print(l-1,r+1);
	return res;
}

