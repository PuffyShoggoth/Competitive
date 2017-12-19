#include <bits/stdc++.h>

using namespace std;
int dist[5005][5005];
void findLocation(int n, int first, int location[], int stype[]){
	vector<pair<int, int> > vls0;
	vector<int> vlsl, vlsr;
	for(int i=1; i<n; i++){
		dist[0][i]=getDistance(0, i);
		dist[i][0]=dist[0][i];
		vls0.push_back({dist[0][i], i});
	}
	location[0]=first; stype[0]=1;
	sort(vls0.begin(), vls0.end());
	int fd = vls0[0].second;
	location[fd]=first+vls0[0].first;
	stype[fd]=2;
	dist[fd][0]=dist[0][fd];
	for(int i=1; i<n; i++){
		if (i==fd) continue;
		dist[fd][i]=getDistance(fd, i);
		dist[i][fd]=dist[fd][i];
	}
	set<int> loc, loc2;
	loc.insert(fd);
	loc2.insert(0);
	int cfirst = 0, cd = fd;
	for(pair<int, int>tp: vls0){
		int i=tp.second;
		if (i==fd) continue;
		if(dist[fd][i]<dist[0][fd] && dist[fd][i]+dist[0][fd]==dist[0][i]){
			location[i]=location[fd]-dist[fd][i];
			loc2.insert(i);
			stype[i]=1;
		}
		else if(dist[fd][i]+dist[0][fd]==dist[0][i]){
			vlsl.push_back(i);
		}
		else{
			vlsr.push_back(i);
		}
	}
	for(int tp: vlsr){
		if(stype[tp]) continue;
		int y0 = getDistance(tp, cd);
		int tpi = (dist[0][cd]+y0-dist[0][tp])/2;
		if(loc.count(location[cd]-tpi)){
			location[tp]=location[cd]-tpi-(dist[0][tp]+y0-dist[0][cd])/2;
			stype[tp]=1;
		}
		else{
			stype[tp]=2;
			location[tp]=first+dist[0][tp];
			cd = tp;
			loc.insert(location[tp]);
		}
	}
	for(int tp: vlsl){
		int y0 = getDistance(tp, cfirst);
		int tpi = (dist[fd][cfirst]+y0-dist[fd][tp])/2;
		if(loc2.count(location[cfirst]+tpi)){
			location[tp]=location[cfirst]+tpi+(dist[fd][tp]+y0-dist[fd][cfirst])/2;
			stype[tp]=2;
		}
		else{
			stype[tp]=1;
			location[tp]=location[fd]-dist[fd][tp];
			cfirst=tp;
			loc2.insert(location[tp]);
		}
	}
}