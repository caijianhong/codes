
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[1005], minn, sum, j, dp[1005][1005], t;
char s[100], s1[100];
int main(){
		scanf("%lld", &t);
	while(t--){
		memset(dp, 18, sizeof(dp));
		printf("dp[0][0]=%lld\n",dp[0][0]);
		scanf("%lld", &n);
		sum = 0, minn = 1e9;
		if(!n) return 0;
		for(int i = 1; i <= n; ++i){
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		dp[1][n] = 0;
		for(int len = n; len >= 1; len-=2){
			for(int l = 1; l + len - 1 <= n; ++l){
				int r = l + len - 1;
				if(a[l + 1] >= a[r]) dp[l + 2][r] = min(dp[l + 2][r], dp[l][r] + a[l + 1]);
				else dp[l + 1][r - 1] = min(dp[l + 1][r - 1], dp[l][r] + a[r]);
				if(l + 2 >= r) minn = min(minn, dp[l + 2][r]);
				if(l + 1 >= r - 1) minn = min(minn, dp[l + 1][r - 1]);
				if(a[l] >= a[r - 1]) dp[l + 1][r - 1] = min(dp[l + 1][r - 1], dp[l][r] + a[l]);
				else dp[l][r - 2] = min(dp[l][r - 2], dp[l][r] + a[r - 1]); 
				if(l + 1 >= r - 1) minn = min(minn, dp[l + 1][r - 1]);
				if(l >= r - 2) minn = min(minn, dp[l][r - 2]);
			}
		}
		printf("%lld\n", sum - minn * 2);
	}
	
}
