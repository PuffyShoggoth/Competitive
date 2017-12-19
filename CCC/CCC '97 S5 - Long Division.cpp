#include <bits/stdc++.h>
using namespace std;
deque <int> a, b, q;
bool gt(){
	if (a.size()<b.size()) return 0;
	for(int i=0; i<b.size(); i++){
		if (a[i]>b[i]){ return 1; }
		else if (a[i]<b[i]) {return 0; }
	}
	return 1;
}
void mn(){
	a[0]-=b[0]; int tp;
	for(int i=1; i<b.size(); i++){
		if (b[i]>a[i]){
			a[i]+=10; tp=i-1;
			while(!a[tp]){ a[tp]=9; tp--; }
			a[tp]--;
		}
		a[i]-=b[i];
	}
	return;
}
int main() {
	int n, t;
	cin>>n; 
	string tp;
	while(n--){
		a.clear(); b.clear(); q.clear();
		cin>>tp;
		for(int i=0; i<tp.length(); i++) {a.push_back(tp[i]-'0'); }
		cin>>tp;
		for(int i=0; i<tp.length(); i++) {b.push_back(tp[i]-'0'); }
		while(a.size()>=b.size()){
			q.push_back(0);
			while(gt()){
				mn(); q.back()++;
			}
			if (a.size()<=b.size()) { break; }
			t=a.front(); a.pop_front(); a.front()+=t*10;
		}
		while(!q.empty() && q.front()==0){ q.pop_front(); }
		if (q.empty()) {cout<<0; }
		while(!q.empty()) {cout<<q.front(); q.pop_front(); }
		cout<<"\n";
		while(!a.empty() && a.front()==0){ a.pop_front(); }
		if (a.empty()) { cout<<0; }
		while(!a.empty()){ cout<<a.front(); a.pop_front(); }
		cout<<"\n\n";
	}
	return 0;
}