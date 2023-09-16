#include <bits/stdc++.h>
using namespace std;
int n, m, k, maxx, pos, nxt, a[1000010], Log[1000010], f[1000010][21], d[1000010], l, r;
long long s[1000010], ans=1;
const int Logn = 20;
const long long mo = 998244353;
stack <int> st;
vector <int> p[1000010];
inline int read(){
	int s=0, w=1; char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') w=-1; ch=getchar();}
	while (ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
	return s*w;
}
int main(){
	n = read(), m = read();
	Log[0] = -1;
	for (int i=1; i<=n; i++){
		a[i] = read();
		p[a[i]].push_back(i);
		f[i][0] = a[i];
		Log[i] = Log[i>>1] + 1;
	}
	for (int j=1; j<=Logn; j++){
		for (int i=1; i+(1<<j)-1<=n; i++){
			f[i][j] = max(f[i][j-1], f[i+(1<<j-1)][j-1]);
		}
	}
	for (int i=n; i>=1; i--){
		while (!st.empty() && a[st.top()] <= a[i]) st.pop();
		if (st.empty()) d[i] = 0;
		else d[i] = st.top();
		st.push(i);
	}
	for (int i=n; i>=1; i--){
		if (!d[i]) s[i] = 1LL * (n - i + 1) * a[i] % mo;
		else s[i] = (s[d[i]] + 1LL * (d[i] - i) * a[i] % mo) % mo;
		printf("d[%d]=%d,s[%d]=%d\n",i,d[i],i,s[i]);
	}
	for (int i=1; i<=m; i++){
		l = read(), r = read();
		k = Log[r - l + 1];
		maxx = max(f[l][k], f[r-(1<<k)+1][k]);
		pos = *lower_bound(p[maxx].begin(), p[maxx].end(), l);
		ans = ans * ((s[l] - s[pos] + mo + 1LL * maxx * (r - pos + 1) % mo + mo)) % mo;
	}
	printf ("%lld\n", ans);
	return 0;
}
/*
6 1
6 4 3 4 3 2
2 6
*/
