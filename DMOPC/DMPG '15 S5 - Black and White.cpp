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
set<int> active;
set<int>::iterator itr;
vector<pair<int, pair<int, int> > >rectangles;
int main() {
	int n, m, x, y, w, h, ps=0, twhite=0, cw=0, ce=0; pair<set<int>::iterator, bool> fpos, spos;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i%i%i", &x, &y, &w, &h);
		rectangles.push_back(mp(x, mp(y, h)));
		rectangles.push_back(mp(x+w, mp(y, h)));
	}
	sort(rectangles.begin(), rectangles.end());
	ps=rectangles[0].s.s;
	active.insert(rectangles[0].s.f+rectangles[0].s.s);
	active.insert(rectangles[0].s.f);
	for(int i=1; i<rectangles.size(); i++){
		twhite+=ps*(rectangles[i].f-rectangles[i-1].f);
		spos=active.insert(rectangles[i].s.f+rectangles[i].s.s);
		fpos=active.insert(rectangles[i].s.f);
		if (spos.s==false){active.erase(spos.f);}
		if (fpos.s==false){active.erase(fpos.f);}
		cw=0; ce=0; ps=0;
		for(itr=active.begin(); itr!=active.end(); ++itr){
			if (cw==0){cw=1;}
			else{ps+=*itr-ce; cw=0;}
			ce=*itr;	
		}
	}
	printf("%i", twhite);
	return 0;
}