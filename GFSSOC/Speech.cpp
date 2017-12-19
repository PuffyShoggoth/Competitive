#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, string> frwords;
map<string, string>:: iterator it;
int main(){
    int n;
    string ta, tb;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ta>>tb;
        frwords[tb]=ta;
    }
    cin>>ta;
    while(ta.back()!='.'){
        it=frwords.find(ta);
        if (it!=frwords.end()){
            cout<<it->second<<' ';
        }
        else{ cout<<ta<<' ';}
        cin>>ta;
    }
    ta.erase(ta.end()-1, ta.end());
    it=frwords.find(ta);
    if (it!=frwords.end()){
        cout<<it->second<<'.';
    }
    else{ cout<<ta<<'.';}
    return 0;
}