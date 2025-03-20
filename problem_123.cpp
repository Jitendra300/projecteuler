#include<bits/stdc++.h>
using namespace std;

#define ll long long 

bool isprime(ll n){
  for(ll i=3;i<=long(sqrt(n)+1);i+=2){
	if(n%i == 0) return false;
  }
  return true;
}

void algo(){
  ll condition = 10e9;
  ll n = 3;
  int nth = 1;
  ll ans = 0;
  while(true){
	if(isprime(n)){
	  ++nth;
	  if(nth%2 == 1)
		ans = (2*n*nth)%(n*n);
	  else
		ans = 0LL;
	  if(ans > condition){
		cout << nth << "\n";
		break;
	  }
	}
	n+=2;
  }
}

int main(){
  algo();
  return 0;
}
