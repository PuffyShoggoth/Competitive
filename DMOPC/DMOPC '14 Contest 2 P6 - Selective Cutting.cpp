#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int bit[100005];
int ans[100005];
int n;
void update(int ind, int val){
	for(int i=ind; i<=n; i+=i&-i){
		bit[i]+=val;
	}
	return;
}
int sm(int ind){
	int tp=0;
	for(int i=ind; i>0; i-=i&-i){
		tp+=bit[i];
	}
	return tp;
}
vector<pair<int, int> > trees;
vector<pair<pair<int, int>, pair<int, int> > >qrs;
int main() {
	scanf("%i", &n);
	int m;
	for(int i=1; i<=n; i++){
		scanf("%i", &m);
		trees.push_back(make_pair(m, i));
	}
	sort(trees.begin(), trees.end());
	int q, a, b;
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		scanf("%i%i%i", &a, &b, &m);
		qrs.push_back(make_pair(make_pair(m, i), make_pair(a+1, b+1)));
	}
	sort(qrs.begin(), qrs.end());
	int ftree=n-1;
	for(int i=qrs.size()-1; i>=0; i--){
		while(ftree>=0 && trees[ftree].first>=qrs[i].first.first){
			update(trees[ftree].second, trees[ftree].first);
			ftree--;
		}
		
		ans[qrs[i].first.second]=sm(qrs[i].second.second)-sm(qrs[i].second.first-1);
	}
	for(int i=0; i<q; i++){
		printf("%i\n", ans[i]);
	}
	return 0;
}