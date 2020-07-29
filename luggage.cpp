#include<stdio.h>
using namespace std;

int max(int a, int b){
    return(a>b)? a : b;
}

int luggage(int sum, int bags[], int count){

	sum/=2;
	int dp[202];
	dp[0] = 1;
	for(int i=1;i<=sum;i++){
		dp[i] = 0;
	}	
	
	for(int i=0;i<count;i++){
		for(int j=sum;j>=bags[i];j--){
			if(dp[j - bags[i]]==1) dp[j] = 1;
		}
	}
	
	return dp[sum];
}

int main(){
	int t, tempBag;
	int bags[22];
	int sum = 0;
	
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		sum = 0;
		int j = 0;
		char c = ' ';
		while(c!='\n'){
			scanf("%d%c", &tempBag,&c);
			bags[j++] = tempBag;
			sum+=tempBag;
		}
		
		if(sum%2==1){
			puts("NO");
		} else {
			int f = luggage(sum, bags, j);
			printf("%s\n",(f==1)?"YES" : "NO");
		}
		
	
		
	}
	return 0;
}
