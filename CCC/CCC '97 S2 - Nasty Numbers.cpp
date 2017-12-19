#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
bool d[32005];
int main() {
	int n, c;
	cin>>n; 
	while(n--){
		memset(d, 0, sizeof(d));
		cin>>c;
		for(int i=1; i<=sqrt(c); i++){
			if (c%i==0){
				d[c/i+i]=1;
			}
		}
		bool dn=0;
		for(int i=1; i<=sqrt(c); i++){
			if (c%i==0 && d[c/i-i]) {dn=1; break;}
		}
		cout<<c<<" is ";
		if (!dn){ cout<<"not "; }
		cout<<"nasty\n";
	}
	return 0;
}