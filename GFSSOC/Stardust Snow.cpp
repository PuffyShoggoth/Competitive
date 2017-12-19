#include <iostream>
#include <utility>
using namespace std;
int snowfall[55][55][55][55];
pair<int, int>flakes[55][55];
int main()
{
  int rows, cols, snowflakes, explode, done, move;
  cin>>rows>>cols>>snowflakes>>explode>>done>>move;
  for (int i=0; i<snowflakes; i++){
      int  temp, value, col, row;
      cin>>temp>>value>>col>>row;
      if (temp<explode){
      flakes[row][col]=make_pair(value, temp);
      snowfall[row][col][1][temp]=value;}}
  for (int i=0; i<rows; i++){
      for (int j=1; j<=min(move*i+1, cols); j++){
          for (int p=max(1, j-move); p<=min(j+move, cols); p++){
              for (int k=0; k<min(done, i+1); k++){
                  for (int l=0; l<explode-flakes[i+1][p].second; l++){
                  
                      snowfall[i+1][p][k][l]=max(snowfall[i+1][p][k][l], snowfall[i][j][k][l]);
                      snowfall[i+1][p][k+1][l+flakes[i+1][p].second]=max(max(snowfall[i+1][p][k+1][l+flakes[i+1][p].second], snowfall[i][j][k][l+flakes[i+1][p].second]), snowfall[i][j][k][l]+flakes[i+1][p].first);
                   }
               }
          for (int l=0; l<explode-flakes[i+1][p].second; l++){
                  snowfall[i+1][p][min(done, i+1)][l]=max(snowfall[i+1][p][min(done, i+1)][l], snowfall[i][j][min(done, i+1)][l]);}
          for (int k=1; k<=min(done, i); k++){
              for (int l=explode-flakes[i+1][p].second; l<explode; l++){
                      snowfall[i+1][p][k][l]=max(snowfall[i+1][p][k][l], snowfall[i][j][k][l]);
                   }
               }
           }
       }

  }
  int tpt=0;
  for (int j=1; j<=min(move*rows+1, cols); j++){
      for (int k=0; k<=min(done, rows); k++){
              for (int l=0; l<explode; l++){
                  tpt=max(tpt, snowfall[rows][j][k][l]);}
      }
  }
  cout<<tpt<<endl;

  return 0;
}