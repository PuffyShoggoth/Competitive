#include <iostream>
using namespace std;
int chocolate[100090];
int choco(int rem, int x, int y, int z){
	if (rem<0){return -999999;}
	if (chocolate[rem]!=0){return chocolate[rem];}
	if (rem==0){return 0;}
	chocolate[rem]=max(choco(rem-x, x, y, z), choco(rem-y, x, y, z));
	chocolate[rem]=max(chocolate[rem], choco(rem-z, x, y, z));
	if (chocolate[rem]<0){return -999999;}
	chocolate[rem]+=1;
	return chocolate[rem];
}

int main() {
	int n, x, y, z, t;
	cin>>n>>x>>y>>z;
	t=choco(n, x, y, z);
	cout<<t;
	return 0;
}