#include <iostream>
#include <set>
#include <functional>
#include <cstdio>
using namespace std;
set<int, greater<int> >gates;
set<int, greater<int> >::iterator open;
int main() {
	int g, p, gi, lp=0;
	scanf("%i%i", &g, &p);
	for(int i=1; i<=g; i++){
		gates.emplace(i);
	}
	for(int i=0; i<p; i++){
		scanf("%i", &gi);
		open=gates.lower_bound(gi);
		if (open==gates.end()){break;}
		else{
			gates.erase(open); lp++;
		}
	}
	printf("%i", lp);
	return 0;
}