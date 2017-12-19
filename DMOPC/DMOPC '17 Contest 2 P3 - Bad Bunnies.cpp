#include <bits/stdc++.h>

using namespace std;
vector<int> edges[200005];
bool rab[200005];
int mnd = 99999999;
int hch[200005];
bool mrk(int cn, int par, int dst){
	if (cn==dst) return 1;
	for(int i: edges[cn]){
		if (i==par) continue;
		if (mrk(i, cn, dst)){
			hch[cn]=i;
			return 1;
		}
	}
	return 0;
}
void dmn(int cn, int par, int dst){
	if (dst>=mnd) return;
	if (rab[cn]){
		mnd = min(mnd, dst);
		return;
	}
	for(int i: edges[cn]){
		if (i!=par) dmn(i, cn, dst+1);
	}
	return;
}
int main(){
	int n, nr, a, b, r;
	scanf("%i%i", &n, &nr);
	for(int i=1; i<n; i++){
		scanf("%i%i", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i=0; i<nr; i++){
		scanf("%i", &r);
		rab[r]=1;
	}
	int x, y;
	scanf("%i%i", &x, &y);
	mrk(x, 0, y);
	int par = 0;
	while(x){
		if (rab[x]){
			mnd = 0;
			break;
		}
		for(int i: edges[x]){
			if (i!=par && i!= hch[x]){
				dmn(i, x, 1);
			}
		}
		par = x;
		x = hch[x];
	}
	printf("%i", mnd);
	return 0;
}