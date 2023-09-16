#include <cstdio>
#include <cassert>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node;
template<int N,class T=int> struct flower{
    T b[N+10];int cnt;
    flower():cnt(0){}
    T operator+=(T x){return b[++cnt]=x;}
    void work(){sort(b+1,b+cnt+1),cnt=unique(b+1,b+cnt+1)-b-1;}
    int operator()(T x){return lower_bound(b+1,b+cnt+1,x)-b;}
    T operator[](int x){return b[x];}
};
template<int N,class T=int> struct fenwick{
    T c[N+10];
    fenwick(){memset(c,0,sizeof c);}
    void add(T k,int p){for(;p<=N;p+=p&-p) c[p]+=k;}
    T query(int p,T ans=0){for(;p>=1;p-=p&-p) ans+=c[p];return ans;}
    T operator[](int x){return c[x];}
};
int n,q[2000010][3];
flower<2000010> b;
fenwick<1<<21> t1,t2;
int brute(int t){return min(t1.query(t),t2.query(2e6)-t2.query(t));}
node solve(){
    int p=0,s1=0,s2=t2.query(2e6);
    for(int j=20;j>=0;j--){
    	int q=p+(1<<j);
    	if(s1+t1[q]<s2-t2[q]) s1+=t1[q],s2-=t2[q],p=q;
	}
    return node(min(s1,s2),p);
}
node bestccf(int f){
	if(f>2e6) return node(0,0);
	int p=0,s1=0,s2=t2.query(2e6);
    for(int j=20;j>=0;j--){
    	int q=p+(1<<j);
    	if(s1+t1[q]<s2-t2[q]) s1+=t1[q],s2-=t2[q],p=q;
    	else if(min(s1+t1[q],s2-t2[q])==f) s1+=t1[q],s2-=t2[q],p=q;
	}
    return node(min(s1,s2),p);
} 
int main(){
//    #ifdef LOCAL
//    	freopen("input.in","r",stdin);
//    #endif
    scanf("%d",&n);
    for(int i=1,op,x;i<=n;i++){
        scanf("%d",&op);
        // q[i]={t,x,y};
        if(op==1) scanf("%d%d%d",&q[i][0],&q[i][1],&q[i][2]);
        else scanf("%d",&x),q[i][0]=q[x][0],q[i][1]=q[x][1],q[i][2]=-q[x][2];
        b+=q[i][1];
    }
    b.work();
    for(int i=1;i<=n;i++){
        (!q[i][0]?t1:t2).add(q[i][2],b(q[i][1])+q[i][0]);
        node res1=solve(),res2=bestccf(brute(res1.second+1)),res=max(res1,res2);
        assert(brute(res1.second)==res1.first);
        assert(brute(res2.second)==res2.first);
        printf(res.first?"%d %d\n":"Peace\n",b[res.second],2*res.first);
    }
    return 0;
}

/*
.ans
Peace
103 200
103 200
103 300
102 200
102 200
104 700
102 1000

.out
Peace
102 250
102 400
103 550
101 250
101 350
103 750
101 1100
*/

