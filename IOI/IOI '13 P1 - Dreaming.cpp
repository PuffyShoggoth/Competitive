#include <vector>
#include <cstdio>
#include <utility>
#include <cmath>
using namespace std;
int visited[100005];
int mxlngth[100005][2];

vector<pair<int, int> > edges[100005];


void dfs(int cn){
	visited[cn]=1;
	for(int i=0; i<edges[cn].size(); i++){
		if (visited[edges[cn][i].first]) continue;
		dfs(edges[cn][i].first);
		if (mxlngth[edges[cn][i].first][0]+edges[cn][i].second>=mxlngth[cn][0]){
			mxlngth[cn][1]=mxlngth[cn][0]; mxlngth[cn][0]=mxlngth[edges[cn][i].first][0]+edges[cn][i].second;
		}
		else if (mxlngth[edges[cn][i].first][0]+ edges[cn][i].second> mxlngth[cn][1] ){
			mxlngth[cn][1]=mxlngth[edges[cn][i].first][0]+edges[cn][i].second;
		}
	}
	return;
}
pair<int, int> dfsb(int cn, int par, int pvmx){
	int tpa, tpb; pair<int, int> tp;
	tpa=max(pvmx, mxlngth[cn][0]); tpb=min(max(pvmx, mxlngth[cn][1]), mxlngth[cn][0]);
	for(int i=0; i<edges[cn].size(); i++){
		if (edges[cn][i].first==par) continue;
		if (mxlngth[cn][0] == mxlngth[edges[cn][i].first][0] + edges[cn][i].second){
			tp= dfsb(edges[cn][i].first, cn, max(mxlngth[cn][1], pvmx)+edges[cn][i].second);
		}
		else{
			tp = dfsb(edges[cn][i].first, cn, max(mxlngth[cn][0], pvmx)+edges[cn][i].second);
		}
		if (tp.first<tpa){
			tpa=tp.first; tpb=tp.second;
		}
	}
	return make_pair(tpa, tpb);
}
int travelTime(int N, int M, int L, int A[], int B[], int T[]){
	int tg=0, mxa=-1, mxb=-1, mxl=0, mxlb=0; pair<int, int> tp;
	for(int i=0; i<M; i++){
		edges[A[i]].push_back(make_pair(B[i], T[i]));
		edges[B[i]].push_back(make_pair(A[i], T[i]));
	}
	for(int i=0; i<N; i++){
		if (visited[i]) continue;
		tg++;
		dfs(i);
		tp=dfsb(i, 0, 0);
		if (tp.first>=mxa){
			if (mxb!=-1) {mxlb=max(mxlb, mxa+mxb+L*2);}
			mxb=mxa; mxa=tp.first;
		}
		else if (tp.first>mxb){
			if (mxb!=-1) {mxlb=max(mxlb, mxb+tp.first+L*2);}
			mxb=tp.first;
		}
		else if (mxb!=-1){
			mxlb=max(mxlb, mxb+tp.first+L*2);
		}
		mxl=max(mxl, tp.first+tp.second);
	}
	if (mxb<0){
		return mxl;
	}
	return max(mxa+mxb+L, max(mxl, mxlb));
}