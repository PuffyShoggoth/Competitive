#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
const int INF = 0x3f3f3f3f;
unordered_map<int, long long int> vls;
long long int dpv[1000005];
//this differs from my wa solution on CCC by, like, an equals sign and an if statement >:-(
long long int dp(int w){
	if(w==1 || w==2){return 1;}
	if(w==0){return 0;}
	if(w<=MAX){if(dpv[w]){return dpv[w];}}
	else{if(vls.count(w)){return vls[w];}}
	//heaviest a tree can be is w/2
	//lightest a tree can be is 1
	//for weights > sqrt(n)
	//you can have at most sqrt(w) trees
	int sqt = sqrt(w);
	long long int tt = 0;
	for(int i=1; i<=sqt; i++){
		long long int tpi = floor(w/i);
		long long int tpi1 = floor(w/(i+1));
		long long int dv = floor(w/i);
		if(i!=1 && dv>sqt){
			tt+=dp(dv);
		}
		tt+=dp(i)*(tpi-tpi1);
	}
	if(w<=MAX){
		dpv[w]=tt;
	}
	else{vls[w]=tt;}
	return tt;
}
int main() {
	long long int n;
	scanf("%lli", &n);
	printf("%lli", dp(n));
    return 0;
}