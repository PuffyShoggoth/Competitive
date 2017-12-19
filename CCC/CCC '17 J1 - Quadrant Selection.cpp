#include <bits/stdc++.h>

using namespace std;

int main(){
	int x, y;
	scanf("%i%i", &x, &y);
	if (x<0 && y<0){
		printf("3");
	}
	else if (x<0){
		printf("2");
	}
	else if (y<0){
		printf("4");
	}
	else{
		printf("1");
	}
}