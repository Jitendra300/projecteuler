#include<bits/stdc++.h>
using namespace std;


bool ispalindrome(int n){
  int x= 0;
  int num = n;
  while(num){
	x = (x*10) + (num%10);
	num /= 10;
  }
  return x == n;
}

// brute_force_very stupid method;
void brute_force_it(){
  int ans = 0;
  for(int i=100;i<=999;++i){
	for(int j=100;j<=999;++j){
	  if(ispalindrome(i*j)){
		ans = max(ans, i*j);
	  }
	}
  }
  cout << ans << "\n";
}

// using more efficient method by knowing the problem details.

void more_smarter(){
  int ans = 0;  
  for(int i=100;i<=999;++i){
	for(int j=110;j<=990;j+=11){
	  if(ispalindrome(i*j)){
		ans = max(ans, i*j);
	  }
	}
  }
  cout << ans << "\n";
}

int main(){
  brute_force_it();
  more_smarter();
  return 0;
}
