#include <iostream>
#define INF 922337203685477587
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
pair <int, int> countries[3009];
int flag[3009];
long long int dist[3009];
vector <long long int> spots;
long long int distcl(pair<int, int>xyf, pair<int, int>xys){
    long long int k, j;
    k=max(xyf.first, xys.first)-min(xyf.first, xys.first);
    j=max(xyf.second, xys.second)-min(xyf.second, xys.second);
    return k*k+j*j;
}

int main()
{
  int n, x, cv, nv, cx, cy, q, m, s, e;
  long long int qi=0;
  cin>>n;
  for (int i=1; i<=n; i++){
      scanf("%i%i", &cx, &cy);
      countries[i]=make_pair(cx, cy);
  }
  cin>>x;
  long long int mads=INF;
  cv=x;
  for (int i=1; i<=n; i++){
      dist[i]=distcl(countries[i], countries[x]);
      if (dist[i]<mads){
          mads=dist[i];
          cv=i;}
  }
  flag[x]=1;
  while (cv>0){
      mads=INF;
      nv=-1;
      for (int i=1; i<=n; i++){
          if (flag[i]==0){
      dist[i]=min(dist[i], dist[cv]+distcl(countries[i], countries[cv]));
      if (dist[i]<mads){
          mads=dist[i];
          nv=i;}
  }
  }
  flag[cv]=1;
  cv=nv;
  }
  for (int i=1; i<=n; i++){
      spots.push_back(dist[i]);
  }
  sort(spots.begin(), spots.end());
  cin>>q;
  for (int i=0; i<q; i++){
      scanf("%lld", &qi);
      s=0; e=spots.size();
      while (e>=s){
          m=(s+e)/2;
          if (spots[m]==qi){s=m+1;}
          if (spots[m]>qi){
              e=m-1;}
          if (spots[m]<qi){
              s=m+1;}
          
      }
     s=spots.size();
     cout<<min(s, e+1)<<"\n";
  }
          
  return 0;
}