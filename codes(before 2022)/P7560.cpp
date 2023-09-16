#include <cstdio>
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
    edge& operator[](int i){return e[i];}
    void add(int u,int v,T w=0){e[++cnt]=edge(u,v,w),nxt[cnt]=head[u],head[u]=cnt;}
    void link(int u,int v,T w=0){add(u,v,w),add(v,u,w);}
};
template<int N,class T=LL> struct fenwick{
	T c[N+10];
	fenwick(){memset(c,0,sizeof c);}
	void add(T k,int p){for(;p<=N;p+=p&-p) c[p]+=k;}
	T query(int p){T res=0;for(;p>=1;p-=p&-p) res+=c[p]; return res;}
};
template<int N,class T=LL> struct exfenwick:public fenwick<N,T>{
	fenwick<N,T> &t=*this;
	void modify(T k,int l,int r){t.add(k,l),t.add(-k,r+1);}
	T query(int x){return t.query(x);}
	int binary(T k){
		int p=0;T tot=0;
		for(int j=18;j>=0;j--) if(tot+t.c[p+(1<<j)]<k) tot+=t.c[p+=1<<j];
		return p+1;
	}
};
template<int N,class T,class A=LL> struct segtree{
	T tag[N*4+10];
	void pushdown(int p){tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p],tag[p]=T();}
	void modify(T k,int L,int R,int p=1,int l=1,int r=N){
		if(L<=l&&r<=R) return void(tag[p]+=k);
		int mid=(l+r)>>1;
		pushdown(p);
		if(L<=mid) modify(k,L,R,p<<1,l,mid);
		if(mid+1<=R) modify(k,L,R,p<<1|1,mid+1,r);
	}
	A query(int X,int p=1,int l=1,int r=N){
		if(X<=l&&r<=X) return tag[p]();
		int mid=(l+r)>>1;
		pushdown(p);
		if(X<=mid) return query(X,p<<1,l,mid);
		if(mid+1<=X) return query(X,p<<1|1,mid+1,r);
		return -1e18;
	}
};
template<class T=LL> struct tag{
	T ad,mx;
	tag(T ad=0,T mx=-1e18):ad(ad),mx(mx){}
	T operator()(){return max(ad,mx);}
	tag operator+=(tag b){return *this=tag(ad+b.ad,max(mx+b.ad,b.mx));}
	//max(max(k+ad,mx)+ad',mx')=max(k+ad+ad',max(mx+ad',mx'))
};
int n,m,q,co[1<<18];
exfenwick<1<<18> s;
segtree<1<<18,tag<LL>,LL> t;
graph<1<<18,1<<18,LL> que;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,op,l,r;i<=q;i++){LL k;
		scanf("%d",&op);
		switch(op){
			case 1:{
				scanf("%d%d%d%lld",&l,&r,&co[i],&k);
				s.modify(k,l,r);
				t.modify(tag<LL>(k,0),l,r);
				que.add(l,i,k);
				que.add(r+1,i,-k);
				break;
			}
			case 2:{
				scanf("%d%d%lld",&l,&r,&k);
				t.modify(tag<LL>(-k,0),l,r);
				break;
			}
			case 3:{
				scanf("%d%lld",&l,&k);
//				printf("query q[%d][%lld]\n",l,k+s.query(l)-t.query(l));
				if(k>t.query(l)) que.add(l,0,-1);
				else que.add(l,0,k+s.query(l)-t.query(l));
				break;
			}
		}
	}
//	for(int i=1;i<=que.cnt;i++){
//		printf("(%d,%d)=%lld\n",que[i].u,que[i].v,que[i].w);
//	}
	memset(s.c,0,sizeof s.c);
	for(int u=1;u<=n;u++){
//		printf("u=%d\n",u);
		for(int i=que.head[u];i;i=que.nxt[i]){
			if(que[i].v){
//				printf("s[%d]+=%lld\n",que[i].v,que[i].w);
				s.add(que[i].w,que[i].v);
			}
		}
		for(int i=que.head[u];i;i=que.nxt[i]){
			if(!que[i].v){
				LL k=que[i].w;
//				printf("query[%d] k=%lld,get co[%d]\n",i,k,s.binary(k));
				if(k==-1) que[i].w=0;
				else que[i].w=co[s.binary(k)];
			}
		}
	}
//	for(int i=1;i<=que.cnt;i++){
//		printf("(%d,%d)=%lld\n",que[i].u,que[i].v,que[i].w);
//	}
	for(int i=1;i<=que.cnt;i++) if(!que[i].v) printf("%lld\n",que[i].w);
	return 0;
}
/*
1. �����뿪������Ӱ�죺
	- d[i] ��ʾ�� i �����е���ʵ����
		* ����ӣ������������� 0 ȡ max������ѯ�� => segtree
	- e[i] ��ʾ�����뿪ʱ���� i �����е�����
		* ����ӣ�����ѯ�� => fenwick
	- �뿪�� e[i]-d[i] ���ˣ��ӵ�ѯ�ʲ����� k ��
2. ���ߴ���ѯ��
	- ���ڼ������ [L,R] += k*c
		* [L,n] += k*c
		* [R+1,n] -= k*c
	- ά������ c[i]����ʾ�� i ������������˻��ڲ��ڣ�0 �� k����ͬʱ������ɫ
	- ����ѯ�ʲ������ҵ���С�� y ʹ c[1]+c[2]+...+c[y]>=k => ��״���鱶�� 
*/ 
