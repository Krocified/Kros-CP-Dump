#include <stdio.h>
#include <math.h>
#define ll long long int

ll modFib(ll x, ll y){
	
	ll matrix[2][2] = {1,1,1,0};
	ll result[2][2] = {1,0,0,1};
	ll temp[2][2];
	ll ans;
	
	while(x>0){
		if(x&1){
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					temp[i][j] = result[i][0]*matrix[0][j] + result[i][1]*matrix[1][j];
				}
			}
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					result[i][j] = temp[i][j] % y;
				}
			}
		}
		
		x = x>>1;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				temp[i][j] = result[i][0]*matrix[0][j] + result[i][1]*matrix[1][j];
			}
		}
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				matrix[i][j] = temp[i][j] % y;
			}		
		}	
	}

	ans = (result[0][0]*1 + result[0][1]*0);
	return ans;
	
}

int main(){
	
	int n, m;
	while(scanf("%d%d",&n,&m)!=EOF){
		
		ll y=1;
		if(m!=0) {
			for(int i=0;i<m;i++){
				y*=2;
			};
		}
		
		if(n==0) printf("%d\n",(0%y));
		else if(n==1) printf("%d\n",(1%y));
		else printf("%lld\n", modFib(n-1, y));
	}
		
	return 0;
}
