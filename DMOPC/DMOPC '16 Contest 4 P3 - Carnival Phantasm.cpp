#include <cstdio>
#include <set>
#include <algorithm> 
#include <utility>
#include <vector>
using namespace std;
set<pair<int, int> > apples[105];
int stalls[100005];
int main() {
	int n, s, si, ai;
	scanf("%i %i", &n, &s);
	for(int i=1; i<=n; i++){
		scanf("%i", &stalls[i]);
	}
	for(int i=0; i<s; i++){
		scanf("%i%i", &si, &ai);
		apples[ai].insert(make_pair(stalls[si], si));
	}
	set<pair<int, int> >::iterator it;
	int q, x, k; char tp;
	scanf("%i", &q);
	for(int i=0; i<q; i++){
		do{tp=getchar();}while(tp!='A' && tp!='S' && tp!='E' && tp!='Q');
		if (tp=='A'){
			scanf("%i%i", &x, &k);
			apples[k].insert(make_pair(stalls[x], x));
		}
		else if (tp=='S'){
			scanf("%i%i", &x, &k);
			it=apples[k].find(make_pair(stalls[x], x));
			if (it!=apples[k].end()){
				apples[k].erase(it);
			}
		}
		else if (tp=='E'){
			scanf("%i%i", &x, &k);
			for(int i=1; i<100; i++){
				it=apples[i].find(make_pair(stalls[x], x));
				if (it!=apples[i].end()){
					apples[i].erase(it);
				}
			}
			stalls[x]=k;
		}
		else{
			scanf("%i", &k);
			if (apples[k].empty()){
				printf("-1\n");
			}
			else{
				printf("%i\n", apples[k].begin()->second);
			}
		}
		
	}
	return 0;
}