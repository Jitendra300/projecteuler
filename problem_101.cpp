#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll generateOurSequence(int n){
  ll ans = 0;
  for(int i=0;i<=10;++i){
	ans = ans + pow(-1, i)*pow(n, i);
  }
  return ans;
}

int main(){
  int n; cin >> n;
  cout << generateOurSequence(n) << "\n";
  return 0;
}
