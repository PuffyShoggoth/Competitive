#include <iostream>
#include <cstdio>
using namespace std;

int hated[100009];
int main() {
	int n, m, p, a, b, t, s=0;
	scanf("%i%i%i", &n, &m, &p);
	for(int i=0; i<n; i++){
		scanf("%i%i", &a, &b);
		if (hated[b]==0){
			hated[b]=a;
		}
	}
	while(1==1){
		if (hated[p]==0){printf("%i", s); break;}
		else if (hated[p]==-1){printf("%i", -1); break;}
		t=p; p=hated[p]; hated[t]=-1; s+=1;
	}
	return 0;
}