#include <stdio.h>
#define ll long long int


ll tribonacci(ll x){
	
	ll matrix[3][3] = {1,1,1,1,0,0,0,1,0};
	ll result[3][3] = {1,0,0,0,1,0,0,0,1};
	ll temp[3][3];
	ll ans;
	
	while(x>0){
		if(x&1){
			for(int i=0;i<3;i++){
				temp[i][0] = result[i][0]*matrix[0][0] + result[i][1]*matrix[1][0] + result[i][2]*matrix[2][0];
				temp[i][1] = result[i][0]*matrix[0][1] + result[i][1]*matrix[1][1] + result[i][2]*matrix[2][1];
				temp[i][2] = result[i][0]*matrix[0][2] + result[i][1]*matrix[1][2] + result[i][2]*matrix[2][2];	
			}
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					result[i][j] = temp[i][j] % 1000000009;
				}
			}
		}
		
		x = x>>1;
		for(int i=0;i<3;i++){
				temp[i][0] = matrix[i][0]*matrix[0][0] + matrix[i][1]*matrix[1][0] + matrix[i][2]*matrix[2][0];
				temp[i][1] = matrix[i][0]*matrix[0][1] + matrix[i][1]*matrix[1][1] + matrix[i][2]*matrix[2][1];
				temp[i][2] = matrix[i][0]*matrix[0][2] + matrix[i][1]*matrix[1][2] + matrix[i][2]*matrix[2][2];	
			}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				matrix[i][j] = temp[i][j] % 1000000009;
			}		
		}	
		
	}
	
	ans = result[0][0]*2 + result[0][1]*1 + result[0][2]*0;
	return ans % 1000000009;
	
}

int main(){
	
	ll input=-1;
	while(input!=0){
		scanf("%lld",&input);
		if(input==0) break;
		if(input==1) printf("0\n");
		else if(input==2) printf("1\n");
		else if(input==3) printf("2\n");
		else printf("%lld\n",tribonacci(input-3));
//		puts("");
	}
		
	return 0;
}
