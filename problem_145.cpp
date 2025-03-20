#include<bits/stdc++.h>
using namespace std;

#define ll long long 

ll reverse(ll num){
  ll ans = 0LL;
  while(num){
	ans *= 10;
	ans += num%10;
	num /= 10;
  }
  return ans;
}

bool isreversibleNumber(ll num){
  ll queryNum = num + reverse(num);
  while(queryNum){
	if((queryNum%10)%2 == 0) return false;
	queryNum /= 10;
  }
  return true;
}

void bruteforce(){
  ll n = 10LL;
  ll limit = 1000000000LL;
  // ll limit = 1000LL;
  ll ans = 0LL;
  
  while(n<limit){
	if((n%10 != 0) && isreversibleNumber(n)) ++ans;
	++n;
  }

  cout << ans << "\n";
}

int main(){
  bruteforce();
  return 0;
}
