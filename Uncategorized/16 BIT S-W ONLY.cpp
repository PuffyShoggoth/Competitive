#include <cstdio>
using namespace std;
int main()
{
  int n;
  long long int a, b, p;
  scanf("%i", &n);
  for (int i=0; i<n; i++){
      scanf("%lli%lli%lli", &a, &b, &p);
      if ((a*b)==p){
          printf("POSSIBLE DOUBLE SIGMA\n");
      }
      else{
          printf("16 BIT S/W ONLY\n");
      }
  }
    return 0;
}