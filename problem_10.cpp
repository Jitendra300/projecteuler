#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// function to find whether the given number is prime or not
bool isprime(int n){
  if(n <= 1) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  else{
	for(int i=3;i<=(sqrt(n)+1);i=i+2){
	  if(n%i == 0) return false;
	}
  }
  return true;
}

void brute_force_it(){
  long long ans = 2;
  for(int i=3;i<2000000;i+=2){
	if(isprime(i)){
	  ans+= i;
	}
  }
  cout << ans << "\n";
}


void sieve_of_eratosthenes(){
  ll n = 2000000LL; // our limit
  ll ans = 0LL;
  vector<bool>  is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for(ll i=2;i<n;++i){
	if(is_prime[i]){
	  ans += i;
	  for(ll j=i*i;j<n;j+=i){
		is_prime[j] = false;
	  }
	}
  }
  cout << ans << "\n";
}

int main(){
  // brute_force_it();
  sieve_of_eratosthenes();
  return 0;
}
