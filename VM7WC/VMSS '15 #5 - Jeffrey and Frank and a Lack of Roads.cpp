#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
pair<int, vector<int> >dp[1009][1009];
pair <int, pair<int, int> > applestats[10];
vector<string> applenames;
int n, r, s;
pair<int, vector<int> >optimalapples(int mny, int spc){
	vector<int>flr(n, 0);
	pair<int, vector<int> > tp, lr;
    if (spc<0 || mny<0){return make_pair(-1, flr);}
    if (dp[mny][spc].second.size()!=0){return dp[mny][spc];}
    lr=make_pair(0, flr);
    if (spc==0 || mny==0){return lr;}
    for(int i=0; i<n; i++){
        tp=optimalapples(mny-(applestats[i].second.first), spc-(applestats[i].second.second));
        if (tp.first==-1){continue;}
        if ((tp.first+(applestats[i].first))>lr.first){
        lr=tp;
        lr.first+=(applestats[i].first); lr.second[i]+=1;
        }
    }
    dp[mny][spc]=lr;
    return dp[mny][spc];

}
int main(){
    int v, a, b;
    string e;
    cin>>n>>r>>s;
    for(int i=0; i<n; i++){
        cin>>e>>v>>a>>b;
        applenames.push_back(e);
        applestats[i]=make_pair(v, make_pair(a, b));
    }
    pair<int, vector<int> > tl=optimalapples(r, s);
    cout<<tl.first<<"\n";
    for(int i=0; i<n; i++){
        cout<<applenames[i]<<" "<<tl.second[i]<<"\n";
    }
    return 0;
}
//long story