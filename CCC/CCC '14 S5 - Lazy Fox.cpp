#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <algorithm>
#define mp(a,b) make_pair(a,b)
#define dst(a,b,c,d) ((a-c)*(a-c)+(b-d)*(b-d))
#define f first
#define s second
using namespace std;
vector<pair<int, int> >locations;
vector<pair<int, pair<int, int> > >distances;
pair<int, int> dp[2009][2];
void update(int a, int b, int d){
    if(a==0){return;} 
    if(dp[a][0].s==d){
          if (dp[b][0].f<(dp[a][1].f+1)){
              if (dp[b][0].s<d){dp[b][1]=dp[b][0];}
              dp[b][0]=mp(dp[a][1].f+1, d);
          }
    }
    else if (dp[b][0].f<(dp[a][0].f+1)){
        if (dp[b][0].s<d){dp[b][1]=dp[b][0];}
        dp[b][0]=mp(dp[a][0].f+1, d);
    }
    return;
}
    
int main()
{
  int n, x, y;
  scanf("%i", &n);
  locations.push_back(mp(0, 0));
  for(int i=0; i<n; i++){
      scanf("%i%i", &x, &y);
      locations.push_back(mp(x, y));
  }
  for(int i=0; i<=n; i++){
      for(int j=i+1; j<=n; j++){
          distances.push_back(mp(dst(locations[i].f, locations[i].s, locations[j].f, locations[j].s), mp(i, j)));
      }
  }
  sort(distances.begin(), distances.end());
  for(int i=0; i<distances.size(); i++){
      update(distances[i].s.f, distances[i].s.s, distances[i].f);
      update(distances[i].s.s, distances[i].s.f, distances[i].f);
  }
  printf("%i", dp[0][0].f);
  return 0;    
}