#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > ppl;

priority_queue<int, vector<int>, greater<int> > pq;
int main(){
	int n, a, b;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i%i", &a, &b);
		ppl.push_back({-a, b});
	}
	sort(ppl.begin(), ppl.end());
	int pb=0, tot=0;
	for(int i=0; i<n; i++){
		pq.push(ppl[i].second);
		if (pb+n-1-i< -ppl[i].first){ tot+=pq.top(); pq.pop(); pb++; }
	}
	printf("%i", tot);
	return 0;
}