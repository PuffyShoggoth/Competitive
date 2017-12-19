#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int ln[100009];
vector<pair<int, int> > edges;
int root(int i){
	while (ln[i]!=0){
		i=ln[i];
	}
	return i;
}
int main() {
	int k, n, t, ra, rb, wt=0;
	scanf("%i%i", &n, &k);
	for (int i=k+1; i<=n; i++){
		ln[i]=root(i-k);
	}
	for (int i=1; i<n; i++){
		scanf("%i", &t);
		edges.push_back(make_pair(t, i));
	}
	sort(edges.begin(), edges.end());
	for (int i=0; i<(n-1); i++){
		ra=root(edges[i].second); rb=root(edges[i].second+1);
		if (ra==rb){continue;}
		wt+=edges[i].first;
		ln[max(ra, rb)]=min(ra, rb);
	}
	cout<<wt;
	return 0;
}