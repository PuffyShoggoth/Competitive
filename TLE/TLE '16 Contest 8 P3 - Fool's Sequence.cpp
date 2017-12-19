#include <bits/stdc++.h>
using namespace std;
vector<long long int> nv, cs;

int main(){
	long long int mval = 1000000000000009;
	nv.push_back(0); nv.push_back(0); nv.push_back(1); nv.push_back(1);
	cs.push_back(0); cs.push_back(0); cs.push_back(1); cs.push_back(2);
	long long int tsm = 2, tp=0;
	int nd = 4;
	while(tsm<=mval){
		tp = nv[nd-2]+nv[nd-3];
		nv.push_back(tp);
		tsm+=tp;
		cs.push_back(tsm);
		nd++;
	}
	int t;
	long long int n;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		scanf("%lli", &n);
		int ind = lower_bound(cs.begin(), cs.end(), n)-cs.begin();
		n-=cs[ind-1];
		while(n>0){
			if (ind<2){break;}
			if (ind ==2){printf("69"); break;}
			if (ind==3){printf("420"); break;}
			if (nv[ind-3]<n){
				printf("69"); n-=nv[ind-3]; ind-=2;
			}
			else{
				printf("420"); ind-=3;
			}
		}
		printf("\n");
	}
	return 0;
}