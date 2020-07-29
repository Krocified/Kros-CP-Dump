#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h> 
#include<vector>
#define ll long long int
using namespace std; 
//THANK YOU GEEKSFORGEEKS FOR THE SEGMENTED SIEVE
ll primes[100005];

void simpleSieve(ll limit, vector<ll>& prime) 
{ 
	bool mark[limit + 1]; 
	memset(mark, false, sizeof(mark)); 

	for (ll i = 2; i <= limit; ++i) { 
		if (mark[i] == false) { 
			prime.push_back(i); 
			for (ll j = i; j <= limit; j += i) 
				mark[j] = true; 
		} 
	} 
} 

void primesInRange(ll low, ll high) 
{ 
	ll limit = floor(sqrt(high)) + 1; 
	vector<ll> prime; 
	simpleSieve(limit, prime); 

	ll n = high - low + 1; 

	bool mark[n + 1]; 
	memset(mark, false, sizeof(mark)); 
 
	for (ll i = 0; i < prime.size(); i++) { 
		ll loLim = floor(low / prime[i]) * prime[i]; 
		if (loLim < low) 
			loLim += prime[i]; 
		if(loLim==prime[i]) 
			loLim += prime[i]; 
		for (ll j = loLim; j <= high; j += prime[i]) 
			mark[j - low] = true; 
	} 
	
	int primeCt = 0;
	for (ll i = low; i <= high; i++) 
		if (!mark[i - low]) {
			primes[primeCt] = i;
			primeCt++;
		}
		
	ll c1, c2, d1, d2;
	int close = 1000001;
	int dist = 0;
	
	for(ll i = 0; i< primeCt-1; i++){
		ll curr = primes[i];
		ll next = primes[i+1];
		
		if(next-curr<close){
			close = next-curr;
			c1 = curr;
			c2 = next;
		}
		if(next-curr>dist){
			dist = next-curr;
			d1 = curr;
			d2 = next;
		}
	}
	
	if (close == 1000001 && dist == 0){
		puts("There are no adjacent primes.");
	} else {
		printf("%lld,%lld are closest, %lld,%lld are most distant.\n",c1, c2, d1, d2);
	}
	
} 

int main() { 
	
	ll low, high;
	while(scanf("%lld%lld",&low,&high)!=EOF){
		if(low<2) low=2;
		primesInRange(low, high); 
	}
	return 0; 
} 

