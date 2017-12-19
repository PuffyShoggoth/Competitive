#include <bits/stdc++.h>

using namespace std;

int cards[200005];
priority_queue<int, vector<int>, greater<int> >avb;
int main(){
	int n;
	scanf("%i", &n);
	int nc=0;
	for(int i=0; i<n; i++){
		scanf("%i", &cards[i]);
	}
	int clv=0, pvc=0;
	avb.push(cards[0]);
	while(avb.size()){
		if (clv>=n){ break; }
		while (avb.top()<=pvc){ avb.pop(); }
		if (avb.size()){
			nc++;
			pvc = avb.top();
			avb.pop();
			if (clv+pvc>=n){ clv+=pvc; break; }
			for(int i=clv; i<=clv+pvc; i++){
				if (cards[i]>pvc){ avb.push(cards[i]); }
			}
			clv+=pvc;
		}
	}
	if (clv<n){printf("-1"); }
	else{printf("%i", nc);}
	return 0;
}