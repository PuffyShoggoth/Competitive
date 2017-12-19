#include <string>
#include <iostream>
using namespace std;

bool dn[300];
int main() {
	int r, c, tpi;
	string tps;
	dn[46]=1;
	cin>>c>>r;
	getline(cin, tps);
	int tt=0, dd=0;
	for(int i=0; i<r; i++){
		getline(cin, tps);
		for(int j=0; j<tps.size(); j++){
			if (tps[j]==' ') continue;
			if (!dn[tps[j]]){ tt++; }
			dn[tps[j]]=1;
			tt++; dd++;
		}
	}
	cout<<tt;
	return 0;
}