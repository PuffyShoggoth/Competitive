#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <utility>
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef pair<int, int> pii;
map<int, vector<pair<bool, pii> > > horz;
map<int, vector<pair<bool, pii> > > vert;
multiset<pii> curr;
int csm(){
	int on=0, tot=0;
	for(auto it = curr.begin(); it!=curr.end(); ++it){
		if (it->second){
			on--;
			if (!on)tot+=1;
		}
		else{
			on++;
			if (on==1) tot+=1;
		}
	}
	return tot;
}
int ttsm(map<int, vector<pair<bool, pii> > > cvct){
	int pv, tt=0; pii tpa, tpb;
	for(auto i = cvct.begin(); i!=cvct.end(); ++i){
		tt+=(csm()*(i->first-pv)); pv=i->first;
		for(auto j = i->second.begin(); j!=i->second.end(); ++j){
			tpa=mp(j->second.first, 0); tpb=mp(j->second.second, 1);
			if (j->first){ 
				curr.erase(curr.find(tpa)); curr.erase(curr.find(tpb));
			}
			else{
				curr.insert(tpa); curr.insert(tpb);
			}
		}
	}
	return tt;
}

int main() {
	int n, llx, lly, urx, ury;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i%i%i%i", &llx, &lly, &urx, &ury);
		horz[llx].push_back(mp(0, mp(lly, ury)));
		horz[urx].push_back(mp(1, mp(lly, ury)));
		vert[lly].push_back(mp(0, mp(llx, urx)));
		vert[ury].push_back(mp(1, mp(llx, urx)));
	}
	printf("%i", ttsm(horz)+ttsm(vert));
	return 0;
}