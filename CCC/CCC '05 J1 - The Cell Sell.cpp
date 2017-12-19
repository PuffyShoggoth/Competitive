#include <cstdio> 

using namespace std;

int main(){
	float plana=0, planb=0;
	int tmp; 
	scanf("%i", &tmp);  
	if (tmp>100){
		plana = (tmp-100)*25;
	}
	
	if (tmp>250){planb = (tmp-250) * 45;
	}
	scanf("%i", &tmp); 
	
	plana+= tmp*15;
	planb+=tmp*35;
	scanf("%i", &tmp);
	plana+= tmp*20;
	planb+=tmp*25;
	printf("Plan A costs %.2f\n", plana/100); 
	printf("Plan B costs %.2f\n", planb/100);

	if (plana==planb){
		printf("Plan A and B are the same price.\n");
	}
	else if (plana>planb){
		printf("Plan B is cheapest.");
	}
	else{
		printf("Plan A is cheapest.");
	}
	return 0;
}