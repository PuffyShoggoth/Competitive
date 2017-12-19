#include <cstdio>
#include <vector>
#include <algorithm> 
#include <utility>
using namespace std;
vector<pair<pair<int, int>, int> >cs;
vector<int> fail;
int main() {
	int b, f, e, p, nf, fvl;
	scanf("%i", &b);
	for(int i=0; i<b; i++){
		scanf("%i%i%i", &f, &e, &p);
		cs.push_back(make_pair(make_pair(f, e), p));
	}
	scanf("%i", &nf);
	for(int i=0; i<nf; i++){
		scanf("%i", &fvl);
		fail.push_back(fvl);
	}
	sort(fail.begin(), fail.end());
	vector<int>::iterator low, high;
	int tot=0;

	for(auto it=cs.begin(); it!=cs.end(); ++it){
		if(!fail.size() || it->first.second<fail[0] || it->first.first>fail.back()){
			tot+=it->second;
		}
		else{
			low=lower_bound(fail.begin(), fail.end(), it->first.first);
			high=upper_bound(fail.begin(), fail.end(), it->first.second);
			--high;
			if (!((*low)<=it->first.second || (*high)>=it->first.first)){
				tot+=it->second;
			}
		}
	}
	printf("%i", tot);
	return 0;
}