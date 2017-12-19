#include <bits/stdc++.h>

using namespace std;
vector<int> bat;
int main(){
	int n, k, t;
	scanf("%i", &t);
	int st=1, tp=0;
	while(tp<1e9){
		tp+=st*(st+1)/2;
		bat.push_back(tp);
		st++;
	}
	for(int i=0; i<t; i++){
		scanf("%i%i", &n, &k);
		n-=k;
		auto it = upper_bound(bat.begin(), bat.end(), n);
		--it;
		printf("%i\n", *it);
	}
}