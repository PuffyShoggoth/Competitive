#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> items;

int main() {
	int t, n, w, st, ed, tt;
	scanf("%i", &t);
	for(int donotreuse=1; donotreuse<=t; donotreuse++){
		scanf("%i", &n);
		tt=0;
		items.clear();
		for(int i=0; i<n; i++){
			scanf("%i", &w); items.push_back(w);
		}
		sort(items.begin(), items.end());
		st=0; ed=items.size()-1;
		while(ed>=0 && (ed-st+1)*items[ed]>=50){
			if (items[ed]>=50) { ed--; } 
			else if (50%items[ed]==0){ 
				st+=((50/items[ed])-1);
				ed--;
			}
			else{
				st+=(50/items[ed]);
				ed--;
			}
			tt++;
		}
		printf("Case #%i: %i\n", donotreuse, tt);
	}
	return 0;
}