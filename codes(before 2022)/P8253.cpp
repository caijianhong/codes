#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
struct node{
	int a[3],id,op,v;
	node(int x=0,int y=0,int z=0,int id=0,int op=0,int v=0):id(id),op(op),v(v){a[0]=x,a[1]=y,a[2]=z;}
	int& operator[](int i){return a[i];}
	bool operator<(node b){
		for(int i=0;i<3;i++) if(a[i]!=b[i]) return a[i]<b[i];
		return id<b.id;
	}
	void print(){
		printf("{%d,%d,%d}[%d]=(%d,%d)\n",a[0],a[1],a[2],id,op,v);
	}
}; 
int n,m,a[4][200010];
LL ans;
node _[3][400010];
void prints(node a[],int l,int r){
	for(int i=l;i<=r;i++){
		a[i].print(); 
	}
}
LL cdq(int L,int R,int dep,node a[],node b[]){
	if(dep>2||L==R) return 0;
	int mid=(L+R)>>1;
	LL ans=cdq(L,mid,dep,a,b)+cdq(mid+1,R,dep,a,b);
	printf("L=%d,R=%d,dep=%d,ans=%lld\n",L,R,dep,ans);
	printf("a={\n"),prints(a,L,R);
	switch(dep){
		case 1:{
			for(int i=L,j=L,k=mid+1;i<=R;i++){
				if(j<=mid&&(k>R||a[j][1]<=a[k][1])) b[i]=a[j++],b[i].op=-abs(b[i].op);
				else b[i]=a[k++],b[i].op=abs(b[i].op);
			}
			break;
		}
		case 2:{
			LL s0=0,s1=0;
			for(int i=L,j=L,k=mid+1;i<=R;i++){
				if(j<=mid&&(k>R||a[j][2]<=a[k][2])) b[i]=a[j++],b[i].op==-1&&(s0++,s1+=b[i].v);
				else b[i]=a[k++],b[i].op==1e9&&(ans+=s0*b[i].v+s1);
			}
			break;
		}
	} 
	printf("}\nb={\n"),prints(b,L,R);
	printf("}\nnow ans=%lld\n============\n",ans);
	memcpy(a+L,b+L,sizeof(node)*(R-L+1));
	return cdq(L,R,dep+1,b,_[dep+1])+ans;
}
LL solve(int d){
	for(int i=1;i<=n;i++){
		_[0][i]=node(0,0,0,i,1e9,a[d][i]);
		_[0][i+n]=node(0,0,0,i+n,1,a[d][i]);
		for(int j=0,k=0;j<m;j++){
			if(j!=d){
				_[0][i][k]=a[d][i]-a[j][i];
				_[0][i+n][k]=a[j][i]-a[d][i];
				k++;
			}
		}
	}
	sort(_[0]+1,_[0]+2*n+1);
	return cdq(1,2*n,1,_[0],_[1]);
}
int main(){
	#ifdef LOCAL
	 	freopen("input.in","r",stdin);
	#endif
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<m;i++) ans+=solve(i);
	for(int i=0;i<m;i++) for(int j=1;j<=n;j++) a[i][j]=-a[i][j];
	for(int i=0;i<m;i++) ans-=solve(i);
	printf("%lld\n",ans);
	return 0;
} 
