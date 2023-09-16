#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,l,r;
    cin>>n>>l>>r;
    if(r-l>=n-1){
        cout<<n-1<<endl;
    } 
    else{
        bool flag=false;
        int k=1;
        for(int i=r-1;i>=l;i--){
            k+=1;
            if(k>=2e8)break;
            if(i%n>(i+1)%n){
            cout<<i%n;
            flag=true;
            break;
          }
        }
        if(!flag)cout<<r%n;
    }
    return 0;
}
/*
300000000 599999999 899999997
*/
