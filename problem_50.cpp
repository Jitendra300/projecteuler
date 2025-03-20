#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool isprime(ll n){
  if(n <= 1) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(int i=3;i<=(int(sqrt(n))+1);i=i+2){
	if(n%i == 0) return false;
  }
  return true;
}

void bruteforce(){
  ll ans = 0;
  int term = 0;
  vector<ll> prev;
  prev.push_back(2);
  // vector<ll> succ;
  // filling up primes;
  int n = 3;
  while(n < 25000){
	if(isprime(n)){
	  prev.push_back(prev.back()+n);
	}
	n=n+2;
  }

  // for(auto x: prev) cout << x << "\n";
  // cout << prev.back() << "\n";

  for(int i=0;i<prev.size();++i){
	for(int j=i+1;j<prev.size();++j){
	  if(i == 0){
		if(prev[j] < 1000000 && isprime(prev[j])){
		  if(term <= (j+1)){
			term = j+1;
			ans = prev[j];
		  }
		}
	  }
	  else{
		if((prev[j]-prev[i-1] < 1000000) && isprime((prev[j]-prev[i-1]))){
		  if(term <= (j-i+1)){
			term = j+1-i;
			ans = prev[j]-prev[i-1];
		  }
		}
	  }
	}
  }
  cout << term << " " << ans << "\n";
}

int main(){
  bruteforce();
  return 0;
}
