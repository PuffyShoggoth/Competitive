#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <string>
using namespace std;
vector<pair<int, string> > dcs;
vector<pair<int, string> >:: iterator it;
int main(){
    int n, m, ita, itb;
    string tmp;
    cin>>n>>m;
    for(int i=0; i<m; i++){
    	cin>>ita>>itb;
    	cin.ignore(1, '\n');
    	getline(cin, tmp);
    	dcs.push_back(make_pair(itb, tmp));
    }
    cin>>n;
    for(it=dcs.begin(); it!=dcs.end(); ++it){
    	if (it->first==n){
    		cout<<it->second<<"\n";
    	}
    }
    return 0;
}