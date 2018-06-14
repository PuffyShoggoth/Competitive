#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
pair<int, int> dirs[]={{-1,0}, {1,0}, {0,-1}, {0,1}};
int r, c;
bool vld(int cr, int cc){
	return (cr<r&&cr>=0&&cc<c&&cc>=0);
}
string plan[30];
bool vstd[30][30];
int dfs(int x, int y){
	if(!vld(x, y) || vstd[x][y] || plan[x][y]!='.') return 0;
	int tt = 1;
	vstd[x][y]=1;
	for(pair<int, int> tp: dirs){
		tt+=dfs(x+tp.first, y+tp.second);
	}
	return tt;
}
vector<int> rms;
int main() {
	int fl;
	cin>>fl>>r>>c;
	for(int i=0; i<r; i++){
		cin>>plan[i];
	}
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(plan[i][j]=='.' && !vstd[i][j]){
				rms.push_back(dfs(i,j));
			}
		}
	}
	sort(rms.begin(), rms.end());
	int tt = 0;
	for(int i=rms.size()-1; i>=0; i--){
		if(rms[i]<=fl){
			tt++; fl-=rms[i];
		}
		else{
			break;
		}
	}
	if (tt==1){
		printf("%i room, %i square metre(s) left over", tt, fl);
	}
	else{
		printf("%i rooms, %i square metre(s) left over", tt, fl);
	}
    return 0;
}