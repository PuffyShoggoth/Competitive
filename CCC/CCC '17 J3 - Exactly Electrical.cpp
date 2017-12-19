#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d, t, vs;
	scanf("%i%i%i%i%i", &a, &b, &c, &d, &t);
	vs = abs(a-c) + abs(b-d);
	if (t<vs || (t-vs)%2==1) printf("N");
	else printf("Y");

}