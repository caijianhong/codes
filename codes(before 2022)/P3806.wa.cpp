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

inline void write(int x)
{
    char F[200];
    int tmp = x > 0 ? x : -x;
    if(x<0) putchar('-');
    int cnt = 0;
    while(tmp > 0){
        F[cnt++] = tmp%10+'0';
        tmp /= 10;
    }
    while(cnt > 0) putchar(F[--cnt]);
    putchar('\n');
}
const int N = 10005, MaxN = 100000005;
int n, m, u, v, w, Q[105];
int tmp[MaxN], ans[MaxN];//tmp 存所求子树到当前重心的距离
//can 存之前子树到当前重心的距离
int siz[N], vis[N];// sz存节点及子树大小 vis存是否访问过
int maxp[N];//存最大子树的大小 
int tot, rt, dis[N];//dis存到当前重心的距离 
int q[MaxN], ynn[N];//队列辅助清空 ynn记录答案 
vector< pair<int, int> > d[10005]; 
namespace _std{
    void predfz(int x, int fa){
        siz[x] = 1; maxp[x] = 0;
        for(int i = 0; i < d[x].size(); ++i){
            int y = d[x][i].first;
            if(y == fa || vis[y]) return ;
            predfz(y, x);
            siz[x] += siz[y];
            maxp[x] = max(maxp[x], siz[y]);
        }
        maxp[x] = max(maxp[x], tot - siz[x]);
        if(maxp[x] < maxp[rt]) rt = x;
    }
    void cal(int x);
    void solve(int x){
    	printf("x=%d\n",x);
        vis[x] = ans[0] = 1; cal(x);
        for(int i = 0; i < d[x].size(); ++i){
            int y = d[x][i].first;
            if(vis[y]) continue;
            tot = siz[y];
            maxp[0] = MaxN;
            rt = 0;
            predfz(y, 0);
            solve(rt);
        }
    } 
    void update(int x, int fa){
        tmp[++tmp[0]] = dis[x];
        for(int i = 0; i < d[x].size(); ++i){
            int y = d[x][i].first;
            int val = d[x][i].second;
            if(vis[y] || y == fa) continue;
            dis[y] = dis[x] + val;
            update(y, x);
        }

    }
    void cal(int x){
        int p = 0;
        for(int i = 0; i < d[x].size(); ++i){
            int y = d[x][i].first, val = d[x][i].second;
            if(vis[y]) continue;
            tmp[0] = 0; dis[y] = val;
            update(y, x);
            for(int k = tmp[0]; k; --k){
                for(int j = 1; j <= m; ++j){
                    if(Q[j] >= tmp[k]){
                        ynn[j] |= ans[Q[j] - tmp[k]];
                    }
                }
            }
            for(int k = tmp[0]; k; --k) q[++p] = tmp[k], ans[tmp[k]] = 1;
        }
        for(int i = 1; i <= p; ++i) ans[q[i]] = 0;
    }
}
int main(){
    n = read(), m = read();
    for(int i = 1; i < n; ++i){
        u = read(), v = read(), w = read();
        d[u].push_back(make_pair(v, w));
        d[v].push_back(make_pair(u, w));
    }
    for(int i = 1; i <= m; ++i) Q[i] = read();
    maxp[0] = n;
    rt = 0;
    tot = n;
    _std::predfz(1, 0); 
    _std::solve(rt); 
    for(int i = 1; i <= m; ++i){
        if(ynn[i]) printf("AYE\n");
        else printf("NAY\n");
    }
    return 0;
}
