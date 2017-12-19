#include <cstdio>
#include <vector>
using namespace std;
vector<int> swifts, sema;

int main(){
	int n;
	int sc;
	scanf("%i", &n);
	swifts.push_back(0); sema.push_back(0);
	for(int i=0; i<n; i++){
		scanf("%i", &sc);
		swifts.push_back(swifts.back()+sc);
	}
	for(int i=0; i<n; i++){
		scanf("%i", &sc);
		sema.push_back(sema.back()+sc);
	}
	for(int i=0; i<=n; i++){
		if (swifts[i]==sema[i]){
			sc=i;
		}
	}
	printf("%i", sc);
}