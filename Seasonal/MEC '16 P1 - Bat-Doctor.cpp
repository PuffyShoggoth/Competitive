#include <iostream>
#include <cmath>
#include <iostream>
#include <cmath>
#include <cstdio>
#define PI 3.14159265
using namespace std;
int x[10009];
int main() {
	int r, c, sp=1, pr;
	double cr, o, oa;
	char tp;
	scanf("%i%i", &r, &c);
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			tp=getchar(); while(tp<'A'){tp=getchar();}
			if(tp=='X'){x[j]=i;}
		}
	}
	while(x[pr]==0 && pr<=c){pr+=1;}
	sp=pr;
	for(int i=(sp+1); i<=c; i++){
		if(x[i]==0){continue;}
		o=(max(x[pr], x[i])-min(x[pr], x[i]));
		oa=o/(i-pr);
		cr=atan(oa)*180/PI;
		if(x[i]<x[pr]){cr=90-cr;}
		else{cr+=90;}
		printf("%.3f\n", cr);
		pr=i;
	}
	if (pr==sp){printf("%.3f\n", 0.000);}
	return 0;
}