#include<bits/stdc++.h>
#define ll long long
#define p1 998244353
#define p2 1000000007
using namespace std;
#define N 500005
ll n,k,i,tot,ch[N*35][2],sz[N*35];
ll s[N],ans;
void insert(ll p,ll pre,ll v){
	for(int i=32;i>=0;i--){
		ch[p][((v>>i)&1)^1]=ch[pre][((v>>i)&1)^1];
		ch[p][(v>>i)&1]=++tot;
		p=ch[p][(v>>i)&1];
		pre=ch[pre][(v>>i)&1];
	}
	sz[p]=1;
	return;
}
ll dfs(ll x){
	if(!x) return 0;
	return sz[x]=sz[x]?sz[x]:(dfs(ch[x][0])+dfs(ch[x][1]));
}
struct node{
	ll x,k;
	ll y;
}u,v;
bool operator <(node a,node b){
	return a.y<b.y;
}
priority_queue<node> q;
ll fd(ll s,ll p,ll k){
	ll sum=0;
	for(int i=32;i>=0;i--)
	if(sz[ch[p][((s>>i)&1)^1]]>=k){
		sum+=(1ll<<i);
		p=ch[p][((s>>i)&1)^1];
	}
	else{
		k-=sz[ch[p][((s>>i)&1)^1]];
		p=ch[p][(s>>i)&1];
	}
	return sum;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	tot=n+1;
	insert(1,0,0);
	for(i=2;i<=n+1;i++){
		scanf("%lld",&s[i]);
		s[i]^=s[i-1];
		insert(i,i-1,s[i]);
	}
	u.k=1;
	for(i=1;i<=n+1;i++){
		dfs(i);
		u.x=i;
		u.y=fd(s[i],i,1);
		q.push(u);
	}
	for(i=1;i<=k;i++){
		u=q.top();
		q.pop();
		ans+=u.y;
		v.x=u.x;
		v.k=u.k+1;
		v.y=fd(s[v.x],v.x,v.k);
		q.push(v);
	}
	printf("%lld",ans);
	return 0;
}
