const char* table[]={
	"0\n",
	"1\n" "1",
	"1\n" "1",
	"1\n" "1",
	"2\n" "2 4",
	"2\n" "2 4",
	"4\n" "2 4 6 3",
	"4\n" "2 4 6 3",
	"5\n" "2 4 8 6 3",
	"6\n" "2 4 8 6 3 9",
	"8\n" "5 10 2 4 8 6 3 9",
	"8\n" "5 10 2 4 8 6 3 9",
	"9\n" "5 10 2 4 8 12 6 3 9",
	"9\n" "5 10 2 4 8 12 6 3 9",
	"12\n" "5 10 2 4 8 12 6 3 9 6 14 7",
	"12\n" "2 4 8 12 6 3 9 15 5 10 14 7",
};
#include <cmath> 
#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N> struct siever{
    int pri[N+10],cnt;
    siever(){
        memset(pri,1,sizeof pri),pri[0]=pri[1]=0;
        for(int i=1;i<=N;i++){
            if(pri[i]) pri[++cnt]=i;
            for(int j=1;j<=cnt&&i*pri[j]<=N;j++){
                pri[i*pri[j]]=0;
                if(i%pri[j]==0) break;
            }
        } 
    }
    int operator[](int i){return pri[i];}
    bool operator()(int x){return *lower_bound(pri+1,pri+cnt+1,x)==x;}
};
int n,cnt[3],p[3][1000010],pth[2000010],tot;
bool vis[1000010];
siever<1000010> pri;
void prt(int x,int f=0){if(f||!vis[x]) vis[x]=1,pth[++tot]=x;}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d",&n);
	if(n<=15) return puts(table[n]),0;
	for(int i=1;pri[i]<=n/2;i++){
		int k=pri[i]<=sqrt(n)?0:(pri[i]*3>n)+1;
		p[k][++cnt[k]]=pri[i];
	}
	prt(p[2][1]),prt(p[2][1]*2);
	int crx=0;
	for(int i=1;i<=cnt[1];i++){
		prt(p[1][i]*(2+crx));
		prt(p[1][i]);
		crx^=1,prt(p[1][i]*(2+crx));
	}
	prt(6);
	p[0][++cnt[0]]=2;
	p[0][cnt[0]+1]=1;
	for(int i=2;i<=cnt[0];i++){
		int no=p[0][i]*p[0][i+1];
		for(int j=p[0][i];j<=n;j+=p[0][i]) if(j!=no&&(p[0][i]!=2||!pri(j/2)||j/2<=n/3)) prt(j);
		prt(no);
	}
	int pos=tot;
	for(int i=2;i<=cnt[2];i++){
		prt(p[2][i]*2,1);
		prt(p[2][i]);
		prt(p[2][i]*2,1);
	}
	if(pos!=tot) tot--; 
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d%c",pth[i]," \n"[i==tot]);
	return 0;
}

