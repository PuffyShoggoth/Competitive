#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

vector<int> bndw[1009];
int eng(int a, int b){
	if (a==b) return 615;
	else if (bndw[a].size()==4) return 346;
	else return 413;
}
int main() {
	int n, m, a, b, tte=0, c, d, e, f, hyd=0, carb=0;
	bool pos=0;
	scanf("%i%i", &n, &m);
	for(int i=0; i<m; i++){
		scanf("%i%i", &a, &b);
		bndw[a].push_back(b);
		bndw[b].push_back(a);
	}
	for(int i=1; i<=n; i++){
		if (bndw[i].size()==1){
			hyd++;
			if (bndw[bndw[i][0]].size()<4){
				pos=1; break;
			}
			else if (bndw[i][0]>i){
				tte+=413;
			}
		}
		else if (bndw[i].size()==4){
			carb++;
			sort(bndw[i].begin(), bndw[i].end());
			c=bndw[i][0]; d=bndw[i][1]; e=bndw[i][2]; f=bndw[i][3];
			if ((c==d && d==e)||(d==e && e==f)){ pos=1; break; }
			if (c>i){tte+=eng(c,d);}
			if (d>i && d!=c){tte+=eng(d, e);}
			if (e>i && e!=d){tte+=eng(e,f);}
			if (f>i && f!=e){tte+=eng(f,e);}
		}
		else{ pos=1; break; }
	}
	if (pos){printf("Impossible");}
	else{
		printf("%i\n", tte);
		printf("C"); if (carb>1) {printf("%i", carb);}
		printf("H"); if (hyd>1) {printf("%i", hyd);}
	}
	return 0;
}