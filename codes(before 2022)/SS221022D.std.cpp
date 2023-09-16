#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define pii pair<int,int>
#define lowbit(x) ((x)&-(x))
#define popcount(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define umap unordered_map
#define all(x) x.begin(),x.end();
#define mk make_pair
#define ckmax(x,y) x=max(x,y)
#define ckmin(x,y) x=min(x,y)
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define N 300005
using namespace std;
inline int read(){
	int x=0,f=0; char ch=getchar();
	while(!isdigit(ch)) f|=(ch==45),ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
struct edge{
	int b,n;
}e[N*2];
int n,nxt[N],h[N],tot,rt[N];
char s[N];
inline void charu(int a,int b){
	e[++tot].b=b,e[tot].n=h[a],h[a]=tot;
}
struct node{
	int l,r,mx;
	node operator + (const node &B)const{
		node A=*this;
		if(A.mx==-1 && B.mx==-1) return A;
		if(A.mx==-1) return B;
		if(B.mx==-1) return A;
		return {A.l,B.r,max(max(A.mx,B.mx),B.l-A.r)};
	}
};
struct segmentTree{
	int ls,rs,lazy;
	node v;
}d[60*N];
int pool;
inline void pushdown(int k){
	if(!d[k].lazy) return;
	if(d[k].ls) d[d[k].ls].lazy+=d[k].lazy;
	if(d[k].rs) d[d[k].rs].lazy+=d[k].lazy;
	d[k].lazy=0;
}
void update(int &k,int l,int r,int x){
	if(!k) k=++pool,d[k].v.mx=-1;
	if(l==r){
		d[k].v.l=d[k].v.r=l;
		d[k].v.mx=0;
		return;
	}
	pushdown(k);
	int mid=l+r>>1;
	if(x<=mid) update(d[k].ls,l,mid,x);
	else update(d[k].rs,mid+1,r,x);
	d[k].v=d[d[k].ls].v+d[d[k].rs].v;
}
int merge(int x,int y,int l,int r){
	if(!x || !y) return x|y;
	if(l==r) return x;
	pushdown(x),pushdown(y);
	int mid=l+r>>1;
	d[x].ls=merge(d[x].ls,d[y].ls,l,mid);
	d[x].rs=merge(d[x].rs,d[y].rs,mid+1,r);
	d[x].v=d[d[x].ls].v+d[d[x].rs].v;
	return x;
}
void modify(int k,int l,int r,int x,int y){
	if(!k) return;
	if(x<=l && r<=y) return (void)((d[k].lazy)++);
	int mid=l+r>>1;
	if(x<=mid) modify(d[k].ls,l,mid,x,y);
	if(mid+1<=y) modify(d[k].rs,mid+1,r,x,y);
}
int binarySearch(int k,int l,int r,int v){
	if(l==r) return l;
	int mid=l+r>>1;
	if(!d[k].ls) return binarySearch(d[k].rs,mid+1,r,v);
	if(!d[k].rs) return binarySearch(d[k].ls,l,mid,v);
	if(max(d[d[k].ls].v.mx,d[d[k].rs].v.l-d[d[k].ls].v.r)>v) return binarySearch(d[k].ls,l,mid,v);
	return binarySearch(d[k].rs,mid+1,r,v);
}
void dfs(int u){
	if(!h[u]) update(rt[u],0,n,0);
	update(rt[u],0,n,u);
	for(int i=h[u];i;i=e[i].n){
		int v=e[i].b;
		dfs(v);
		rt[u]=merge(rt[u],rt[v],0,n);
	}
	modify(rt[u],0,n,u,binarySearch(rt[u],0,n,u));
}
void get(int k,int l,int r){
	if(l==r){
		if(l) printf("%d\n",d[k].lazy);
		return;
	}
	int mid=l+r>>1;
	get(d[k].ls,l,mid),get(d[k].rs,mid+1,r);
}
signed main(){
//	freopen("cover.in","r",stdin);
//	freopen("cover.out","w",stdout);
	d[0].v.mx=-1;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=2,j=0;i<=n;++i){
		while(j && s[j+1]!=s[i]) j=nxt[j];
		if(s[j+1]==s[i]) j++;
		nxt[i]=j;
	}
	for(int i=1;i<=n;++i) charu(nxt[i],i);
	dfs(0);
	get(rt[0],0,n);
	return 0;
}
