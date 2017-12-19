#include <iostream>
#include <string>
using namespace std;
int grid[105][105];
void up(int &x, int &y, int &d){
	if (grid[y][x]==0){
		y-=1; return;
	}
	else if (grid[y][x]==1){
		grid[y][x]+=1; y+=1; d=2; return;
	}
	else if (grid[y][x]==2){
		y-=1; return;
	}
	else if (grid[y][x]==3){
		grid[y][x]+=1; x+=1; d=1; return;
	}
	grid[y][x]-=1; x-=1; d=3; return;
}
void down(int &x, int &y, int &d){
	if (grid[y][x]==0){
		y+=1; return;
	}
	else if (grid[y][x]==1){
		grid[y][x]+=1; y-=1; d=0; return;
	}
	else if (grid[y][x]==2){
		y+=1; return;
	}
	else if (grid[y][x]==3){
		grid[y][x]+=1; x-=1; d=3; return;
	}
	grid[y][x]-=1; x+=1; d=1; return;
}
void right(int &x, int &y, int &d){
	if (grid[y][x]==0){
		x+=1; return;
	}
	else if (grid[y][x]==1){
		x+=1; return;
	}
	else if (grid[y][x]==2){
		grid[y][x]-=1; x-=1; d=3; return;
	}
	else if (grid[y][x]==3){
		grid[y][x]+=1; y-=1; d=0; return;
	}
	grid[y][x]-=1; y+=1; d=2; return;
}
void left(int &x, int &y, int &d){
	if (grid[y][x]==0){
		x-=1; return;
	}
	else if (grid[y][x]==1){
		x-=1; return;
	}
	else if (grid[y][x]==2){
		grid[y][x]-=1; x+=1; d=1; return;
	}
	else if (grid[y][x]==3){
		grid[y][x]+=1; y+=1; d=2; return;
	}
	grid[y][x]-=1; y-=1; d=0; return;
}
int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string tmps;
	tmps.resize(105);
	int n, m, t, x, y, d=1;
	bool out=0;
	cin>>n>>m>>t;
	for(int i=0; i<m; i++){
		cin>>tmps;
		for(int j=0; j<n; j++){
		    if (tmps[j]=='.'){grid[i][j]=0;}
			else if (tmps[j]=='-'){grid[i][j]=1;}
			else if (tmps[j]=='|'){grid[i][j]=2;}
			else if (tmps[j]=='/'){grid[i][j]=3;}
			else if (tmps[j]=='O'){x=j; y=i;}
			else {grid[i][j]=4;}
		}
	}
	for(int i=0; i<=t; i++){
		if (x<0 || x>=n || y<0 || y>=m){
			cout<<"The observer leaves the grid after "<<i<<" tick(s).";
			out=1; break;
		}
		else if (d==0){up(x, y, d);}
		else if (d==1){right(x, y, d);}
		else if (d==2){down(x, y, d);}
		else{left(x, y, d);}
	}
	if (!out){ cout<<"The observer stays within the grid.";}
	return 0;
}
//@#$%!