#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
int pv[2000002];
vector<int> sptl;
int main() {
	int n, e, i, a, b;
	scanf("%i%i%i", &n, &e, &i);
	i++;
	for(int j=0; j<e; j++){
		scanf("%i%i", &a, &b);
		pv[b+1]=a+1;
	}
	while(pv[i]){
		i=pv[i];
		sptl.push_back(i-1);
	}
	for(auto it=sptl.rbegin(); it!=sptl.rend(); ++it){
		printf("%i ", *it);
	}
	return 0;
}