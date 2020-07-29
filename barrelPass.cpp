#include <stdio.h>
#define ll long long int

ll fibo(ll x){
	ll dp[x+5];
	dp[0] = 0;
	dp[1] = 1;
	if(x<=1) return x;

	for(ll i=2;i<=x;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	return dp[x];
}

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b, a%b);
}

int main(){
	
	ll t;
	scanf("%lld",&t);
	
	for(ll i=0;i<t;i++){
		ll a, b;
		scanf("%lld%lld", &a, &b);

		printf("%lld\n", fibo(gcd(a,b)));
	}
	
	return 0;
}
