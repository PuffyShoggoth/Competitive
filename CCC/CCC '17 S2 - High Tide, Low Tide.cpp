#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> tides;

int main(){
	int n;
	int sc;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i", &sc);
		tides.push_back(sc);
	}
	sort(tides.begin(), tides.end());
	int st=n/2-1+n%2, ed=n/2+n%2;
	while(ed<n){
		printf("%i %i ", tides[st], tides[ed]);
		st--; ed++;
	}
	if (st==0){
		printf("%i", tides[st]);
	}
}