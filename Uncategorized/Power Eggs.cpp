#include <cstdio>
using namespace std;
unsigned int drps[33][33];
int main() {
	unsigned int n, t, k;
	for (int i=1; i<=32; i++){
		for(int j=1; j<i; j++){
			drps[i][j]=drps[i-1][j];
		}
		for(int j=i; j<=32; j++){
			drps[i][j]=drps[i][j-1]+drps[i-1][j-1]+1;
		}
	}
	scanf("%u", &n);
	for(int i=0; i<n; i++){
		scanf("%u%u", &t, &k);
		if (drps[k][32]<t){printf("Impossible\n", drps[k][32]);}
		else{
			for (int j=1; j<=32; j++){
				if(drps[k][j]>=t){
					printf("%u\n", j);
					break;
					}
			}
		}
	}
	return 0;
}