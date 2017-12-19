#include <bits/stdc++.h>
using namespace std;


vector<int> scc;

int main(){
	long long int k;
	scanf("%lli", &k);
	int tn=5000; bool f=1;
	int v=0, e=0;
	while(k>0){
		if (k>=(tn*(tn-1))/2){
			k-=(tn*(tn-1))/2;
			scc.push_back(tn);
			v+=tn; e+=tn;
			if (!f){ e++; }
			else{ f=0; }
		}
		else{tn--;}
	}
	printf("%i %i\n", v, e);
	int cn=1;
	for(int i: scc){
		if (cn>1){ printf("%i %i\n", cn, cn+1); cn++; }
		int st=cn;
		for(int j=st; j<st+i-1; j++){
			printf("%i %i\n", cn, cn+1); 
			cn++;
		}
		printf("%i %i\n", cn, st);
	}
	return 0;
}