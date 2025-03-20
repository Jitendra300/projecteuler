#include<bits/stdc++.h>
using namespace std;

#define ll long long

set<ll> S;

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

void bruteforceFor0(int a){
  int x = 0;
  string num = returnCharString('0'+a, 3);
  while(x<10){
	int y =  0;
	while(y<10){
	  num += to_string(y) + to_string(x);
	  while(next_permutation(num.begin(), num.end())){
		if(num[0] != '0' && num[9] != '0' && isprime(stoll(num))){
		  S.insert(stoll(num));
		}
	  }
	  ++y;
	  num = returnCharString('0'+a, 8);
	}
	++x;
	num = returnCharString('0'+a, 8);
  }
}

// this will work for 1, 3, 7
void bruteforceFor1_3_7(int a){
  int z = 0;
  while(z<10){
	string num = returnCharString('0'+a, 9);
	num += to_string(z);
	while(next_permutation(num.begin(), num.end())){
	  if(num[0] != '0' && num[9] != '0' && isprime(stoll(num))){
		S.insert(stoll(num));
	  }
	}
	++z;
	num = returnCharString('0'+a, 9);
  }
}

int main(){
  bruteforceFor0(0);
  bruteforceFor1_3_7(1);
  bruteforceFor0(2);
  bruteforceFor1_3_7(3);
  bruteforceFor0(4);
  bruteforceFor0(5);
  bruteforceFor0(6);
  bruteforceFor1_3_7(7);
  bruteforceFor0(8);
  bruteforceFor0(9);

  ll ans = 0LL;
  for(auto x: S){
	 ans += x;
  }

  cout << ans << "\n";
  
  return 0;
}
