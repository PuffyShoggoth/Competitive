#include <cstdio>
using namespace std;

int ar[1000005];

int main() {
	int n, h, sm=0;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i", &h);
		if (ar[h]) ar[h]--; 
		else sm++;
		ar[h-1]++;
	}
	printf("%i", sm);
	return 0;
}