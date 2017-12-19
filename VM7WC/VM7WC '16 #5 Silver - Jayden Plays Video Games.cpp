#include <bits/stdc++.h>

using namespace std;

int dpl[1005], dpr[1005];
vector<pair<int, int> > trees;
int main(){
	int n, p, h, a, b;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i%i", &a, &b);
		trees.push_back({a,b});
	}
	sort(trees.begin(), trees.end());
	for(int i=0; i<trees.size(); i++){
		int tp = i-1; dpl[i+1]=min(dpl[i]+1, dpr[i]+1);
		while(tp>=0 && trees[tp].first>= trees[i].first-trees[i].second){
			dpl[i+1] = min(dpl[i+1], dpl[tp+1]);
			tp--;
		}
		if (!dpr[i+1]){
			dpr[i+1] = min(dpr[i]+1, dpl[i]+1);
		}
		else{
			dpr[i+1] = min(dpr[i+1], min(dpr[i]+1, dpl[i]+1));
		}
		for(int j=i+1; j<trees.size(); j++){
			if (trees[j].first>trees[i].first+trees[i].second){ break; }
			if (dpr[j+1]) { dpr[j+1] = min(dpr[j+1], dpr[i+1]); }
			else{ dpr[j+1] = dpr[i+1]; }
		}
	}
	printf("%i\n", min(dpr[n], dpl[n]));
}