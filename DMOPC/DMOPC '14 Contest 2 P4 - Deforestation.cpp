#include <iostream>
using namespace std;
int tc[1000009];
int main()
{
  int nt, q, a, b;
  cin>>nt;
  cin>>tc[0];
  for (int i=1; i<nt; i++){
      scanf("%i", &tc[i]);
      tc[i]+=tc[i-1];
  }
  cin>>q;
  for (int i=0; i<q; i++){
      scanf("%i%i", &a, &b);
      if (a==0){printf("%i%s", tc[b], "\n");}
      else{printf("%i%s", tc[b]-tc[a-1], "\n");}
  }
   return 0;
}