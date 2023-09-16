//[SDOI2022] \xce?\xa6\xb4›¥ 
#include <set>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
string wzy[85]={
	"a","o","e",
	"ba","bo","bi","bu",
	"pa","po","pi","pu",
	"ma","mo","me","mi","mu",
	"fa","fo","fu",
	"da","de","di","du",
	"ta","te","ti","tu",
	"na","ne","ni","nu",
	"la","le","li","lu",
	"ga","ge","gu",
	"ka","ke","ku",
	"ha","he","hu",
	"ji","jv","qi","qv","xi","xv",
	"za","ze","zi","zu",
	"ca","ce","ci","cu",
	"sa","se","si","su",
	"zha","zhe","zhi","zhu",
	"cha","che","chi","chu",
	"sha","she","shi","shu",
	"re","ri","ru",
	"ya","yo","ye","yi","yv",
	"wa","wo","wu"
};
set<string> crxis;
void sshwy(){
	for(int i=0;i<85;i++){
		string s=wzy[i];
		sort(s.begin(),s.end());
		crxis.insert(s);
	}
}
int n;
LL f[1<<10];
string s;
void binprt(int u){
	for(int i=n-1;i>=0;i--) putchar((u>>i&1)+'0');
}
int mian(){
	n=s.size();
	f[0]=1;
	for(int i=1;i<1<<n;i++){
		for(int j=(i-1)&i;j>=0;j=(j-1)&i){
//			binprt(i),putchar(' '),binprt(j),puts("");
			string clb="";
			for(int k=0;k<n;k++) if((i^j)>>k&1) clb+=s[k];
			sort(clb.begin(),clb.end());
			if(crxis.find(clb)!=crxis.end()) f[i]+=f[j];
			if(!j) break;
		}
	}
	printf("%lld\n",f[(1<<n)-1]);
	return 0;
}
int main(){
//	#ifdef LOCAL
	 	freopen("hack.in","r",stdin);
//	#endif
	sshwy();
	for(scanf("%*d");cin>>s;memset(f,0,sizeof f),mian());
	return 0;
}


