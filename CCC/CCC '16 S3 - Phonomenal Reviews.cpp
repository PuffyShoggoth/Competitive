#include <iostream>
#include <vector>
using namespace std;
vector<int> r[100009];
int ph[100009];
int fl[100009];
int tt=0;
int mt=0;
int dist(int i){
	int t, td=0, cm=0;
	if (r[i].size()==1 & r[i][0]==i){
		return ph[i];}
	for(int p=0; p<r[i].size(); p++){
		if (fl[r[i][p]]!=0){continue;}
		fl[r[i][p]]=1;
		t=dist(r[i][p]);
		mt=max(mt, cm+t);
		if (t!=0){
		if (t>cm){tt+=(cm*2); cm=t;}
		else{tt+=t*2;}}
	
	}
	if (cm==0 & ph[i]==0){return 0;}
	return cm+1;
}
int main() {
	int n, m, a, b, ta, tk;
	cin>>n>>m;
	cin>>ta;
	ph[ta]+=1;
	fl[ta]+=1;
	for(int i=1; i<m; i++){
		scanf("%i", &a);
		ph[a]+=1;
	}
	for (int i=1; i<n; i++){
		scanf("%i%i", &a, &b);
		r[a].push_back(b);
		r[b].push_back(a);
	}
	tk=dist(ta);
	tt+=(tk-1)*2;
	cout<<tt-max(tk-1, mt);
	return 0;
}