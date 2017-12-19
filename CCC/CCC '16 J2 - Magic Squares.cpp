#include <iostream>
#include <cstdio>
using namespace std;

int squares[4][4];
int main() {
	bool t=1;
	int s=0, ts;
	for (int i=0; i<4; i++){
		for (int k=0; k<4; k++){
			scanf("%i", &squares[i][k]);
		}
	}
	for(int i=0; i<4; i++){
		s+=squares[0][i];
	}
	for(int i=1; i<4; i++){
		ts=0;
		for (int k=0; k<4; k++){
			ts+=squares[i][k];
		}
		if (ts!=s){t=0;}
	}
	for(int i=0; i<4; i++){
		ts=0;
		for (int k=0; k<4; k++){
			ts+=squares[k][i];
		}
		if (ts!=s){t=0;}
	}
	if (t){cout<<"magic";}
	else{cout<<"not magic";}
	return 0; 
}