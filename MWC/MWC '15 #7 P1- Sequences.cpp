#include <cstdio>
using namespace std;
double seq[12];
int main() {
	int n;
	bool ar=1, geo=1, tmp=1;
	scanf("%i", &n);
	for(int i=0; i<n; i++){
		scanf("%lf", &seq[i]);
		if (seq[i]!=0){tmp=0;}
	}
	for(int i=2; i<n; i++){
		if (seq[i]/seq[i-1] != seq[1]/seq[0]) geo=0;
		if (seq[i]-seq[i-1] != seq[1]-seq[0]) ar=0;
	}
	if (tmp==1){geo=1;}
	if (ar && geo){printf("both");}
	else if (ar){printf("arithmetic");}
	else if (geo){printf("geometric");}
	else{printf("random");}
	return 0;
}