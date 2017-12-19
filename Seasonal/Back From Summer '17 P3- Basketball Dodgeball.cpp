#include <bits/stdc++.h>
using namespace std;
pair<int, int> nc[3005], mc[3005];
int nr[3005], mr[3005];
bool nv[3005], mv[3005];
inline bool dist(pair<int, int> a, pair<int, int> b, int r){
	return ((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second))<=r*r;
}
int bfs(int num, pair<int, int> coord[3005], int rng[3005], bool vst[3005], int baller, int start){
	//printf("%i %i\n", baller, start);
	queue<pair<int, int> > q;
	q.push({start, 0});
	int ans = -1;
	pair<int, int> curr;
	while(!q.empty()){
		curr = q.front();
		q.pop();
		if (vst[curr.first]){ continue; }
		else if (curr.first == baller){ ans = curr.second; break; }
		else{
			vst[curr.first]=1;
			for(int i=0; i<num; i++){
				if (vst[i] || (!dist(coord[curr.first], coord[i], rng[curr.first]))){
					continue;
				}
				else{
					//printf("%i ", i);
					q.push({i, curr.second+1});
				}
			}
			//printf("%i\n", curr.first);
		}
	}
	return ans;
}
int main(){
	int n, m;
	scanf("%i%i", &n, &m);
	int x, y, r;
	int ny=-1, my=-1, nb=-1, mb=-1;
	int stn=-1, stm=-1;
	for(int i=0; i<n; i++){
		scanf("%i%i%i", &x, &y, &r);
		nc[i] = {x, y};
		nr[i]=r;
		if (r==9001){ nb = i;}
		if (y>ny){ ny = y; stn = i;}
	}
	for(int i=0; i<m; i++){
		scanf("%i%i%i", &x, &y, &r);
		mc[i] = {x, y};
		mr[i]=r;
		if (r==9001){ mb = i;}
		if (y>my){ my = y; stm = i;}
	}
	int scn = bfs(n, nc, nr, nv, nb, stn);
	int scm = bfs(m, mc, mr, mv, mb, stm);
	//printf("%i %i\n", scn, scm);
	if (scn == scm){
		printf("SUDDEN DEATH");
	}
	else if (scm == -1 || (scn!=-1 && scn < scm)){
		printf("We are the champions!");
	}
	else{
		printf(":'(");
	}
}