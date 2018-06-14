#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int sunf[105][105];

int main() {
	int n;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%i", &sunf[i][j]);
		}
	}
	bool dn = 0;
	if(sunf[0][0]<sunf[0][1]){
		if(sunf[0][0]<sunf[1][0]){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					printf("%i ", sunf[i][j]);
				}
				putchar('\n');
			}
		}
		else{
			for(int i=0; i<n; i++){
				for(int j=n-1; j>=0; j--){
					printf("%i ", sunf[j][i]);
				}
				putchar('\n');
			}

		}
	}
	else{
		if(sunf[0][0]<sunf[1][0]){
			for(int i=n-1; i>=0; i--){
				for(int j=0; j<n; j++){
					printf("%i ", sunf[j][i]);
				}
				putchar('\n');
			}
		}
		else{
			for(int i=n-1; i>=0; i--){
				for(int j=n-1; j>=0; j--){
					printf("%i ", sunf[i][j]);
				}
				putchar('\n');
			}

		}
	}
    return 0;
}