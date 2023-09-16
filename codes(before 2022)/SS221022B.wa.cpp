#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,i,j,x,ppcnt[N],s,tot=1,v=65535,p=998244353;
int t[2525],ans[2525],anss[65560],rnk[65560];
int read(){
    char c=getchar();
    int s=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){
        s=s*10+c-48;
        c=getchar();
    }
    return s;
}
void outp(int x){
    if(x>9) outp(x/10);
    putchar(x%10+48);
    return;
}
int main()
{
    freopen("count.hack.in","r",stdin);
    freopen("count.out","w",stdout);
    for(i=1;i<65536;i++){
        ppcnt[i]=ppcnt[i-(-i&i)]+1;
        if(ppcnt[i]<=4) t[rnk[i]=++tot]=i;
    }
    rnk[0]=1;
    n=read();
    for(i=1;i<=n;i++){
        x=read();
        s=anss[x]+1;
        for(j=1;j<=tot;j++)
        if((x&t[j])==t[j]) s=((s+ans[j])>=p?(s+ans[j]-p):(s+ans[j]));
        outp(s);
        putchar('\n');
        if(ppcnt[x]<=4) ans[rnk[x]]=((s+ans[rnk[x]])>=p?(s+ans[rnk[x]]-p):(s+ans[rnk[x]]));
        else{
            anss[v]=((s+anss[v])>=p?(s+anss[v]-p):(s+anss[v]));
            for(j=(v-x)&(v-x-1);j!=v-x;j=(j-1)&(v-x)) anss[j+x]=((s+anss[j+x])>=p?(s+anss[j+x]-p):(s+anss[j+x]));
        }
    }
	return 0;
}

