#include <cstdio>
using namespace std;
int np[105];
int cv[105];
bool sal[26];
int main() {
	int t, n;
	scanf("%i", &t);
	sal[0]=1; sal[1]=1; sal[2]=1; sal[4]=1; sal[6]=1; sal[11]=1; sal[14]=1; sal[17]=1;
	for(int i=0; i<t; i++){
		int mnv=-1;
		scanf("%i", &n);
		getchar();
		for(int j=0; j<n; j++){
			cv[j]=getchar()-'A';
		}
		for(int j=0; j<n; j++){
			scanf("%i", &np[j]);
		}
		for(int j=0; j<=26; j++){
			bool posal=1;
			for(int k=0; k<n; k++){
			    posal&=sal[cv[k]];
				cv[k]=(cv[k]+np[k])%26;
			}
			if (posal){
				mnv=j; break;
			}
		}
		printf("%i\n", mnv);
	}
	return 0;
}