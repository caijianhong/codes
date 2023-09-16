#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct leftistree{
	int tot,ch[N+10][2],val[N+10],dis[N+10],fa[N+10];
	leftistree():tot(0){dis[0]=-1;}
	int newnode(int v){int p=++tot;return ch[p][0]=ch[p][1]=0,val[p]=v,dis[p]=0,fa[p]=p;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	int merge(int p,int q){
		if(!p||!q) return p+q;
		if(val[p]==val[q]?p>q:val[p]>val[q]) swap(p,q);
		ch[p][1]=merge(ch[p][1],q);
		if(dis[ch[p][0]]<dis[ch[p][1]]) swap(ch[p][0],ch[p][1]);
		dis[p]=dis[ch[p][1]]+1;
		return p;
	}
	void _merge(int p,int q){if(p=find(p),q=find(q),p!=q) fa[p]=fa[q]=merge(p,q);}
	int top(int p){return val[find(p)];}
	void pop(int p){p=find(p),fa[ch[p][0]]=fa[ch[p][1]]=fa[p]=merge(ch[p][0],ch[p][1]);}
};
int n,m;
bool vis[100010];
leftistree<100010> t;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),t.newnode(x);
	for(int i=1,op,x,y;i<=m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			if(vis[x]||vis[y]) continue;
			t._merge(x,y);
		}else{
			scanf("%d",&x);
			if(vis[x]){puts("-1");continue;}
			printf("%d\n",t.top(x)),vis[t.find(x)]=1,t.pop(x);
		}
	} 
	return 0;
}

