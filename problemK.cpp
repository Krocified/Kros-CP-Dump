#include <stdio.h>

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b); 
}

int main(){
	int l;
	scanf("%d",&l);
	
	int numList[20001];
	for(int i = 0;i<l;i++){
		scanf("%d",numList[i]);	
	}
	
	int ctr = 0;
	int i = 0;
	int j = 1;
	
	while(1){
	    if (j<l){
	        if (numList[i] > 0 && numList[j]> 0 && numList[i]<numList[j] && gcd(numList[i],numList[j])%2==1){
	            numList[i]=-1;
	            numList[j]=-1;
	            ctr+=1;
	            i = 0;
	            j = 1;
	        }else{    
				j+=1;
			}
		} else if (i<l){
	        i+=1;
	        j=i+1;
		}
	    else break;
	}
	printf("%d",ctr);
	return 0;
}
	
