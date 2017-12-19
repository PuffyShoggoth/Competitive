#include <bits/stdc++.h>
using namespace std;
string dir[4];
string inst;
bool visited[6005], hasval[6005];
set<pair<int, int> >vals[6005];
void pos(int a){
    if (visited[a] || a>inst.length()){ return; }
	else if (a==inst.length()){
		vals[a].insert({0,0});
		hasval[a]=1;
		visited[a]=1;
		return;
	}
	visited[a]=1;
	pair<int, int> tpp;
	for(int i=0; i<4; i++){
		if ((a+dir[i].length())>inst.length()){continue;}
		bool match=1;
		for(int j=0; j<dir[i].length(); j++){
			if (a+j>=inst.length() || dir[i][j]!=inst[a+j]){
				match = 0; break;
			}
		}
		tpp.first=0; tpp.second=0;
		if (i==0){ tpp.first--; }
		else if (i==1){ tpp.first++; }
		else if (i==2){ tpp.second--; }
		else{ tpp.second++; }
		if (match && dir[i].length()){
		    pos(a+dir[i].length());
			if (hasval[a+dir[i].length()]){
			    hasval[a]=1;
			    for(auto j: vals[a+dir[i].length()]){
				    vals[a].insert({j.first+tpp.first, j.second+tpp.second});
			    }  
			}
		}
	}
	return;
}
int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	for(int i=0; i<4; i++){
		cin>>dir[i];
	}
	cin>>inst;
	pos(0);
	if (hasval[0]){
	    printf("%lu", vals[0].size());
	}
	else{
	    printf("0");
	}
}