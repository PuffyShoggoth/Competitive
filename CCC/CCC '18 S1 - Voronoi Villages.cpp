#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
vector<int> vlgs;

int main() {
	int n, vi;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i", &vi);
		vlgs.push_back(vi);
	}
	sort(vlgs.begin(), vlgs.end());
	double mn = INF;
	for(int i=1; i<n-1; i++){
		mn = min(mn, (vlgs[i]-vlgs[i-1])/2.0+(vlgs[i+1]-vlgs[i])/2.0);
	}
	printf("%.1f", mn);
    return 0;
}