#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int elm[3];
vector <char> chm;
int main() {
	int pv=0, nm=0, a, b, c, d;
	char tp=getchar();
	do{
		chm.push_back(tp);
		if (tp=='H'){ pv=0;}
		else if (tp=='C'){pv=1;}
		else {pv=2;}
		tp=getchar();
		if (tp<'0' || tp>'9'){nm=1;}
		else{nm=0;}
		while(tp>='0' && tp<='9'){
			nm=(nm*10)+tp-'0';
			chm.push_back(tp);
			tp=getchar();
		}
		elm[pv]+=nm;
	}
	while (tp>='C' && tp<='O');
	if (elm[0]==0 || elm[1]==0){printf("Impossible");}
	else if (elm[2]-elm[1]*2 > elm[0]/2){
		printf("Impossible");
	}
	
	else{
		a=1;
		if (elm[0] % 2){ a=a*2;}
		if ((elm[2]*a-elm[0]*a/2)%2){a=a*2;}
		b=(elm[1]*a*2+elm[0]*a/2 -elm[2]*a)/2;
		c=elm[1]*a;
		d=elm[0]*a/2;
		if (a==0 || b==0 || c==0 || d==0){printf("Impossible");}
		else{
		printf("%i", a);
		for(int i=0; i<chm.size(); i++){
			printf("%c", chm[i]);
		}
		printf(" + %iO2 -> %iCO2 + %iH2O", b, c, d);}
	}
	return 0;
}