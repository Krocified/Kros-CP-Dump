#include <stdio.h>

int main(){
	
	int num;
	
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d", &num)==1){
		
		if(num==0)break;
		
		int factors[100];
		int count=0;
		
		for(int i=1;i<num;i++){
			if (num%i==0){
				factors[count]=i;
				count++;	
			}
		}
	
		int sum=0;
		for(int i=0;i<count;i++){
			sum+=factors[i];
		}
		
		if(num==sum){
			printf("%5d  PERFECT\n",num);
		} else if(num>sum){
			printf("%5d  DEFICIENT\n",num);
		} else if(num<sum){
			printf("%5d  ABUNDANT\n",num);
		} 
		
	}
	
	printf("END OF OUTPUT\n");
	return 0;
}
