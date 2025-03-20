#include<bits/stdc++.h>
using namespace std;

vector<long long> primes;

bool isprime(long long n){
  if(n <= 1 ) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(long long i=3;i<=(long(sqrt(n))+1);i+=2){
	if(n%i == 0) return false;
  }
  return true;
}

bool satisfies_condition(long long num){
  for(long long i=1;i*i<=num;i++){
	if(num%i == 0) {
	  if(!isprime(i + num/i)) return false;
	}
  }
  return true;
}

void bruteforce(){
  long long ans = 1;
  long long num = 2;

  while(num < 100000){
	if(isprime(num+1) && isprime(2+num/2) &&satisfies_condition(num)){
	  ans += num;
	  // cout << num << "\n";
	  // count++;
	}
	num+=4;
  }
  cout << ans << "\n";
}

void fill_primes(){
  // primes.push_back(2);
  long long n=3;
  int count=1;
  while(n < 1000000000){
	if(isprime(n)) {
	  count++;
	  cout << n << "\n";
	}
	n+=2;
  }
  cout << count << "\n";
}

int main(){
  fill_primes();
    // bruteforce();
  // int n; cin >> n;
  // satisfies_condition(n);
  return 0;
}
