#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
	int x,y,z,id,v;
	node(int x=0,int y=0,int z=0,int id=0,int v=1):x(x),y(y),z(z),id(id),v(v){}
	bool operator==(node b){return x==b.x&&y==b.y&&z==b.z;}
	friend bool operator<(node a,node b){
		if(a.x!=b.x) return a.x<b.x;
		if(a.y!=b.y) return a.y<b.y;
		return a.z<b.z; 
	} 
};
int n,ans[200010],sos[200010];
node a[200010],b[200010],c[200010];
void ccf(node a[],int l,int r){
	for(int i=l;i<=r;i++) printf("(%d,%d,%d)[%d]=%d\n",a[i].x,a[i].y,a[i].z,a[i].id,a[i].v);
	for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	puts("============");
}
void cdq(int L,int R,int d){
	if(L==R) return ;
	int mid=(L+R)>>1;
	cdq(L,mid,d),cdq(mid+1,R,d);
	if(d==1){
//		printf("L=%d,R=%d,d=%d\n",L,R,d),ccf(b,L,R);
		int cnt=0;
		for(int i=L,j=L,k=mid+1;i<=R;i++){
			if(j<=mid&&(k>R||b[j].z<=b[k].z)) c[i]=b[j++],c[i].id>0&&(cnt+=c[i].v);
			else c[i]=b[k++],c[i].id<0&&(ans[-c[i].id]+=cnt);
		}
//		ccf(c,L,R);
		memcpy(b+L,c+L,sizeof(node)*(R-L+1));
	}else{
//		printf("L=%d,R=%d,d=%d\n",L,R,d),ccf(a,L,R);
		for(int i=L,j=L,k=mid+1;i<=R;i++){
			if(j<=mid&&(k>R||a[j].y<=a[k].y)) b[i]=a[j++],b[i].id=abs(b[i].id);
			else b[i]=a[k++],b[i].id=-abs(b[i].id);
		}
//		ccf(b,L,R);
		memcpy(a+L,b+L,sizeof(node)*(R-L+1));
		cdq(L,R,d-1);
	}
} 
int main(){
	scanf("%d%*d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	int m=0;
	for(int i=1;i<=n;i++){
		if(i>1&&a[i]==b[m]) b[m].v++;
		else b[++m]=a[i];
	}
	memcpy(a,b,sizeof b);
	cdq(1,m,2); 
	for(int i=1;i<=m;i++) sos[ans[abs(a[i].id)]+a[i].v-1]+=a[i].v;
	for(int i=0;i<n;i++) printf("%d\n",sos[i]);
	return 0;
} 
