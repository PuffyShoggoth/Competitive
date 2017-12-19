#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int v[100009];
vector <int>edges;
int root(int i){
	while (v[i]!=0){
		i=v[i];
	}
	return i;
}
int main() {
	int n, m, a, b, ra, rb, cnt=0;
	scanf("%i%i", &n, &m);
	for (int i=1; i<=m; i++){
		scanf("%i%i", &a, &b);
		ra=root(a); rb=root(b);
		if (ra!=rb){
			edges.push_back(i);
			v[max(ra, rb)]=min(ra, rb);
		}
	}
	for (int i=1; i<=n; i++){
		if (v[i]==0){cnt+=1;}
	}
	if (cnt!=1){
		cout<<"Disconnected Graph";
	}
	else{
		for(int i=0; i<edges.size(); i++){
			printf("%i\n", edges[i]);
		}
	}
	return 0;
}