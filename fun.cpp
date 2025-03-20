#include<bits/stdc++.h>
using namespace std;

#define ll long long

int divisors(ll n){
  int ans = 1;
  for(long long i=2;i<=n;++i){
	if(n%i == 0){
	  int k = 0;
	  while(n%i == 0){
		n/=i;
		++k;
	  }
	  ans *= (k+1);
	}
  }
  return ans;
}

int main(){
  ll N = 13082761331670030;
  // ll limit = 614889782588491410;
  ll limit  = 9223372036854775807;
  ll k = 1;

  while(N*k <= limit){
	int ndivisors = divisors(N*k);
	if(ndivisors >= 8000000){
	  cout << N*k << "\n";
	  break;
	}
	cout << N*k << "\n";
	++k;
  }
  return 0;
}
