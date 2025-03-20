#include<bits/stdc++.h>
using namespace std;

#define ll long long

set<ll> S;


/*
Note:
This program is flawed as it uses next_permutation which is lexographically working...doesn't we don't get the correct answer...
We can implement a raw permutation function instead...
 */

string returnCharString(char c, int n){
  string s = "";
  for(int i=1;i<=n;++i) s+=c;
  return s;
}

bool isprime(ll n){
  if(n<=1) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(ll i=3;i<=int(sqrt(n)+1);i+=2){
	if(n%i == 0) return false;
  }
  return true;
}

void bruteforceTwice(int a){
  int x = 0;
  string num = returnCharString('0'+a, 2);
  while(x<10){
	int y =  0;
	while(y<10){
	  num += to_string(y) + to_string(x);
	  
	  if(num[0] != '0' && num[3] != '0' && isprime(stoll(num))){
		S.insert(stoll(num));
	  }
	  
	  while(next_permutation(num.begin(), num.end())){
		if(num[0] != '0' && num[3] != '0' && isprime(stoll(num))){
		  S.insert(stoll(num));
		}

	  }
	  
	  ++y;
	  num = returnCharString('0'+a, 2);
	}
	++x;
	num = returnCharString('0'+a, 2);
  }
}

// this will work for 1, 3, 7
void bruteforceOnes(int a){
  int z = 0;

  while(z<10){
	string num = to_string(z)+returnCharString('0'+a, 3);
	
	if(num[0] != '0' && num[3] != '0' && isprime(stoll(num))){
	  S.insert(stoll(num));
	}

	while(next_permutation(num.begin(), num.end())){
	  if(num[0] != '0' && num[3] != '0' && isprime(stoll(num))){
		S.insert(stoll(num));
	  }
	  // cout << num << "\n";
	}

	++z;
	num = returnCharString('0'+a, 3);
  }
}

int main(){
  // bruteforceTwice(0);
  int n; cin >> n;
  bruteforceOnes(n);
  // bruteforceOnes(1);
  // bruteforceOnes(2);
  // bruteforceOnes(3);
  // bruteforceOnes(4);
  // bruteforceOnes(5);
  // bruteforceOnes(6);
  // bruteforceOnes(7);
  // bruteforceOnes(8);
  // bruteforceOnes(9);

  ll ans = 0LL;
  for(auto x: S){
	 ans += x;
	 cout << x << "\n";
  }

  cout << ans << "\n";
  
  return 0;
}
