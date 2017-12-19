#include <bits/stdc++.h>
using namespace std;
set<string> dict;
string curr;
int dp[2009];
int gmn(int pos){
	if (pos>=curr.size()){ return 0; }
	if (dp[pos]!=-1) return dp[pos];
	int mn=-2, tp;
	for(int i=1; i<=curr.size()-pos; i++){
		if (dict.find(curr.substr(pos, i))!=dict.end()){
			tp = gmn(pos+i);
			if (mn==-2){ mn = tp; }
			else if (mn> tp && tp!=-2){ mn=tp; }
		}
	}
	if (mn!=-2){ mn++; }
	dp[pos]=mn;
	return mn;
}
int main(){
	int n;
	cin>>n;
	string a;
	while(n--){
		cin>>a;
		dict.insert(a);
	}
	for(int dnr=0; dnr<10; dnr++){
		memset(dp, -1, sizeof(dp));
		cin>>curr;
		cout<<gmn(0)-1<<"\n";
	}
	return 0;
}