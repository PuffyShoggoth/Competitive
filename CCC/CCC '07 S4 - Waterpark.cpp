#include <iostream>
#include <vector>
using namespace std; 

int ni[10009];
vector<int>edges[10009];
int main(){
	int n, cx, cy;
	cin>>n;
	while (9>0){
		cin>>cx>>cy;
		if (cx==0 && cy==0){break;}
		edges[cx].push_back(cy);
	}
	ni[1]=1;
	for (int i=1; i<n; i++){
		for (int k=0; k<edges[i].size(); k++){
			ni[edges[i][k]]+=ni[i];
		}
	}
	cout<<ni[n];
	return 0;
}