#include <cstdio>
#include <testlib.h>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> node;
#define x first
#define y second
const int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int n,m,c[1010];
node a[1010];
int main(int argc,char *argv[]){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	registerTestlibCmd(argc,argv);
	n=inf.readInt();
	for(int i=1;i<=n;i++) a[i].x=inf.readInt(),a[i].y=inf.readInt(); 
	m=ouf.readInt(1,40);
	for(int i=1;i<=m;i++) c[i]=ouf.readInt();
	for(int i=1;i<=n;i++){
		int x=0,y=0;
		string op=ouf.readToken();
		quitif(op.size()!=m,_wa,"Fuck! op.size()!=m: op.size()=%d,m=%d\n",(int)op.size(),m);
		for(int j=1;j<=m;j++){
			switch(op[j-1]){
				case 'L':x-=c[j];break;
				case 'R':x+=c[j];break;
				case 'D':y-=c[j];break;
				case 'U':y+=c[j];break;
				default :quitf(_wa,"Fuck! op[%d]=%c\n",j-1,op[j-1]);
			}
		}
		quitif(x!=a[i].x||y!=a[i].y,_wa,"Fuck! Robot arrives at (%d,%d) but not (%d,%d)!\n",x,y,a[i].x,a[i].y);
	}
	quitf(_ok,"Orz!\n");
	return 0;
}

