#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
pair<int, int> dirs[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;
string mp[1005];
bool vstd[1005][1005];
bool vld(int x, int y){
	if(x>=n || x<0 || y>=m || y<0){ return 0;}
	else{
		if(mp[x][y]!='X' && vstd[x][y]==0){return 1;}
		else{  return 0; }
	}
}

int main() {
	cin>>n>>m;
	int stx=-1, edx = -1;
	getchar();
	for(int i=0; i<n; i++){
		cin>>mp[i];
		for(int j=0; j<m; j++){
			if(mp[i][j]=='s'){ stx = i; edx = j; break;}
		}
	}
	queue<pair<pair<int, int> , int> > cvls;
	cvls.push({{stx, edx}, 0});
	bool dn = 0;
	while(cvls.size()){
		pair<int, int> tpp = cvls.front().first; int cc = cvls.front().second;
		cvls.pop();
		if(vstd[tpp.first][tpp.second]){ continue;}
		
		if(mp[tpp.first][tpp.second]=='e'){cout<<cc-1<<'\n'; dn = 1; break;}
		vstd[tpp.first][tpp.second] = 1;
		for(pair<int, int> i: dirs){
			if(vld(tpp.first+i.first, tpp.second+i.second)){
				
				cvls.push({{tpp.first+i.first, tpp.second+i.second}, cc+1});
			}
		}
	}
	if(!dn){cout<<-1<<'\n';}
    return 0;
}