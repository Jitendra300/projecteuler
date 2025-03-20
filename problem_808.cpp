#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll ispalindrome(ll n){
  ll num2 = 0;
  while(n){
	num2 *= 10;
	num2 += n%10;
	n/=10;
  }
  return num2;
}

bool isprime(ll n){
  if(n%2 == 0) return false;
  for(ll i=3;i<=long(sqrt(n)+1);i+=2){
	if(n%i == 0) return false;
  }
  return true;
}


bool satisfies(ll n){
  ll palindrome = ispalindrome(n);
  if(palindrome == n) return false;
  if(int(sqrt(palindrome)) != sqrt(palindrome)) return false;
  if(!isprime(sqrt(palindrome))) return false;
  return true;
}


void bruteforce(){
  vector<ll> primes;
  int LIMIT = 3000000; // no of primes....
  ll n = 5;
  while(primes.size() <= LIMIT){
	if(isprime(n)) primes.push_back(n);
	n+=2;
  }

  int NUM = 0; // we will stop the loop if we get over 50....
  int i = 0;
  ll ans = 0LL;
  
  while(NUM < 50 && i<primes.size()){
	int integer = primes[i]*primes[i];
	if(satisfies(integer)){
	  cout << integer << "\n";
	  ans += integer;
	  NUM++;
	}
	++i;
  }

  cout << ans << "\n";
}

int main(){
  bruteforce();
  return 0;
}
