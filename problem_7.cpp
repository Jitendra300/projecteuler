#include<bits/stdc++.h>
using namespace std;

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

bool isAP(int a, int b, int c){
  return ((a+b) == 2*b);
}

void brute_force_it(){
  int i =0;
  int n = 1;
  while(i != 10001){
	++n;	
	if(isprime(n)) ++i;
  }
  cout << n << "\n";
}

int main(){
  brute_force_it();
  return 0;
}
