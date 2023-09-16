#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int n,m,a[1010][1010];
int ans[2][1010];
void flip_c(int j){for(int i=1;i<=n;i++) a[i][j]^=1;}
void flip_l(int i){for(int j=1;j<=m;j++) a[i][j]^=1;}
int count(int i){
	int cnt[2]={0,0};
	for(int j=1;j<=m;j++) cnt[a[i][j]]++;
	return cnt[0]&&cnt[1]?-1:!cnt[0]; 
}
bool check(int pos){
	for(int i=1;i<pos;i++) ans[1][i]=a[1][i];
	for(int i=pos;i<=m;i++) ans[1][i]=!a[1][i];
	for(int i=1;i<=m;i++) if(ans[1][i]) flip_c(i);
	if(pos==m+1){
		int flag=0;
		for(int i=2;i<=n;i++){
			int res=count(i);
			if(flag){
				if(res<0) return 0;
				if(!res) ans[0][i]=1,flip_l(i); 
			}else{
				if(res)
			}
		}
	}else{
		for(int i=2;i<=n;i++){
			int res=count(i);
			if(res<0) return 0;
			if(!res) ans[0][i]=1,flip_l(i); 
		}
		return 1;
	}
}
void print(){
	puts("=====================");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d%c",a[i][j]," \n"[j==m]);
		}
	}
}
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	if(n==1){
		puts("YES");
		for(int i=1;i<=n;i++) putchar('0');puts("");
		for(int i=1;i<=m;i++) putchar(a[1][i]+'0');puts("");
		return 0;
	}
	for(int j=1;j<=m+1;j++){
		memset(ans,0,sizeof ans),ans[0][1]=0;
		if(check(j)){
//			printf("(%d,%d)\n",i,0);
			puts("YES");
			for(int i=1;i<=n;i++) putchar(ans[0][i]+'0');puts("");
			for(int i=1;i<=m;i++) putchar(ans[1][i]+'0');puts("");
			return 0;
		}else{
			for(int i=1;i<=n;i++) if(ans[0][i]) flip_l(i);
			for(int i=1;i<=m;i++) if(ans[1][i]) flip_c(i);
		}
//		print();
		memset(ans,0,sizeof ans),ans[0][1]=1,flip_l(1);
		if(check(j)){
//			printf("(%d,%d)\n",i,1);
			puts("YES");
			for(int i=1;i<=n;i++) putchar(ans[0][i]+'0');puts("");
			for(int i=1;i<=m;i++) putchar(ans[1][i]+'0');puts("");
			return 0;
		}else{
			for(int i=1;i<=n;i++) if(ans[0][i]) flip_l(i);
			for(int i=1;i<=m;i++) if(ans[1][i]) flip_c(i);
		}
//		print();
	}
	puts("NO");
	return 0;
}

