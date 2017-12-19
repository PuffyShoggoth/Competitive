#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <deque>
using namespace std;
vector <int> cbns[515];
pair<int, int> pbns[515];
int flg[515];
int rds[515];
int bfs(int a, int b){
	for (int i=0; i<504; i++){
		flg[i]=0;
	}
	int m;
	deque <int> ts;
	ts.push_back(a);
	while (ts.size()>0){
		m=ts[0];
		ts.pop_front();
		if (m==b){return 1;}
		if (flg[m]!=-1){
			flg[m]=-1;
			for (unsigned int i=0; i<cbns[m].size(); i++){
					ts.push_back(cbns[m][i]);
			}
		}
	}
	return 0;
}
int main() {
	int q, b, x, y, r, qa, qb, xi, yi;
	cin>>b>>q;
	for (int i=1; i<=b; i++){
		cin>>x>>y>>r;
		pbns[i]=make_pair(x, y);
		rds[i]=r;
		for (int k=1; k<i; k++){
			xi=abs(pbns[k].first-x);
			yi=abs(pbns[k].second-y);
			if (xi*xi+yi*yi<=rds[k]*rds[k]){
				cbns[k].push_back(i);}
			if (xi*xi+yi*yi<=r*r){
				cbns[i].push_back(k);
			}
		}
	}
	for (int pp=0; pp<q; pp++){
		cin>>qa>>qb;
		int l=bfs(qa, qb);
		if (l==1){
			cout<<"YES\n";
		}
		else{cout<<"NO\n";}
	}
	
	return 0;
}