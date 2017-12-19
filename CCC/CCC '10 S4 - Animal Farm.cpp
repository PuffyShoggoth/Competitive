#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;
int cpe[20];
int m;
vector<pair<pair <int, int>, int> > sides[1009];
vector<pair<int, pair<int, int> > >edges;
int dsj[109];
int root(int i){
	while (dsj[i]!=0){
		i=dsj[i];
	}
	return i;
}
int mst(){
	int tt=0, ra, rb;
	sort(edges.begin(), edges.end());
	for(int i=0; i<=edges.size(); i++){
		ra=root(edges[i].second.first);
		rb=root(edges[i].second.second);
		if (ra!=rb){
			dsj[max(ra, rb)]=min(ra, rb);
			tt+=edges[i].first;
		}
		
	}
	return tt;
}
int main() {
	int ea, eb, w, p, ina, ti, tot, sj=0;
	scanf("%i", &m);
	for(int i=1; i<=m; i++){
		scanf("%i", &p);
		for (int k=0; k<(p*2); k++){
			scanf("%i", &cpe[k]);
		}
		for(int k=0; k<p; k++){
			ina=0; 
			ea=min(cpe[k], cpe[(k+1)%p]); 
			eb=max(cpe[k], cpe[(k+1)%p]);
			for(int y=0; y<sides[ea].size(); y++){
			if(sides[ea][y].first.first==eb){
				edges.push_back(make_pair(cpe[k+p], make_pair(sides[ea][y].second, i)));
				ina+=1; sides[ea][y].first.first=-1; break;}
			}
			if (ina==0){sides[ea].push_back(make_pair(make_pair(eb, cpe[k+p]), i));}
		}
	}
	ti=mst();
	for (int i=1; i<=m; i++){if (dsj[i]==0){sj++;} dsj[i]=0;}
	for(int i=0; i<1002; i++){
		for (int k=0; k<sides[i].size(); k++){
			if (sides[i][k].first.first!=-1){
				edges.push_back(make_pair(sides[i][k].first.second, make_pair(sides[i][k].second, m+1)));
			}
		}
	}
	tot=mst();
	if (sj>1){printf("%i", tot);}
	else{printf("%i", min(ti, tot));}
	
	return 0;
}