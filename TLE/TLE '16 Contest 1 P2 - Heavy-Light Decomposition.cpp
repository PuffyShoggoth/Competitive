#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int occ[100090];
int boxes[1009];
int main() {
	int n, wi, tmode=0, nmode=0, noc=0, tt;
	double median, mode, amean=0, mnav;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i", &boxes[i]);
		amean+=boxes[i];
		occ[boxes[i]]+=1;
	}
	sort(boxes, boxes+n);
	median=boxes[(n-1)>>1];
	for(int i=0; i<=boxes[n-1]; i++){
		if (occ[i]>nmode){mode=i; tmode=1; nmode=occ[i];}
		else if (occ[i]==nmode){mode+=i; tmode+=1;}
	}
	mnav=min(median, min(floor(mode/tmode), floor(amean/n)));
	tt=n;
	for(int i=0; i<n; i++){
		if (mnav<boxes[i]){tt=i; break;}
	}
	printf("%i", tt);
	return 0;
}