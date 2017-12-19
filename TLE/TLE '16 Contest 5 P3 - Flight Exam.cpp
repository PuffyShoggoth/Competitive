#include <bits/stdc++.h>
using namespace std;
vector<pair<long long int, long long int> > chk;
set<pair<long long int, long long int> >dn;
long long int mv[2005];
bool pob[2005];
int main() {
	int n;
	long long int t, d, s, ta, td, mx=0;
	scanf("%i%lli%lli%lli", &n, &t, &d, &s);
	for(int i=0; i<n; i++){
		scanf("%lli%lli", &td, &ta);
		if (ta>=s) { chk.push_back(make_pair(td, ta-s)); }
		chk.push_back(make_pair(td, ta));
		dn.insert(make_pair(td, ta));
	}
	chk.push_back(make_pair(0, 0));
	pob[0]=1;
	sort(chk.begin(), chk.end());
	for(int i=1; i<chk.size(); i++){
		for(int j=0; j<i; j++){
			if (chk[i].first == chk[j].first){
				continue;
			}
			else if (chk[i].second>chk[j].second){
				if (chk[i].second-chk[j].second<=(chk[i].first-chk[j].first)*t){
					mv[i]=max(mv[i], mv[j]);
					pob[i]|=pob[j];
				}
			}
			else{
				if (chk[j].second-chk[i].second<=(chk[i].first-chk[j].first)*d){
					mv[i]=max(mv[i], mv[j]);
					pob[i]|=pob[j];
				}
			}
		}
		if (pob[i]){
			if (dn.find(chk[i])!=dn.end()){mv[i]++;}
			if (s!=0 && dn.find(make_pair(chk[i].first, chk[i].second+s))!=dn.end()){ mv[i]++;}
		}
		mx=max(mx, mv[i]);
	}
	printf("%lli", mx);
	return 0;
}