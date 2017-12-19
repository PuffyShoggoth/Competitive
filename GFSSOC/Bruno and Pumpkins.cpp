#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> p;
vector <int> n;
int main() {
	int np, cp, mp=5000;
	unsigned int tp;
	cin>>np>>tp;
	p.push_back(0);
	n.push_back(0);
	for (int i=0; i<np; i++){
		cin>>cp;
		if (cp>0){p.push_back(cp);}
		else {n.push_back(cp*-1);}
	}
	sort(n.begin(), n.end());
	sort(p.begin(), p.end());
	for (int i=1; i<min(p.size(), tp+2); i++){
		if (i+n.size()>tp){
			mp=min(mp, p[i]+2*n[tp-i]);
		}
	}
	for (int i=1; i<min(n.size(), tp+2); i++){
		if (i+p.size()>tp){
			mp=min(mp, n[i]+2*p[tp-i]);
		}
	}
	cout<<mp;
	return 0;
}