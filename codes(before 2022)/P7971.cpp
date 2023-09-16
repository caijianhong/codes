#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
template<int N> struct dsu{
	int fa[N+10],siz[N+10],cnt;
	dsu(int n=N):cnt(n){for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){
		if(x=find(x),y=find(y),x!=y){
			if(siz[x]<siz[y]) swap(x,y);
			cnt--,siz[x]+=siz[y],fa[y]=x;
		}
	}
};
int n,T,f[1010][1010],last[1010],p[1010];
dsu<1010> s;
int query(int l,int r){
	if(l>r) swap(l,r);
	if(f[l][r]==-1){
		printf("? %d %d\n",l,r);
		fflush(stdout);
		scanf("%d",&f[l][r]);
	}
	return f[l][r];
}
int flower(){
	int cnt=0;
	p[++cnt]=1;
	for(int i=2;i<=n;i++){
		if(query(p[cnt],i)==1) s.merge(p[cnt],i);
		else p[++cnt]=i;
	}
	return cnt;
}
int main(){
	memset(f,-1,sizeof f);
	scanf("%d%d%*d",&T,&n);
	if(T==1||T==2) flower();
	else if(query(1,n)==n-1){
		int L=1,R=n;
		while(query(n,L)==n-L) L++;
		while(query(R,1)==R-1) R--;
		s.merge(L-1,R+1);
	}else if(query(1,n)==3){
	    int cnt=flower();
	    if(query(p[1],p[3])==2) s.merge(p[1],p[3]);
		for(int i=4;i<=cnt;i++){
			if(query(p[i-2],p[i])==2) s.merge(p[i-2],p[i]);
			else{
				set<int> fs;
				for(int j=1;j<i;j++) fs.insert(s.find(p[j]));
				fs.erase(s.find(p[i-1]));
				fs.erase(s.find(p[i-2]));
				if(!fs.empty()) s.merge(*fs.begin(),p[i]);
			}
		}
	}else if(query(1,n)!=n){
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=1;j<=1000;j++) if(last[j]) p[++cnt]=last[j];
			sort(p+1,p+cnt+1);
			int L=1,R=cnt;
			while(L<R){
				int mid=(L+R+1)>>1;
				if(query(p[mid],i)==cnt-mid+1) L=mid;
				else R=mid-1;
			}
			if(query(1,n)==cnt||!cnt||query(p[L],i)==cnt-L+1) s.merge(p[L],i);
			last[s.find(i)]=i;
		}
	}
	printf("! ");
	for(int i=1;i<=n;i++) printf("%d%c",s.find(i)," \n"[i==n]);
	fflush(stdout);
	return 0;
}
/*
131231232233
*/
