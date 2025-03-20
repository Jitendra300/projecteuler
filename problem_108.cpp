#include<bits/stdc++.h>
using namespace std;

#define ll long long

int Solutions(ll n){
  int ans = 0;
  for(ll i=1;i*i<=n;++i){
	if(n%i == 0){
	  ans += 2;
	  if(n/i == i) --ans;
	}
  }
  return ans;
}

void trick(){
  long long n=304250263527210LL;
  long long LIMIT = 13082761331670030LL;
  int limitOfDivisors = 2000000;
  int count = 0;
  int K=1;
  
  // long long n=2*3*5*7*11*13;
  // long long LIMIT=2*3*5*7*11*13*17;
  // int limitOfDivisors = 2000;

  while(count <= limitOfDivisors && n*K<=LIMIT){
	count = Solutions((n*K)*(n*K));
	cout << n*K << ": " << count << "\n";
	++K;
  }
}

int main(){
  trick();
  return 0;
}
