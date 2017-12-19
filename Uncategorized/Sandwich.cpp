#include <iostream>
#include <cstdio>
#include <deque>
char t[100009];
using namespace std;
int main(){
	int n;
	string t;
	deque<int> dq;
	cin>>n;
	cin>>t;
	for (int i=1; i<=n; i++){
		if (t[i-1]=='0'){dq.push_back(i);}
		if (t[i-1]=='1'){dq.push_front(i);}
	}
	for(int i=0; i<n; i++){
		printf("%i\n", dq[i]);
	}
	return 0;
}