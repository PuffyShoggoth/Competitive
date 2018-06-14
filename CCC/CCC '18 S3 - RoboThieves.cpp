#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
string inp[105];
int ind[105][105];
int dfsv[105][105];
bool mc[105][105];
bool mcr[105][105];
bool mcc[105][105];
int ans[10005];
vector<int> edges[10005];
pair<int, int> dirs[]={{-1,0}, {1, 0},{0,-1},{0,1}};
pair<int, int> conv(int x, int y){
	if(inp[x][y]=='R'){return {x, y+1};}
	else if (inp[x][y]=='L'){return {x,y-1};}
	else if(inp[x][y]=='U'){return {x-1, y};}
	else{return {x+1, y};}
}
int dfs(int i, int j){
	if(dfsv[i][j]){
		return dfsv[i][j];
	}
	else if(inp[i][j]=='C'){
		dfsv[i][j]=-1;
		return -1;
	}
	else if(inp[i][j]=='W'){
		dfsv[i][j]=-1;
		return -1;
	}
	else if (inp[i][j]=='.' || inp[i][j]=='S'){
		if(mc[i][j]){
			dfsv[i][j]=-1;
		}
		else{dfsv[i][j]=ind[i][j];}
		return dfsv[i][j];
	}
	else{
		dfsv[i][j]=-1;
		pair<int, int> tp = conv(i,j);
		dfsv[i][j]=dfs(tp.first, tp.second);
		return dfsv[i][j];
	}
}
int main() {
	int n, m;
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	memset(ans, -1, sizeof(ans));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			ind[i][j]=i*m+j+1;
		}
	}
	for(int i=0; i<n; i++){
		cin>>inp[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(inp[i][j]=='C'){
				for(int k=i-1; k>=0; k--){
					if(mcc[k][j] || inp[k][j]=='W'){break;}
					mcc[k][j]=1;
					mc[k][j]=1;
				}
				for(int k=i+1; k<n; k++){
					if(mcc[k][j] || inp[k][j]=='W'){break;}
					mcc[k][j]=1;
					mc[k][j]=1;
				}
				for(int k=j-1; k>=0; k--){
					if(mcr[i][k] || inp[i][k]=='W'){break;}
					mcr[i][k]=1;
					mc[i][k]=1;
				}
				for(int k=j+1; k<m; k++){
					if(mcr[i][k] || inp[i][k]=='W'){break;}
					mcr[i][k]=1;
					mc[i][k]=1;
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			dfs(i,j);
		}
	}
	int s=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(inp[i][j]=='.' || inp[i][j]=='S'){
				for(pair<int, int> tp:dirs){
					if(dfsv[i+tp.first][j+tp.second]!=-1 && dfsv[i][j]!=-1){
						edges[ind[i][j]].push_back(dfsv[i+tp.first][j+tp.second]);
					}
				}
				if(inp[i][j]=='S'){
					s=ind[i][j];
					if(mc[i][j]){ans[ind[i][j]]=0;}
				}
			}
		}
	}
	queue<pair<int, int> > q;
	q.push({s,0});
	while(q.size()){
		pair<int, int> tp=q.front();
		q.pop();
		if(ans[tp.first]!=-1){continue;}
		ans[tp.first]=tp.second;
		for(int i: edges[tp.first]){
			if(ans[i]==-1){
				q.push({i, tp.second+1});
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(inp[i][j]=='.'){printf("%i\n", ans[ind[i][j]]);}
		}
	}
    return 0;
}