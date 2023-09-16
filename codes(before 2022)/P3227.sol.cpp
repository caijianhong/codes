#include<cstring>
#include<cstdio>
#include<iostream>
#define N 64005
using namespace std;
int dx[]={0, 1, 0, -1}, dy[]={1, 0, -1, 0};
int n, m, k, s, t, u, v, w, head, tail, tot=1, ans, h[N], p[N], q[N], vis[N], dep[N];
struct AB{
	int v, w, nxt;
}e[N*10];
void add(int u, int v, int w){
	e[++tot].v=v, e[tot].w=w;
	e[tot].nxt=p[u], p[u]=tot;
}
int bfs(){
	memset(dep, 0, sizeof(dep));
	memset(vis, 0, sizeof(vis));
	memcpy(h, p, sizeof(h));
	dep[s]=1, q[head=tail=1]=s;
	while(head<=tail){
		u=q[head++];
		for(int i=h[u]; i; i=e[i].nxt){
			v=e[i].v, w=e[i].w;
			if(!dep[v] && w>0) dep[v]=dep[u]+1, q[++tail]=v;
		}
	}
	return dep[t];
}
int dfs(int u, int f){
	if(u==t) return f;
	int tmp=f;
	for(int &i=h[u]; i; i=e[i].nxt){
		int v=e[i].v, w=min(tmp, e[i].w), s;
		if(w<=0 || dep[v]!=dep[u]+1 || vis[v]) continue;
		s=dfs(v, w);
		if(!s) vis[v]=1;
		e[i].w-=s, e[i^1].w+=s, tmp-=s;
		if(!tmp) break;
	}
	return f-tmp;
}
int main(){
	scanf("%d%d%d%d", &n, &m, &k, &u);
	s=n*m*(k-1)+1, t=s+1;
	for(int x=0; x<n; x++){
		for(int y=0; y<m; y++){
			for(int j=0; j<4; j++){
				int nx=x+dx[j], ny=y+dy[j];
				if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
				for(int i=u+1; i<k; i++){
					add(x*m*(k-1)+y*(k-1)+i, nx*m*(k-1)+ny*(k-1)+i-u, 1e7);
					add(nx*m*(k-1)+ny*(k-1)+i-u, x*m*(k-1)+y*(k-1)+i, 0);
				}
			}
		}
	}
	for(int i=1; i<=k; i++){
		for(int x=0; x<n; x++){
			for(int y=0; y<m; y++){
				scanf("%d", &w);
				v=x*m*(k-1)+y*(k-1)+i, u=v-1;
				if(i==1) u=s;
				if(i==k) v=t;
				add(u, v, w), add(v, u, 0);
			}
		}
	}
	while(bfs()){
		while(w=dfs(s, 1e9)) ans+=w;
	}
	printf("%d", ans);
	return 0;
}
