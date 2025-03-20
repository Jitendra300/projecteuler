#include<bits/stdc++.h>
using namespace std;

int most_primes = 0;
int ans = 0;

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

void brute_force(){
  for(int a=-9999;a<10000;++a){
	for(int b=2;b<=10000;++b){
	  if(!isprime(b)) continue;
	  int cur_prime_count = 0;
	  int n = 0;
	  bool run = true;
	  while(run){
		if(isprime((n*n+a*n+b))){
		  ++cur_prime_count;
		  ++n;
		}
		else{
		  if(most_primes <= cur_prime_count){
			most_primes = cur_prime_count;
			ans = a*b;
			cout << a << " " << b << "\n";
		  }
		  run = false;
		  break;
		}
		++n;
	  }
	}
  }
  cout << ans << "\n";
}

int main(){
  brute_force();
  return 0;
}
