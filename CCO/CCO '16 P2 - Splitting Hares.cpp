#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
vector<pair<pair<int, int>, int> > hares;
vector<pair<double, pair<int, bool> > > oth;
inline double slope(pair<int, int> a, pair<int, int> b){
	return ((double)(a.second-b.second))/((double)(a.first-b.first));
}
int main(){
	int n, x, y, w, rsm, lsm, mb, mt, rt, lt, mxw=0;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i%i%i", &x, &y, &w);
		hares.push_back({{x, y}, w});
	}
	for(auto tp: hares){
		rt=0; lt=0; mb=0; mt=0; oth.clear();
		for(auto sp: hares){
			if (tp.first.first>sp.first.first){
				oth.push_back({slope(tp.first, sp.first), {sp.second, 0}});
				lt+=sp.second;
			}
			else if (tp.first.first<sp.first.first){
				oth.push_back({slope(tp.first,sp.first), {sp.second, 1}});
				rt+=sp.second;
			}
			else{
				if (tp.first.second<sp.first.second){
					mt+=sp.second;
				}
				else if (tp.first.second>sp.first.second){
					mb+=sp.second;
				}
			}
		}
		mxw=max(mxw, max(lt, rt)+(mt+mb+tp.second)>0?(mt+mb+tp.second):0);

		sort(oth.begin(), oth.end());
		rt+=mt; lt+=mb;
		int s1=0;
		y=max(tp.second, 0);
		while(s1<oth.size()){
			mb=0; mt=0;
			mxw=max(mxw, max(rt, lt)+y);
			double d=oth[s1].first;
			while(s1<oth.size() && abs(oth[s1].first-d)<10E-9){
				if (oth[s1].second.second){
					mt+=oth[s1].second.first;
				}
				else{
					mb+=oth[s1].second.first;
				}
				s1++;
			}
			rt-=mt; lt-=mb;
			mxw=max(mxw, max(lt, rt)+(mt+mb+tp.second)>0?(mt+mb+tp.second):0);
			rt+=mb; lt+=mt;

		}
		mxw=max(mxw, max(rt, lt)+y);

	}
	printf("%i", mxw);



}