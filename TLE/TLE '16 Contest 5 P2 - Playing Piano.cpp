#include <cstdio>
using namespace std;
int notes[100005];
bool inch[12][12];
int jmps[5]={0, 4, 3, 3, 2};
int main() {
	int n, k, tp, st, ed, mx=0;
	scanf("%i%i", &n, &k);
	for(int i=0; i<n; i++){
		scanf("%i", &tp);
		notes[i]=tp%12;
	}
	for(int i=0; i<12; i++){
		tp=i;
		for(int j=0; j<5; j++){
			tp=(tp+jmps[j])%12; inch[i][tp]=1;
		}
		st=0; ed=0; tp=0;
		while(ed<n){
			while(ed<n && tp+!inch[i][notes[ed]]<=k){
				tp+=!inch[i][notes[ed]]; ed++; 
			}
			if (ed-st>mx){ mx=ed-st; }
			if (ed<n){ tp+=!inch[i][notes[ed]]; ed++; }
			while(st<=ed && tp>k){
				tp-=!inch[i][notes[st]]; st++;
			}
			if (st>ed){ st=ed; tp=0; }
			if (ed-st>mx && ed<n) {mx=ed-st;}
		}
	}
	printf("%i", mx);
	return 0;
}