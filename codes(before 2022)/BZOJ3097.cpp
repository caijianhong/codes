//48463 47057 43117 19260817
#include <map>
#include <cmath> 
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility> 
#include <iostream>
using namespace std;
typedef long long LL;
LL qpow(LL a,LL b,int mod){LL res=1;for(;b;b>>=1,a=a*a%mod) if(b&1) res=res*a%mod;return res;}
LL hask(vector<LL> s,int base,int mod){
	int len=s.size();
	LL res=0;
	for(int i=0;i<len;i++){
		if(mod) res=(res*base+s[i])%mod;
		else res=res*base+s[i];
	}
	return res;
}
vector<LL> random_vector(int n,vector<LL> alp){
	vector<LL> res;
	int siz=alp.size();
	for(int i=1;i<=n;i++) res.push_back(alp[rand()%siz]);
	return res;
}
vector<vector<LL>> birth(int n,int mod,vector<LL> alp){
	int k=1+sqrt(2*mod);
	vector<vector<LL>> res;
	for(int i=0;i<k;i++) res.push_back(random_vector(n,alp));
	return res;
}
pair<vector<LL>,vector<LL>> ull_attack(int n){
	vector<LL> s,t;
	for(int i=0;i<1<<n;i++) s.push_back('A'+__builtin_popcount(i)%2);
	for(int i=0;i<1<<n;i++) t.push_back('B'-__builtin_popcount(i)%2);
	return {s,t};
}
pair<vector<LL>,vector<LL>> birth_attack(int base,int mod,vector<LL> alp){
	for(int l=1;l<=50;l++){
		for(int j=1;j<=5;j++){
			auto v=birth(l,mod,alp);
			map<LL,vector<LL>> mp;
			for(auto s:v){
				LL res=hask(s,base,mod);
				if(mp.count(res)&&mp[res]!=s){
					return {mp[res],s};
				}else{
					mp[res]=s;
				}
			}
		}
	}
	return {{},{}}; 
}
string vtos(vector<LL> p){
	string s="";
	for(int i=0;i<p.size();i++) s+=(char)p[i];
	return s;
}  
int main(){
	int base=48463,mod=19260817;
	srand(time(0));
	auto p=ull_attack(6);
	auto sx=p.first,sy=p.second;
	LL hx=hask(sx,base,mod),hy=hask(sy,base,mod);
	auto p2=birth_attack(
		qpow(base,sx.size(),mod),
		mod,
		{hx,hy}
	);
	vector<LL> S,T;
	for(auto x:p2.first){
		auto res=x==hx?sx:sy;
		for(auto y:res) S.push_back(y);
	}
	for(auto x:p2.first){
		auto res=x==hx?sx:sy;
		for(auto y:res) T.push_back(y);
	}
	cout<<vtos(S)<<endl<<vtos(T)<<endl;
	return 0;
} 

