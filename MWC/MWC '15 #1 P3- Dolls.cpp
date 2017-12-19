#include <cstdio>
using namespace std;
int dolls[102];
int main() {
	int n, tmp, mn=100000, mx=0, mindl, maxdl;
	
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i", &tmp);
		dolls[tmp]+=1;
	}
	for(int i=0; i<=100; i++){
		if (dolls[i]!=0 && dolls[i]<mn){
			mindl=i; mn=dolls[i];
		}
		if (dolls[i]>=mx){
			maxdl=i; mx=dolls[i];
		}
		
	}
	if (maxdl<mindl){printf("%i", mindl-maxdl);}
	else{printf("%i", maxdl-mindl);}
	return 0;
}