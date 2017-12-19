#include <bits/stdc++.h>

using namespace std;

int main(){
	int md = 60*12;
	long long int d;
	scanf("%lli", &d);
	int h, m, td=0, tc=0;
	bool as;
	for(int i=0; i<md; i++){
		as=0;
		h = ((md + i)/60)%12;
		m = (md+i)%60;
		if (h==0){  if (m==34){ as=1; } }
		else if (h>9){
			if (h/10 - h%10 == h%10 - m/10 && h/10-h%10 == m/10-m%10){ as = 1; }
		}
		else{
			if (h - m/10 == m/10 - m%10){ as = 1; }
		}
		if (as){
			td++;
			if (i<=d%md){ tc++; }
		}
	}
	printf("%i", (d/md)*td+tc);
}