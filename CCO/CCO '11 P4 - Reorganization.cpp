#include <bits/stdc++.h>
using namespace std;

map<int, int> spvs;

int main(){
	int n;
	scanf("%i", &n);
	bool pos = 1;
	int rnk;
	scanf("%i", &rnk);
	spvs[rnk] = 2;
	for(int i=1; i<n; i++){
		scanf("%i", &rnk);
		auto it = spvs.lower_bound(rnk);
		if (it == spvs.begin()){
			pos = 0; break;
		}
		--it;
		it->second -= 1;
		if (it->second == 0){
			spvs.erase(it);
		}
		spvs[rnk] = 2;
	}
	if (pos){
		printf("YES");
	}
	else{
		printf("NO");
	}
}