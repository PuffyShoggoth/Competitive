#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double PI = 3.1415926535;
vector<pair<pair<int, int>, int> > circs;
//needs to go from (0,a) or (a,Y) to (X, a) or (a, 0)
//0, 0
//cat bleh bleh bleh
//bleh bleh bleh bleh
//bleh bleh bleh bleh
//bleh bleh bleh mouse
//               X, Y
//in the ideal situation, no more than two lamps will cover a single area
vector<pair<double, int> > edges[1005];
bool dn[1005];
bool ed[1005];
double ans[1005];
double circA(int r){
	return r*r*PI;
}

inline int sq(int a){ return a*a;}
int dstsq(pair<int, int> a, pair<int, int> b){
	return sq(a.first-b.first)+sq(a.second-b.second);
}
priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;

int main() {
	int n, X, Y;
	scanf("%i%i%i", &n, &X, &Y);
	int tx, ty, tr;
	for(int i=0; i<n; i++){
		scanf("%i%i%i", &tx, &ty, &tr);
		if (tx<=tr || Y-ty<=tr){pq.push({circA(tr), i});}
		if(ty<=tr || X-tx<=tr){ed[i]=1; }
		circs.push_back({{tx, ty},tr});
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int sqd=dstsq(circs[i].first, circs[j].first);
			if(sqd<=sq(circs[i].second-circs[j].second)){continue;}
			if(sqd>sq(circs[i].second+circs[j].second)){continue;}
			if(sqd==sq(circs[i].second+circs[j].second)){
				edges[i].push_back({circA(circs[j].second), j});
				continue;
			}
			double d = sqrt(sqd);
			double a = (sq(circs[j].second)-sq(circs[i].second)+sqd)/(2.0*d);
			double h = sqrt(sq(circs[j].second)-a*a);
			double sect = atan2(h, a)*sq(circs[j].second)-h*a+atan2(h, d-a)*sq(circs[i].second)-h*(d-a);
			edges[i].push_back({circA(circs[j].second)-sect, j});
			edges[j].push_back({circA(circs[i].second)-sect, i});
			}
	}
	double fans=0;
	while(!pq.empty()){
		auto tp = pq.top();
		pq.pop();
		if(dn[tp.second]) continue;
		dn[tp.second]=1;
		//printf("%.7f %i\n", tp.first, tp.second);

		if(ed[tp.second]){fans=tp.first; break;}
				for(auto tpp: edges[tp.second]){
			if(!dn[tpp.second]){
				//printf("%i %.7f\n", tpp.second, tpp.first); 
				pq.push({tp.first+tpp.first, tpp.second});
			}
		}
	}
	printf("%.7f", fans);
    return 0;
}