#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b;
	string s;
	cin>>a>>s>>b;
	if (s[0]=='I')cout<<a-b;
	else cout<<a+b;
	return 0;
}