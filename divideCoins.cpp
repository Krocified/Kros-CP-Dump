#include<stdio.h>
using namespace std;

int max(int a, int b){
    return(a>b)? a : b;
}

int knapsack(int w, int coins[], int n){  
   int dp[n+2][w+2]; 
  
   for (int i = 0; i <= n; i++){ 
       for (int j = 0; j <= w; j++){ 
           if (i==0 || j==0){
            	dp[i][j] = 0; 
		   } else if (coins[i-1] <= j){
		    	dp[i][j] = max(coins[i-1] + dp[i-1][j-coins[i-1]], dp[i-1][j]); 
		   } else {
				dp[i][j] = dp[i-1][j]; 
		   }
       } 
   } 
  
   return dp[n][w]; 
} 

int main(){
	int t, n, tempCoin;
	int coins[502];
	int sum = 0;
	
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		sum = 0;
		scanf("%d",&n);
		for(int j = 0;j<n;j++){
			scanf("%d", &tempCoin);
			coins[j] = tempCoin;
			sum+=tempCoin;	
		}
		
		int w = sum/2;
		
		printf("%d\n",sum - 2*knapsack(w, coins, n));
		
	}
	return 0;
}
