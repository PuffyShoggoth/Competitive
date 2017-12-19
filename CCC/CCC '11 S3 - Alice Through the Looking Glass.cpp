#include <vector>
#include <cstdio>
using namespace std;
int cla[5]={0, 1, 2, 1, 0};
int pf[14];
bool crys(int m, int x, int y, int py){
	if (m==0){
		if (py>y) return 1;
		return 0;
	}
	if (x/pf[m-1]==0 || x/pf[m-1]==4){
		if (py*pf[m]>y) return 1;
		return 0;
	}
	return crys(m-1, x%pf[m-1], y, py*5+cla[x/pf[m-1]]);
}
int main() {
	int t, m, x, y;
	pf[0]=1; for(int i=1; i<14; i++){pf[i]=pf[i-1]*5;}
	scanf("%i", &t);
	for(int i=0; i<t; i++){
		scanf("%i%i%i", &m, &x, &y);
		if (crys(m, x, y, 0)){printf("crystal\n");}
		else{printf("empty\n");}
	}
	return 0;
}