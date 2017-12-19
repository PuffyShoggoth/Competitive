#include <iostream>
#include <string>
using namespace std;
int main()
{
  int rows, cols, ncats;
  cin>>rows;
  cin>>cols;
  cin>>ncats;
  int cages[rows][cols];
  for (int i=0; i<rows; i++){
      for (int k=0; k<cols; k++){
          cages[i][k]=0;
      }
  }
  for (int i=0; i<ncats; i++){
      int row, col;
      cin>>row;
      cin>>col;
      cages[row-1][col-1]=-1;
  }
  for (int i=0; i<rows; i++){
      if (cages[i][0]==-1){break;}
      cages[i][0]=1;}
  for (int k=0; k<cols; k++){
      if (cages[0][k]==-1){break;}
      cages[0][k]=1;}
  for (int i=1; i<rows; i++){
      for (int k=1; k<cols; k++){
          if (cages[i][k]!=-1){
              if (cages[i-1][k]!=-1){cages[i][k]=cages[i-1][k];}
              if (cages[i][k-1]!=-1){cages[i][k]+=cages[i][k-1];}
              }
      }
  }
  cout<<cages[rows-1][cols-1];
}