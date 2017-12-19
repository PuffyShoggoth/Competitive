#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<int> good;
vector<int> bad;
int main() {
	int m, n, si, pi, g=0, b=0, sm=0, su=0;
	scanf("%i%i", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%i%i", &si, &pi);
		if (pi==1){bad.push_back(si);}
		else{good.push_back(si);}
	}
	sort(bad.begin(), bad.end());
	sort(good.begin(), good.end());
	while(1==1){
		if (g<good.size() && ((b>=bad.size()) or ((good[g]/2+good[g]%2)<=bad[b])) && su+good[g]<=m){
			sm+=2; su+=good[g]; g++; continue;
		}
		if (b<bad.size() && su+bad[b]<=m){
			sm++; su+=bad[b]; b++; continue;
		}
		break;
	}
	cout<<sm;
	return 0;
}