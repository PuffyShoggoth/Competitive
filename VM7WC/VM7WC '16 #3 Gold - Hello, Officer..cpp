#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <utility>
using namespace std;
int fl[2005];
vector <pair<int, int> >adl[2005];

int v[2005];
int main()
{
    int n, m, b, x, y, z, q, r;
    cin>>n>>m>>b>>q;
    pair <int, int> f;
    for (int i=0; i<m; i++){
        cin>>x>>y>>z;
        adl[x].push_back(make_pair(z, y));
        adl[y].push_back(make_pair(z, x));
    }
    priority_queue<pair<int, int>, deque<pair<int, int> >, greater<pair <int, int> > >s;
    s.push(make_pair(0, b));
    for (int i=0; i<=n; i++){
        v[i]=90000009;
        }
    while (s.size()>0){
        f=s.top();
        s.pop();
        if (f.first<v[f.second]){
            v[f.second]=f.first;
            fl[f.second]=-1;
            for (int i=0; i<adl[f.second].size(); i++){
                if (fl[adl[f.second][i].second]!=-1){
                    s.push(make_pair(f.first+adl[f.second][i].first, adl[f.second][i].second));
                }
            }
        }
    }
        for (int i=0; i<q; i++){
            cin>>r;
            if (v[r]!=90000009){
            cout<<v[r]<<"\n";}
            else{ cout<<-1<<"\n";}
        }
    
    return 0;       
}