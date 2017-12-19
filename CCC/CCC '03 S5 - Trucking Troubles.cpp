#include <iostream>
#include <vector>
#include <queue>
#define INF 9999999
#include <utility>
#include <functional>
using namespace std;
vector <pair<int, int> >roads[100009];
int flags[10009];
int weights[10009];
int main()
{
  int c, r, d, x, y, w, m, dc;
  pair <int, int> t;
  cin>>c>>r>>d;
  for (int i=1; i<=c; i++){
      weights[i]=-1;
  }
  for (int i=1; i<=r; i++){
      scanf("%i%i%i", &x, &y, &w);
      roads[x].push_back(make_pair(w, y));
      roads[y].push_back(make_pair(w, x));
  }
  priority_queue <pair<int, int> , vector<pair<int, int> >, less<pair<int, int> > >nxtrd;
  nxtrd.push(make_pair(INF, 1));
  while (nxtrd.size()>0){
      t=nxtrd.top();
      nxtrd.pop();
      if (weights[t.second]<t.first && flags[t.second]==0){
          weights[t.second]=t.first;
          for (int i=0; i<roads[t.second].size(); i++){
              nxtrd.push(make_pair(min(t.first, roads[t.second][i].first), roads[t.second][i].second));
          }
      flags[t.second]=1;
      }
  }
  m=INF;
  for (int i=1; i<=d; i++){
        scanf("%i", &dc);
        m=min(m, weights[dc]);
  }
  cout<<m;
  return 0;
}