#include<stdio.h>
#define ll long long int
int main(){
	
	int n;
	int a, b, k;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		
		ll dee = 0, qee = 0;
		
		scanf("%d%d%d",&a,&b,&k);
		
		while(a%k!=0){
			a++;
		}
		
		for(int i=a;i<=b;i+=k){
			for(int j=1;j*j<=i;j++){
				if(i%j==0){
					if(j*j==i){
						dee++;
						qee+=j;
					} else {
						dee+=2;
						qee = qee + j + i/j;
					}
				}
			}
		}
		
		printf("%lld %lld\n", dee, qee);
		
	}
	
	return 0;
}
