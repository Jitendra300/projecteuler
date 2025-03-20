#include<bits/stdc++.h>
using namespace std;

bool ispalindrome10(int n){
  int num =n;
  int reverse  = 0;
  int k = 0;
  while(num){
	reverse += (num%10);
	reverse *= 10;	
	num /= 10;
	++k;
  }
  reverse/=10;
  return (reverse == n);
}

bool ispalindrome2(int n){
  vector<int> representation;
  int num = n;
  while(num){
	representation.push_back(num%2);
	num /= 2;
  }
  int size_ = representation.size();
  for(int i=0;i<size_;++i){
	if(representation[i] != representation[size_-i-1]) return false;
  }
  return true;
}

void brute_force(){
  int ans = 0;
  int n = 0;
  while(n < 1000000){
	if(ispalindrome10(n) && ispalindrome2(n)){
	  // cout << n << "\n";
	  ans+=n;
	}
	++n;
  }
  cout << ans << "\n";
}

int main(){
  brute_force();
  return 0;
}
