#include <cstdio>
using namespace std;
int points[105][2];
int main() {
	int n;
	int t=0;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%i%i", &points[i][0], &points[i][1]);
	}
	for(int i=0; i<n-1; i++){
		t+=points[i][0]*points[i+1][1];
		t-=points[i][1]*points[i+1][0];
	}
	t+=points[n-1][0]*points[0][1];
	t-=points[n-1][1]*points[0][0];
	if (t<0){t=-1*t;}
	t+=1;
	t=t/2;
	printf("%i", t);
	return 0;
}