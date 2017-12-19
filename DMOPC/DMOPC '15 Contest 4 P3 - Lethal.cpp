#include <iostream>
using namespace std;

int main() {
	int g, n, hi, hm, av[10], smp, smm, hl;
	cin>>g;
	for(int dnr=0; dnr<g; dnr++){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>av[i];
		}
		cin>>hi>>hm;
		hl=0;
		for(int i=0; i<(1<<n); i++){
			smp=0; smm=0; 
			for(int j=0; j<n; j++){
				if (i&(1<<j)) smp+=av[j];
				else smm+=av[j];
			}
			if (smp>=hi && smm>=hm){
				hl=1; break;
			}
		}
		if (hl) cout<<"LETHAL\n";
		else cout<<"NOT LETHAL\n";
	}
	return 0;
}