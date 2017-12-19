#include <cstdio>
#include <cmath>
using namespace std;
int main() {
	int t, n;
	float inttemp, b, m;
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		scanf("%i", &n);
		scanf("%f", &b);
		m=0;
		for(int j=1; j<n; j++){
			scanf("%f", &inttemp);
			if (inttemp>b){m+=1;}
		}
		printf("Bob wins $%.2f at IOI!\n", sqrt(n-m)*100);
	}	
	return 0;
}