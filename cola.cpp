#include <stdio.h>

int main(){
	
	int bottle;
	int drink;
	
	while(scanf("%d", &bottle)==1){
		
		drink = 0;
		drink += bottle; 
		
		while(bottle>=3){
			drink += bottle/3; 
			bottle = bottle/3 + bottle%3; 
		}
		
		if(bottle==2) drink++;
		printf("%d\n",drink);
	}
	return 0;
}
