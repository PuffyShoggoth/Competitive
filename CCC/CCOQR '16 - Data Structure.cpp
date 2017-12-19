#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > fksht;
long long int tot(long long int cc, long long int ccm, long long int n){
	if (ccm+cc>n) return 0;
	else if (ccm+cc==n) return 1;
	return ((n-ccm-cc+1)*(n-ccm-cc+2)/2);
}
int main() {
	int m, n, ri, ci;
	long long int pv, tt;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i", &ri, &ci);
		fksht.push_back(make_pair(ci, ri-ci));
	}
	sort(fksht.begin(), fksht.end());
	pv=n+1; tt=0;
	for(int i=0; i<fksht.size(); i++){
		if (fksht[i].second>=pv) continue;
		tt+=tot(fksht[i].first, fksht[i].second, n);
		tt-=tot(fksht[i].first, pv, n);
		pv=fksht[i].second;
	}
	printf("%lli", tt);
	return 0;
}