#include <iostream>
#include <string>
using namespace std;
string a, b;
int t[1000005];
void prep(){
	t[0]=-1;
	int i=-1, j=0;
	while(j<b.size()){
		while(i>=0 && b[i]!=b[j]) i=t[i];
		i++; j++;
		t[j]=i;
	}
	return;
}
int mtch(int sv){
	int j=0;
	while(sv<a.size()){
		while(j>=0 && a[sv]!=b[j])j=t[j];
		sv++; j++;
		if (j==b.size()){
			return j;
		}
	}
	return j;
}
int main() {
	cin>>a>>b;
	prep();
	int tp;
	tp=mtch((a.size()>=b.size()?(a.size()-b.size()):0));
	cout<<a.append(b, tp, string::npos);
	return 0;
}