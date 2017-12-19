#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
	unordered_set<int> p;
	int n, ce, t;
	cin>>n;
	t=0;
	for (int i=0; i<n; i++){
		cin>>ce;
		if (p.count(ce)==0){
			t+=1;
			p.insert(ce);
		}
	}
	cout<<t;
}