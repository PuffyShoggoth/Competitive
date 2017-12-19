#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > srtedy, srtedx;
vector<int> cnm[50005];
vector<pair<int, int> > mq;
vector<int> rem;
int nval[50005];
int pval[50005];
int maxval(int n){
	mq.clear(); rem.clear();
	mq.push_back({n, -1});
	rem.push_back(nval[n]);
	for(int i = n-1; i>=0; i--){
		int tt=nval[i]+pval[i];
		while (mq.back().second>=0 && tt/(mq.back().first-i)>=mq.back().second){
			pair<int, int> tp = mq.back(); mq.pop_back();
			tt+=(mq.back().first-tp.first)*tp.second + rem.back();
			rem.pop_back();
		}
		rem.push_back(tt%(mq.back().first-i));
		mq.push_back({i, tt/(mq.back().first-i)});
	}
	if (mq.size() == 1) {
		return 0;
	}
	else {
		return mq[1].second + (rem[1]?1:0);
	}
}
int prep(int lvl, int a, int b){
	priority_queue<int> pq;
	for(int i=0; i<a; i++){
		int tp = cnm[i].size()-lvl;
		if (tp<0) {
			for(int j=0; j>tp; j--){
				if (pq.empty()){ break; }
				pq.pop();
			}
			tp=0;
		}
		else {
			for(int j=0; j<tp; j++){
				pq.push(cnm[i][j]);
			}
		}
		for(int j=tp; j<cnm[i].size(); j++){
			if (pq.empty() || pq.top()<=cnm[i][j]){ break; }
			pq.pop();
			pq.push(cnm[i][j]);
		}
	}
	memset(nval, 0, sizeof(nval));
	while(!pq.empty()){
		if (pq.top()==b) {
			return -1;
		}
		nval[pq.top()]++;
		pq.pop();
	}
	return maxval(b);
}
int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]){
	sort(X, X+A);
	sort(Y, Y+B);
	for(int i=0; i<T; i++){
		srtedy.push_back({S[i], W[i]});
	}
	sort(srtedy.begin(), srtedy.end());
	int ind = B-1, tind = T-1;
	while(tind>=0){
		if (ind<0 || Y[ind]<=srtedy[tind].first){
			srtedx.push_back({srtedy[tind].second, ind+1});
			tind--;
		}
		else{
			ind--;
		}
	}
	sort(srtedx.begin(), srtedx.end());
	ind = A-1; tind = T-1;
	while(tind>=0){
		if (ind<0 || X[ind]<=srtedx[tind].first){
			cnm[ind+1].push_back(srtedx[tind].second);
			nval[ind+1]++;
			tind--;
		}
		else{
			sort(cnm[ind+1].begin(), cnm[ind+1].end());
			ind--;
		}
	}
	sort(cnm[ind+1].begin(), cnm[ind+1].end());
	int e = maxval(A);
	memset(nval, 0, sizeof(nval));
	for(int i:cnm[A]){
		if (i==B) { return -1; }
		pval[i]++;
	}
	int s = maxval(B);
	if (s>=e){ return s; }
	int m, tp;
	while (s<e) {
		m = (s+e)>>1;
		tp = prep(m, A, B);
		if (tp > m || tp<0){
			s = m + 1;
		}
		else if (tp == m) {
			return tp;
		}
		else {
			e = m;
		}
	}
	return e;
}