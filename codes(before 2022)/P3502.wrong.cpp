#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int n, m, nxt[205][100005], len[205];
ll f[35][205][205], ans[205], sum[205];
char s[205][100005];
int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; ++i){
		scanf("%s", s[i] + 1);
		len[i] = strlen(s[i] + 1); 
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 2, k = 0; j <= len[i]; ++j){
			while(k && s[i][j] != s[i][k + 1]) k = nxt[i][k];
			if(s[i][j] == s[i][k + 1]) k++;
			nxt[i][j] = k;
		}
	}
	memset(f, 20, sizeof(f));
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			int t = 0;
			for(int k = 1; k <= len[i]; ++k){
				while(t && s[i][k] != s[j][t + 1]) t = nxt[j][t];
				if(s[i][k] == s[j][t + 1]) t++;
			}
			f[0][i][j] = len[j] - ((t == len[i] && i == j) ? 0 : t);
		}
	}
	for(int i = 1; i <= 31; ++i){
		for(int k = 1; k <= n; ++k){
			for(int j = 1; j <= n; ++j){
				for(int t = 1; t <= n; ++t){
				//	if(j == k || j == t || k == t) continue;
					f[i][j][t] = min(f[i][j][t], f[i - 1][j][k] + f[i - 1][k][t]);
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i) ans[i] = len[i];
	m--;
	for(int i = 0; i <= 31; ++i){
		if((ll)m & (1ll << i)){
			memset(sum, 20, sizeof(sum));
			for(int j = 1; j <= n; ++j){
				for(int k = 1; k <= n; ++k){
				//	if(j == k) continue; 
					sum[k] = min(sum[k], ans[j] + f[i][j][k]); 
				}
			}
			for(int j = 1; j <= n; ++j) ans[j] = sum[j];
		}
	}
	ll Ans = 1e18; 
	for(int i = 1; i <= n; ++i){
		Ans = min(Ans, ans[i]);
	}
	printf("%lld\n", Ans);
	return 0;
}
