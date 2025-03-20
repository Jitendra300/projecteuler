#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll powerOfk(ll n, int k){
  ll ans = 1LL;
  for(int i=1;i<=k;++i) ans *= n;
  return ans;
}

bool checkCondition(ll num){
  ll copyNum = num;
  ll sumOfdigit = 0;
  while(copyNum){
	sumOfdigit += copyNum%10;
	copyNum /= 10;
  }
  if(sumOfdigit == 1) return false;
  if(num%sumOfdigit != 0) return false;

  
  int k = 1;
  while(true){
	ll powerSumDigit = powerOfk(sumOfdigit, k);
	if(num == powerSumDigit) return true;
	else if(num < powerSumDigit) return false;
	++k;
  }
  return false;
}

void specialCase(){
  set<ll> arr;
  int N = 2;
  long double SuperConstant = 18.362829736; // this is log10(2^61 - 1); close real value is ---->18.362829735502853
  while(arr.size() < 33){
	int MaxexponentLimit = SuperConstant/log10(N);
	int currentexponent = 1;
	while(currentexponent<=MaxexponentLimit){
	  ll num = powerOfk(N, currentexponent);
	  
	  if(num < 10){
		++currentexponent;
		continue;
	  }
	  
	  if(checkCondition(num)){
		arr.insert(num);
	  }
	  ++currentexponent;
	}
	++N;
  }
  vector<ll> ans;
  for(auto x: arr) ans.push_back(x);
  cout << ans[29] << "\n";
}

int main(){
  specialCase();
  return 0;
}
