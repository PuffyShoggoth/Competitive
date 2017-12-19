#include <iostream>
using namespace std;
int sp[400009];
int tar[400009];
int main()
{
  int n, s, f, m=-10000;
  cin>>n;
  for (int i=0; i<n-1; i++){
      scanf("%i%i", &s, &f);
      sp[f]=s;}
  for (int i=1; i<=n; i++){
      scanf("%i", &tar[i]);
      }
  for (int i=n; i>1; i--){
      tar[sp[i]]+=tar[i];
      }
  for (int i=1; i<=n; i++){
      m=max(tar[i], m);
      }
  cout<<m;
 return 0;
}