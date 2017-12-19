#include <iostream>
#include <string.h>
using namespace std;
char s[100006];
int n[100006];
int main()
{
  cin>>s;
  int ends, nq, fn, sn;
  ends=strlen(s);
  if (s[0]=='G'){n[0]+=1;}
  for (int i=1; i<ends; i++){
      if (s[i]=='G'){n[i]=n[i-1]+1;}
      else{n[i]=n[i-1];}
  }
  cin>>nq;
  for (int i=0; i<nq; i++){
      cin>>fn>>sn;
      if (fn==0){cout<<n[sn]<<"\n";}
      else {cout<<n[sn]-n[fn-1]<<"\n";}
  }
  return 0;
}