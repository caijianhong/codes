#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int mod=5557;

int n,m,time;
int cnt[16]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};

int u[501],v[501],ans[16];
char ch[501][4];
struct Matrix
{
    int a[56][56];
    void clear(){memset(a,0,sizeof(a));}
}A[16],T[16];


Matrix operator * (Matrix c,Matrix d)
{
    Matrix t;
    for(int i=0;i<=2*n;i++) 
        for(int j=0;j<=2*n;j++) 
        {
            t.a[i][j]=0;
            for(int k=0;k<=2*n;k++) 
            {
                t.a[i][j]+=c.a[i][k]*d.a[k][j];    
                if(t.a[i][j]>=mod) t.a[i][j]%=mod;
            }
        }
    return t;
}

bool check(char c,char s[])
{
    for(int i=0;i<4;i++) if(s[i] == c)return true;
    return false;
}

int qpow(Matrix c,Matrix d,int k)
{
    while(k)
    {
        if(k&1) c=c*d;
        d=d*d;
        k>>=1;
    }
    printf(" %d %d ",c.a[0][0],c.a[0][2*n]);
    return ((c.a[0][0]+c.a[0][2*n]-1)+mod)%mod;
}

int solve()
{
    int ret=0;
    for(int i=0;i<16;i++) 
    {
        if(cnt[i]%2) ret-=ans[i];
        else ret+=ans[i];
    }
    ret=(ret%mod+mod)%mod;
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d%s",&u[i],&v[i],ch[i]),u[i]--,v[i]--;
    scanf("%d",&time);
    for(int i=0;i<16;i++) 
    {
        A[i].clear();
        T[i].clear();
        A[i].a[0][0]=1;
        T[i].a[0][2*n]++;//
        T[i].a[2*n][2*n]++;//记录开始点经过的次数 
        for(int j=0;j<n;j++) T[i].a[j+n][j]++;
        for(int j=1;j<=m;j++) 
        {
            T[i].a[u[j]][v[j]]++;
            if(!(i & 1) && check('B',ch[j]))continue;
            if(!(i & 2) && check('J',ch[j]))continue;
            if(!(i & 4) && check('M',ch[j]))continue;
            if(!(i & 8) && check('P',ch[j]))continue;
            if(i)T[i].a[u[j]][v[j] + n]++;
         }
         for(int j=0;j<4;j++) {if(i&(1<<j)) printf("1");else printf("0");}
             ans[i] = qpow(A[i],T[i],time);//求出每种路线的答案 
        printf("ans[%d]=%d\n",i,ans[i]);
    }
    cout<<solve()<<endl;//容斥得到答案 
    
    return 0;
}
