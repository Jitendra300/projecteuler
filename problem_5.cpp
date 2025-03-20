#include<bits/stdc++.h>
using namespace std;

// function to find whether the given number is prime or not
bool isprime(int n){
  if(n <= 1) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  else{
	for(int i=3;i<=(sqrt(n)+1);i=i+2){
	  if(n%i == 0) return false;
	}
  }
  return true;
}

// brute force with tweaks ;
void bruce_force_it(){
  int ans = 1;
  int n = 20;
  for(int i=2;i<=20;++i){
	if(isprime(i)){
	  int k = 1;
	  while((n/pow(i, k)) >= 1){
		ans *= i;
		++k;
	  }
	}
  }
  cout << ans << "\n";
}

int main(){
  bruce_force_it();
  return 0;
}
