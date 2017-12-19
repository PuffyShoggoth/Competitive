#include <iostream>
using namespace std;
void FizzFuzz(int i){
	if ((i%7==0) || (i%13==0)){
		if(i%7==0){cout<<"Fizz ";}
		if(i%13==0){cout<<"Fuzz ";}
	}
	else{cout<<i<<" ";}
	return;
}
int main() {
	int n, a=1, b=1;
	cin>>n;
	for(int i=0; i<n; i++){
		FizzFuzz(a);
		FizzFuzz(b);
		cout<<"\n";
		a++;
		b+=2;
	}
	return 0;
}