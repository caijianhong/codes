#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
template<int N,int M=128> struct sa{
	int sa[N*2+10],rnk[N+10],h[N+10],hei[N+10];
	void bucketsort(int n){
		memset(hei,0,sizeof hei);
		for(int i=1;i<=n;i++) hei[rnk[h[i]]]++;
		for(int i=1;i<=max(n,M);i++) hei[i]+=hei[i-1];
		for(int i=n;i>=1;i--) sa[hei[rnk[h[i]]]--]=h[i];
	}
	void build(char *s){
		int n=strlen(s+1);
		for(int i=1;i<=n;i++) h[i]=i,rnk[i]=s[i];
		bucketsort(n);
		for(int j=1;j<=n;j<<=1){
			int tot=0;
			for(int i=n-j+1;i<=n;i++) h[++tot]=i;
			for(int i=1;i<=n;i++) if(sa[i]-j>0) h[++tot]=sa[i]-j;
			bucketsort(n);
			tot=h[sa[1]]=1;
			for(int i=2;i<=n;i++){
				h[sa[i]]=
					rnk[sa[i-1]]==rnk[sa[i]]&&
					(printf("sa[%d-1]=%d,sa[%d]=%d,j=%d\n",i,sa[i-1],i,sa[i],j),rnk[sa[i-1]+j]==rnk[sa[i]+j])?
					tot:++tot;
			}
			memcpy(rnk,h,sizeof h);
		}
		memset(hei,0,sizeof hei);
		for(int i=1,k=0;i<=n;i++){
			if(rnk[i]==1) continue;
			int j=sa[rnk[i]-1];k=max(k-1,0);
			while(max(i,j)+k<=n&&s[i+k]==s[j+k]) k++;
			hei[rnk[i]]=k;
		}
	}
	int operator[](int i){return hei[i];}
};
int n;
char s[1000010];
sa<1000010> hei;
int main(){
//	#ifdef LOCAL
//	 	freopen("input.in","r",stdin);
//	#endif
	scanf("%s",s+1),n=strlen(s+1);
	hei.build(s);
	for(int i=1;i<=n;i++) printf("%d%c",hei.sa[i]," \n"[i==n]);
	return 0;
}

