#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
unordered_set<string> np;
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, m, tt=0;
	string tmp, prv;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>tmp;
		np.insert(tmp);
	}
	cin>>tmp;
	for(int i=1; i<m; i++){
	    prv=tmp;
		cin>>tmp;
		if (tmp==prv) continue;
		else if (np.count(prv)) tt+=1;
	}
	if (np.count(tmp)){tt+=1;}
	cout<<tt;
	return 0;
}