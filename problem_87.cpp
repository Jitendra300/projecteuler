#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isprime(ll n){
  if(n <= 1 ) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(ll i=3;i<=(long(sqrt(n))+1);i+=2){
	if(n%i == 0) return false;
  }
  return true;
}

void bruteforce(){
  vector<ll> primesSquared;
  vector<ll> primesCubed;
  vector<ll> primesQuadrapled;  
  primesSquared.push_back(4); // 2*2
  primesCubed.push_back(8); // 2*2*2
  primesQuadrapled.push_back(16); // 2*2*2*2
  ll n = 3;
  int sizeOfSquared = 7071;
  int sizeOfCube = 368;
  int sizeOfQuadrapled = 84;

  while(primesSquared.size() < sizeOfSquared){
	if(isprime(n)){
	  primesSquared.push_back(n*n);
	  if(primesCubed.size() < sizeOfCube);
		primesCubed.push_back(n*n*n);
	  if(primesQuadrapled.size() < sizeOfQuadrapled);
		primesQuadrapled.push_back(n*n*n*n);	  
	}
	n+=2;
  }

  unordered_set<ll> s;
  ll limited = 50000000;

  for(int i=0;i<sizeOfSquared;++i){
	for(int j=0;j<sizeOfCube;++j){
	  if(primesSquared[i]+primesCubed[j] >= limited) break;
	  for(int k=0;k<sizeOfQuadrapled;++k){
		ll num = primesSquared[i]+primesCubed[j]+primesQuadrapled[k];
		if(num < limited) s.insert(num);
		else break;
	  }
	}
  }
  cout << s.size() << "\n";
}

int main(){
  bruteforce();
  return 0;
}
