#include <iostream>
#include <vector>
using namespace std;
int j[1000006];
vector <int> v;
int l[1000006];
int main()
{
  int nj, nl, c, f=-1, vs, qw;
  cin>>nj;
  for (int i=1; i<=nj; i++){
      scanf("%i", &c);
      j[c]=i;}
  cin>>nl;
  for (int i=0; i<nl; i++){
  	  scanf("%i", &c);
      l[i]=c;
  }
  v.push_back(0);
  for (int i=0; i<nl; i++){
      if (j[l[i]]!=0){
          f=i;
          v.push_back(j[l[i]]);
          break;}
  }
  if (f!=-1){
  for (int i=f+1; i<nl; i++){
      if (j[l[i]]!=0){
          vs=v.size();
          if (v[vs-1]<j[l[i]]){
              v.push_back(j[l[i]]);}
          else{ qw=(vs-1)/2;
          if (v[qw]<j[l[i]]){
          	for (int k=qw; k<vs-1; k++){
              if (j[l[i]]>v[k]){
                  if (j[l[i]]<v[k+1]){
                  v[k+1]=j[l[i]];
                  break;}
          }}}
          	else{ for (int k=0; k<qw; k++){
              if (j[l[i]]>v[k]){
                  if (j[l[i]]<v[k+1]){
                  v[k+1]=j[l[i]];
                  break;}
          }}}}
          
         
  }}}
  cout<<v.size()-1<<"\n";
  return 0;
}