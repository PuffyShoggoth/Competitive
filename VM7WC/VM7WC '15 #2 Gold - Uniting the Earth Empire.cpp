#include <cstdio>
#include <vector>
using namespace std;

vector<long long int> heights, hills;


int main(){
	int n;
	long long int tph;
	scanf("%i", &n);
	long long int tt = 0;
	for(int i=0; i<n; i++){
		scanf("%lli", &tph);
		while(heights.size()>0 && heights.back()<tph){
			tt += hills.back();
			if (heights.size()>1){tt+= hills.back(); }
			hills.pop_back();
			heights.pop_back();
		}
		
		if(heights.size() && heights.back() == tph){
		    tt+= hills.back();
			hills.back()+=1;
		}
		else{
			heights.push_back(tph);
			hills.push_back(1);
		}
	}
	while(heights.size()>1){
		tt+= hills.back();
		heights.pop_back();
		hills.pop_back();
	}
	printf("%lli", tt);
	return 0;
}