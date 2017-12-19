#include <bits/stdc++.h>
using namespace std;
vector<int> edges[1005];
vector<int> bedg[1005];
int low[1005], num[1005];
int dfsvl=0, bval=0;
void tarjan(int cn, int par){
	dfsvl++;
	low[cn] = num[cn] = dfsvl;
	for(int i:edges[cn]){
		if (i==par) continue;
		if (num[i]){ low[cn] = min(low[cn], num[i]); }
		else{
			tarjan(i, cn);
			low[cn] = min(low[cn], low[i]);
		}
	}
	return;
}
bool visited[1005];
void build(int cn, int par, int pvb){
	if (visited[cn]){ return; }
	visited[cn]=1;
	for(int i: edges[cn]){
		if (i==par) continue;
		if (low[i]<=num[cn]){

			build(i, cn, pvb);
		}
		else{
			bval++;
			bedg[pvb].push_back(bval);
			build(i, cn, bval);
		}
	}
	return;
}
int ttb = 0;
int br(int cn){
	if(bedg[cn].size()==0){
		if(cn==0){ return 0; }
		else{ return 1; }
	}
	int ttch =0;
	bool ft =0;
	for(int i: bedg[cn]){
		int tp = br(i);
		if(ttch==0){ ttch = tp; ft=1;}
		else if(ttch==1 && tp==1){
			ttch=2;
			ft = 0;
		}
		else if(ttch==2 && tp==2){
			ttb++;
			ft = 0;
		}
		else{
			ttch = 1;
			ttb++;
			ft = 0;
		}
	}
	if(cn==0){
		if(ft) ttb+= ttch;
		else { ttb+= 1; }
	}
	return ttch;
}
int main(){
	int n, r;
	scanf("%i%i", &n, &r);
	int a, b;
	for(int i=0; i<r; i++){
		scanf("%i%i", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	tarjan(1, 0);
	build(1, 0, 0);
	br(0);
	printf("%i", ttb);
	return 0;
}