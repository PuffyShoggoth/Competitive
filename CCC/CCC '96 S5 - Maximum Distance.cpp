#include <cstdio>
#include <cstring>
using namespace std;
int x[100005];
int y[100005];

int main() {
	int t, n, mx, i;
	scanf("%i", &t);
	for(int dnr=0; dnr<t; dnr++){
		scanf("%i", &n);
		mx=0;
		for(int k=0; k<n; k++){
			scanf("%i", &x[k]);
		}
		for(int k=0; k<n; k++){
			scanf("%i", &y[k]);
		}
		i=n-1;
		for(int j=n-1; j>=0; j--){
			if (i>j) i=j;
			while(i>=0 && y[j]>=x[i]){ i--; }
			mx = mx>(j-(i+1))?mx:(j-(i+1));
			if (i<0){ break; }
		}
		printf("The maximum distance is %i\n", mx);
	}
	return 0;
}