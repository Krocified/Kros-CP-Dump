#include <stdio.h>

int count(int coins[], int x, int y){
	
	int dp[y+1][x];
	for(int i=0;i<x;i++) dp[0][i] = 1;

	for(int i=1;i<y+1;i++){ // fill up
		for(int j=0;j<x;j++){ // loop per coin
			
			int xx = 0, yy = 0;
			
			if(i-coins[j]>=0){ 
				xx = dp[i-coins[j]][j]; // take coin
			}
			if(j>=1){
				yy = dp[i][j-1]; // skip coin
			}
			
			dp[i][j] = xx+yy; // return skip + take
			
		}
	}
	
	return dp[y][x-1];
}

int main(){
	
	int coins[6] = {1, 5, 10, 25, 50};
	int value;
	
	while(scanf("%d", &value)!=EOF){
		printf("%d\n", count(coins, 5, value));
	}
	
	
	return 0;
}
