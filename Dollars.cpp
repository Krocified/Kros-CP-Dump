#include <stdio.h>
#include <math.h>
#define ll long long int
ll count(int coins[], ll x, ll y){
	
	ll dp[y+1][x];
	for(ll i=0;i<x;i++) dp[0][i] = 1;

	for(ll i=1;i<y+1;i++){ // fill up
		for(ll j=0;j<x;j++){ // loop per coin
			
			ll xx = 0, yy = 0;
			
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
	
	int dollars[12] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
	double value = -1;
	
	while(scanf("%lf", &value)!=EOF){
		
		if(value==0.00)break;
		value = static_cast<int>(value*100 + 0.1);	
			
		printf("%6.2f%17lld\n", value/100, count(dollars, 11, value));
	}
	
	
	return 0;
}
