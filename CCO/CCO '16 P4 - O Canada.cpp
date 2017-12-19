#include <map>
#include <cstdio>
using namespace std;
bool grd[10][10];
map<int, int> prv;
int main() {
	int n, g, tmp, tt=0;
	scanf("%i%i", &n, &g);
	for(int i=0; i<g; i++){
		for(int j=0; j<n; j++){
			getchar();
			for(int k=0; k<n; k++){
				if (getchar()=='R') grd[j][k]=1; 
				else grd[j][k]=0;
			}
		}
		for(int j=0; j<n-1; j++){
			for(int k=0; k<n-1; k++){
				if (grd[j][k]){
					grd[j][k]=0; grd[j][k+1]=(!grd[j][k+1]); grd[j+1][k+1]=(!grd[j+1][k+1]);
					grd[j+1][k]=(!grd[j+1][k]);
				}
			}
		}
		tmp=0;
		for(int j=0; j<n; j++){
			if (grd[n-1][j]) tmp= tmp|(1<<j);
		}
		for(int j=0; j<n-1; j++){
			if (grd[j][n-1]) tmp = tmp|(1<<(j+n));
		}
		if (prv.find(tmp)==prv.end()) prv[tmp]=1;
		else{tt+=prv[tmp]; prv[tmp]++;}
	}
	printf("%i", tt);
	
	return 0;
}