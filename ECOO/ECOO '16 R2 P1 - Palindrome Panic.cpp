#include <string>
#include <iostream>
#include <functional>
using namespace std;
string a, ra;
int n;
int b[1000005];
int c[1000005];
void prep(int ar[1000005], string s){
	ar[0]=-1;
	int i=-1, j=0;
	while(j<n){
		while(i>=0 && s[i]!=s[j]) i=ar[i];
		i++; j++;
		ar[j]=i;
	}
}
int mm(string f, string s, int t[1000005]){
	int i=0, j=0;
	while(i<n){
		while(j>=0 && f[j]!=s[i]) j=t[j];
		i++; j++;
	}
	return j;
}
int main() {
	for(int dnr=0; dnr<10; dnr++){
	    a.clear();
		cin>>a;
		n=a.length();
		ra.clear();
		for(int i=n-1; i>=0; i--){
			ra.push_back(a[i]);
		}
		prep(b, a); prep(c, ra);
		printf("%i\n", n-max(mm(a, ra, b), mm(ra, a, c)));
	}
	return 0;
}