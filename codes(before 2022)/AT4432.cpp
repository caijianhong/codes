#include <cstdio>
#include <cstring>
#include <utility> 
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node;
#define x first
#define y second
const int dx[]={0,-1,1,0},dy[]={-1,0,0,1};//DLRU
int n,len;
node a[1010];
char s[1010];
LL c[1010];
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	int tmp=(abs(a[1].x+a[1].y))%2;
	for(int i=1;i<=n;i++) if(tmp!=(abs(a[i].x+a[i].y))%2) return puts("-1"),0;
	printf("%d\n",31+!tmp);
	if(!tmp) printf("1 ");
	for(int i=0;i<=30;i++) printf("%lld%c",c[++len]=1ll<<i," \n"[i==30]);
	for(int i=1;i<=n;i++){
		LL nx=a[i].x,ny=a[i].y;
		if(!tmp) ny-=1,putchar('U');
		for(int j=len;j>=1;j--){
			for(int k=0;k<4;k++){
				LL tx=nx+c[j]*dx[k],ty=ny+c[j]*dy[k];
				if(abs(tx)+abs(ty)<c[j]){
					nx=tx,ny=ty;
					s[j]="URLD"[k];
					break;
				}
			}
		}
		s[len+1]=0,puts(s+1);
	}
	return 0;
}

