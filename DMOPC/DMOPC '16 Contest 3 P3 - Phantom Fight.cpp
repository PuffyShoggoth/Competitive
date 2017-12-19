#include <cstdio>
using namespace std;
int mr[10005];
int main() {
	int n, m, si, mi, ng;
	scanf("%i%i", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%i%i", &si, &mi);
		ng=mi-si;
		if (ng<=0){
			for(int j=si; j<=m; j++){
				if (mr[j]+1 > mr[j+ng]) mr[j+ng]= mr[j]+1;
			}
		}
		else{
		    if (si<=m) m+=ng;
			for(int j=m; j>=si+ng; j--){
				if (mr[j-ng]+1 > mr[j]) mr[j] = mr[j-ng]+1;
			}
		}
	}
	int ind, mx=0;
	for(int i=0; i<=m; i++){
		if (mr[i]>=mx){
			ind=i;
			mx=mr[i];
		}
	}
	printf("%i %i", mr[ind], ind);
	return 0;
}