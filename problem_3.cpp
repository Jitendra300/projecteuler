#include<bits/stdc++.h>
using namespace std;

//classic brute force; stupid method
void brute_force_it(){
  long long n = 600851475143;
  int i = 1;
  int ans = 0;
  while(n!=1){
	if(n%i == 0){
	  n /= i;
	  ans = max(ans, i);
	} 
	++i;
  }
  cout << ans << "\n";
}

int main(){
  brute_force_it();
  return 0;
}
