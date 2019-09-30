#include <stdio.h>

int threeNPlusOne(int n){
	int count=1;
	
	while(1){
		if (n == 1) break;
		if (n % 2 == 1){
			n = 3*n+1;
			count++;
		} else {
			n = n/2;
			count++;
		}
	}
	return count;
}

int main(){
	
	int i,j;
	int max, temp,swap;
	while(scanf("%d %d",&i,&j)!=EOF){
		max=0;
		swap=0;
		if (i>j){
			int temp = i;
			i = j;
			j = temp;
			swap++;
		}
		
		for (int x = i; x<=j; x++){
			
			temp = threeNPlusOne(x);
			if(temp>max){
				max = temp;
			}
		}
		
		if (swap==1){
			int temp = i;
			i = j;
			j = temp;
			swap--;
		}
		
		printf("%d %d %d\n",i,j,max);
		
	}
	
	return 0;
}
