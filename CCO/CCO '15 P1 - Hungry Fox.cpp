#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> cold, hot;
long long int gh(int pv, int h, int tp, int w){
	long long int mx=0;
	while(h>=tp){
		mx+=max(pv-hot[tp], hot[tp]-w);
		if (h>tp){ mx+=hot[h]-w; }
		pv=hot[h]; tp++; h--;
	}
	return mx;
}
long long int gc(int pv, int c, int tp, int w){
	long long int mx=0;
	while(tp>=c){
		mx+=max(cold[tp]-pv, w-cold[tp]);
		if (c<tp){ mx+=w-cold[c]; }
		pv=cold[c]; c++; tp--;
	}
	return mx;
}
	
int main() {
	int n, w, tp;
	scanf("%i%i", &n, &w);
	for(int i=0; i<n; i++){
		scanf("%i", &tp);
		if (tp<w){
			cold.push_back(tp);
		}
		else{
			hot.push_back(tp);
		}
	}
	sort(cold.begin(), cold.end()); sort(hot.begin(), hot.end());
	int pv=w; long long int mx=0, tpmx=0, mn=0;
	for(int i=cold.size()-1; i>=0; i--){
		mn+=pv-cold[i]; pv=cold[i];
	}
	pv=w;
	for(int i=0; i<hot.size(); i++){
		mn+=hot[i]-pv; pv=hot[i];
	}
	int c=0, h=hot.size()-1, pv2=w; pv=w;
	while(c<cold.size() && h>=0){
		mx+=pv-cold[c]+hot[h]-cold[c];
		tpmx+=hot[h]-pv2+hot[h]-cold[c];
		pv2=cold[c]; pv=hot[h]; c++; h--;
	}
	if (h>=0){ 
		tpmx+=hot[h]-pv2; pv2=hot[h]; 
		tpmx+=gh(pv2, h-1, 0, w); 
		mx+=gh(pv, h, 0, w);
	}
	else if (cold.size()-1>=c){
		mx+=pv-cold[c]; pv=cold[c];
		mx+=gc(pv, c+1, cold.size()-1, w);
		tpmx+=gc(pv2, c, cold.size()-1, w);
	}
	printf("%lli %lli", mn, max(mx, tpmx));
	return 0;
}