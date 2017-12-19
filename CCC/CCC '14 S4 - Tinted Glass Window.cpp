#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
using namespace std;
set<pair<int, int> > active;
set<pair<int, int> >::iterator itr;
vector<pair<pair<int, int>, pair<int, int> > >windows;
int tints[1009];
int main() {
	long long int n, t, a, b, c, d, tpt, ta=0, tt=0, i=1, cs, pr; 
	pair<set<pair<int, int> >::iterator, int> baha;
	scanf("%lli%lli", &n, &t);
	for(int i=0; i<n; i++){
		scanf("%lli%lli%lli%lli%lli", &a, &b, &c, &d, &tpt);
		tints[i]=tpt;
		windows.push_back(mp(mp(a, i), mp(b, d)));
		windows.push_back(mp(mp(c, i), mp(b, d)));
	}
	sort(windows.begin(), windows.end());
	active.insert(mp(windows[0].s.f, windows[0].f.s));
	active.insert(mp(windows[0].s.s, windows[0].f.s));
	if(tints[windows[0].f.s]>=t){ta=windows[0].s.s-windows[0].s.f;}
	while(i<windows.size()){
		tt+=ta*(windows[i].f.f-windows[i-1].f.f);
		do{
		baha=active.insert(mp(windows[i].s.f, windows[i].f.s));
		if(baha.s==false){active.erase(baha.f);}
		baha=active.insert(mp(windows[i].s.s, windows[i].f.s));
		if(baha.s==false){active.erase(baha.f);}
		i+=1;
		}
		while(i<windows.size() && windows[i].f.f==windows[i-1].f.f);
		itr=active.begin(); 
		ta=0; cs=0; pr=(*itr).f;
		while(itr!=active.end()){
		if(cs>=t){ta+=(*itr).f-pr;}
		do{cs+=tints[(*itr).s]; pr=(*itr).f; tints[(*itr).s]*=-1; ++itr;}
		while(itr!=active.end() && (*itr).f==pr);
		}
	}
	printf("%lli", tt);
	return 0;
}