#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,int M,class T=int> struct graph{
    int head[N+10],nxt[M*2+10],cnt;
    struct edge{
        int u,v;T w;
        edge(int u=0,int v=0,T w=0):u(u),v(v),w(w){}
    } e[M*2+10];
    graph(){memset(head,cnt=0,sizeof head);}
    edge operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<class T> struct func{
    T k,b;
    func(T k=0,T b=0):k(k),b(b){}
    T operator()(T x){return k*x+b;}
};
template<int N,class T> struct lcstree{
    func<T> tag[N+10];
    int ch[N+10][2],tot;
    lcstree():tot(-1){newnode();}
    int newnode(){int p=++tot;return ch[p][0]=ch[p][1]=0,tag[p]=func<T>(),p;}
    void insert(func<T> f,int &p,int l=0,int r=2e5){
        if(!p) p=newnode(); int mid=(l+r)>>1;
        switch((f(l)<=tag[p](l))+(f(r)<=tag[p](r))){
            case 0: tag[p]=f;break;
            case 1: insert(f,ch[p][0],l,mid),insert(f,ch[p][1],mid+1,r);break;
        }
    }
    T query(int x,int &p,int l=0,int r=2e5){
        if(!p) return 0; int mid=(l+r)>>1;
        if(x<=mid) return max(tag[p](x),query(x,ch[p][0],l,mid));
        else return max(tag[p](x),query(x,ch[p][1],mid+1,r));
    }
};
int n,a[200010],tot,siz[200010],maxk[200010]; 
bool cut[400010];
LL ret[200010];
graph<200010,200010> g,r;
pair<int,int> pth[200010];
vector<int> dts[2];
lcstree<200010<<4,LL> t;
void rebuild(int u,int fa=0){
	int now=u;
	for(int i=r.head[u];i;i=r.nxt[i]){
		int v=r[i].v; if(v==fa) continue;
		a[++tot]=a[u];
		g.link(now,tot,0),g.link(tot,v,1),now=tot;
		rebuild(v,u);
	}
}
pair<int,int> getmiddle(int u,int fa,int T){
	pair<int,int> res={1e9,0}; siz[u]=1;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa||cut[i]||cut[i^1]) continue;
		res=min({res,getmiddle(v,u,T),{max(siz[v],T-siz[v]),i}});
		siz[u]+=siz[v];
	}
	return res;
}
void dfs(int u,int fa,vector<int> &dts,int mink,int sum){
	dts.push_back(u),pth[u]={mink,sum},siz[u]=1;
	for(int i=g.head[u];i;i=g.nxt[i]){
		int v=g[i].v; if(v==fa||cut[i]||cut[i^1]) continue;
		dfs(v,u,dts,min(mink,a[v]),sum+g[i].w);
		siz[u]+=siz[v];
	}
}
void dp(int k){
	maxk[dts[1].size()]=-1e9; int root=t.tot=0;
	for(int i=(int)dts[1].size()-1;i>=0;i--) maxk[i]=max(maxk[i+1],pth[dts[1][i]].second);
//	for(int i=0;i<=dts[1].size();i++) printf("%d%c",maxk[i]," \n"[i==dts[1].size()]);
	for(int i=0,j=0;i<dts[0].size()||j<dts[1].size();){
		if(i<dts[0].size()&&(j==dts[1].size()||pth[dts[0][i]]<pth[dts[1][j]])){
			int u=dts[0][i]; pair<int,int> &p=pth[dts[0][i++]];
			ret[u]=max({ret[u],1ll*p.first*(p.second+maxk[j]+k+1),t.query(p.second,root)});
//			printf("(i=%d,j=%d) ret[%d]=max(%d*%d)\n",i-1,j,u,p.first,(p.second+maxk[j]+k+1));
//			printf("(i=%d,j=%d) ret[%d]=%lld (lcstree)\n",i-1,j,u,t.query(p.second,root));
		}else{
			pair<int,int> &p=pth[dts[1][j++]];
			t.insert(func<LL>(p.first,1ll*p.first*(p.second+k+1)),root);
		}
	}
}
void solve(int i){
	if(!i) return ;
	int L=g[i].u,R=g[i].v;dts[0].clear(),dts[1].clear();
//	printf("solve((%d,%d)=%d)\n",L,R,g[i].w);
	dfs(L,R,dts[0],a[L],0),dfs(R,L,dts[1],a[R],0);
	int Ls=siz[L],Rs=siz[R];
	sort(dts[0].begin(),dts[0].end(),[](int i,int j){return pth[i]<pth[j];});
	sort(dts[1].begin(),dts[1].end(),[](int i,int j){return pth[i]<pth[j];});
//	printf("dts[0]:");for(int i: dts[0]) printf("(%d){%d,%d},",i,pth[i].first,pth[i].second);puts("");
//	printf("dts[1]:");for(int i: dts[1]) printf("(%d){%d,%d},",i,pth[i].first,pth[i].second);puts("");	
	dp(g[i].w),swap(dts[0],dts[1]),dp(g[i].w);
	cut[i]=cut[i^1]=1;
	solve(getmiddle(L,R,Ls).second),solve(getmiddle(R,L,Rs).second);
}
int main(){
    freopen("rag.in","r",stdin),freopen("rag.out","w",stdout);
	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
	#endif
	scanf("%d",&n),g.add(0,0);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),r.link(u,v);
	tot=n,rebuild(1);
//	for(int i=2;i<=g.cnt;i+=2) printf("(%d,%d)=%d\n",g[i].u,g[i].v,g[i].w);
	solve(getmiddle(1,0,tot).second);
	for(int i=1;i<=n;i++) printf("%lld%c",max(ret[i],1ll*a[i])," \n"[i==n]);
	return 0;
}

