#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector <string> gorf[1008];
int main()
{
  int n, emp, q, sk, d;
  cin>>n;
  bool tf=0;
  string empn;
  for (int p=0; p<n; p++){
      cin>>empn>>emp;
      gorf[emp].push_back(empn);
  }
  cin>>q;
  for (int p=0; p<q; p++){ 
      cin>>sk>>d;
      tf=0;
      for (int wataa=sk; wataa<=min(sk+d, 1000); wataa++){
          if (gorf[wataa].size()>0){cout<<gorf[wataa][0]<<"\n"; tf=1; break;}
          }
      if (tf==0){cout<<"No suitable teacher!"<<"\n"; }
  }
  return 0;
      
}