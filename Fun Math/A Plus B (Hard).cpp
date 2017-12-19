#include <cstdio>
#include <string>
using namespace std;
char a[100050];
char b[100050];
char res[100050];
bool nega, negb;
int sizea, sizeb;
void printnumbs(int size){
	int i=0;
	while(i<=size && res[i]==0){
		i++;
	}
	while(i<=size){
		printf("%i", res[i]);
		i++;
	}
	return;
}
void printnumb(int size){
	int i=0;
	while(i<=size){
		printf("%i", res[i]);
		i++;
	}
	return;
}	
void scanhuge(bool &neg, int &size, char scanto[]){
	char tmp;
	do{tmp=getchar();}while(tmp<'-');
	if (tmp=='-'){
		neg=1;
		tmp=getchar();}
	else{neg=0;}
	size=0;
	while(tmp>'-'){
		scanto[size]=tmp-'0';
		size++;
		tmp=getchar();
	}
	size-=1;
	return;
}
int grter(){
	if (sizea>sizeb) return 1;
	else if (sizeb>sizea) return 0;
	for(int i=0; i<=sizea; i++){
		if (a[i]>b[i]) return 1;
		else if (b[i]>a[i]) return 0;
	}
	return -1;
}
void subtract(char g[], char l[], int gs, int ls){
	char carry=0;
	while (ls>=0){
		if (g[gs]>=(l[ls]+carry)){
			res[gs]=g[gs]-l[ls]-carry;
			carry=0;
		}
		else{
			res[gs]=10+(g[gs]-(l[ls]+carry));
			carry=1;
		}
		gs--; ls--;
	}
	while (gs>=0){
		if (g[gs]-carry<0){
			res[gs]=9;
			carry=1;
		}
		else{
			res[gs]=g[gs]-carry;
			carry=0;
		}
		gs--;
	}
	return;
}
char add(char g[], char l[], int gs, int ls){
	char carry=0;
	while (ls>=0){
		res[gs]=(g[gs]+l[ls]+carry)%10;
		if ((g[gs]+l[ls]+carry)>=10){carry=1;}
		else{carry=0;}
		gs--; ls--;
	}
	while (gs>=0){
		if (g[gs]+carry==10){
			res[gs]=0;
			carry=1;
		}
		else{
			res[gs]=g[gs]+carry;
			carry=0;
		}
		gs--;
	}
	return carry;
}
int main()
{
  int n, inttmp;
  char frst;
  scanf("%i", &n);
  while(n--){
  	scanhuge(nega, sizea, a);
  	scanhuge(negb, sizeb, b);
  	inttmp=grter();
  	if (nega!=negb){
  		if (inttmp==-1){printf("0");}
  		else if (inttmp==1){
  			subtract(a, b, sizea, sizeb);
  			if (nega){printf("-");}
  			printnumbs(sizea);
  		}
  		else{
  			subtract(b, a, sizeb, sizea);
  			if (negb){printf("-");}
  			printnumbs(sizeb);
  		}
  	}
  	else{
  		if (inttmp==1){
  			frst=add(a, b, sizea, sizeb);
  			if (nega){printf("-");}
  			if (frst==1){printf("1");}
  			printnumb(sizea);
  		}
  		else{
  			frst=add(b, a, sizeb, sizea);
  			if (nega){printf("-");}
  			if (frst==1){printf("1");}
  			printnumb(sizeb);
  		}
  		
  	}
  	printf("\n");
  }
  return 0;
  
}