#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int vls[4];
int main() {
	for(int i=0; i<4; i++){
		scanf("%i", &vls[i]);
	}
	if((vls[0]==8 || vls[0]==9) && (vls[3]==8 || vls[3]==9) && (vls[1]==vls[2])){
		printf("ignore");
	}
	else{
		printf("answer");
	}
    return 0;
}