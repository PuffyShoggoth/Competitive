#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
char coded[100005];
char cipher[26];
char decrypt[26];
char match[9];
vector<int> patterns;
int shift[9]={7, 0, 8, 11, 7, 24, 3, 17, 0}; 
int n=0;

bool correct(){
	bool tmp;
    for(int i=0; i<patterns.size(); i++){
    	tmp=1;
    	for(int j=0; j<9; j++){
    		if (coded[patterns[i]+j]!=match[j]){
    			tmp=0;
    			break;
    		}
    	}
    	if (tmp) return 1;
    }
    return 0;
}
void decypher(){
	int inttmp;
	for(int i=0; i<26; i++){
		inttmp=cipher[i];
		decrypt[inttmp-65]='A'+i;
	}
    for(int i=0; i<n-1; i++){
    	inttmp=coded[i];
        printf("%c", decrypt[inttmp-65]);
    }
    return;
}
        
int main()
{
  int m;
  char a;
  bool found, fits;
  do{
      a=getchar();
      coded[n]=a;
      n++;
    }
  while(a>='A' && a<='Z');
  scanf("%i", &m);
  for(int i=0; i<n-9; i++){
  		fits=1;
  		if (coded[i]==coded[i+4] && coded[i+1]==coded[i+8]){
  			for(int j=i; j<i+8; j++){
  				if (j==i+4) continue;
  				for(int k=j+1; k<i+9; k++){
  					if (k==i+4 && j==i){continue;}
  					if (j==i+1 && k==i+8){continue;}
  					if (coded[j]==coded[k]){
  						fits=0; 
  						break;}
  				}
  				if (!fits){break;}
  			}
  			if (fits){patterns.push_back(i);}	
  		}
  }
  while(m--){
    do{
        cipher[0]=getchar();
    }
    while(cipher[0]<'A' || cipher[0]>'Z');
    for(int i=1; i<26; i++){
        cipher[i]=getchar();
    }
    for(int i=0; i<9; i++){
        match[i]=cipher[shift[i]];
    }
    found=correct();
    if (found){
        decypher();
        break;
    }
  }
  if (!found){
      printf("KeyNotFoundError");
  }
    return 0;
}