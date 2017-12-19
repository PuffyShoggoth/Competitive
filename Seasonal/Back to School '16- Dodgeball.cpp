#include <iostream>
#include <string>
#define MOD 1000000007
#include <vector>
using namespace std;

vector<int> groups;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string tmps;
	long long int n, pv=0, tt=0;
	char pvc=' ';
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>tmps;
		if (tmps[0]==pvc){
			pv+=1;
		}
		else{
			pvc=tmps[0];
			groups.push_back(pv);
			pv=1;
		}
	}
	groups.push_back(pv);
	for(int i=0; i<groups.size(); i++){
		tt=(tt+(((groups[i])*(groups[i]+1)/2)%MOD))%MOD;
	}
	cout<<tt;
	return 0;
}