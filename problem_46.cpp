#include<bits/stdc++.h>
using namespace std;

bool isprime(long long n){
  if(n <= 1) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;

  for(long long i=3;i<=(int(sqrt(n))+1);i=i+2){
	if(n%i == 0) return false;
  }
  
  return true;
}


void brute_force(){
  bool run = true;
  long long n=35;
  while(run){
	long long term = 1;
	while(!isprime(n-(2*term*term))){
	  term++;	  
	  if(n<(2*term*term)){
		cout << n <<  "\n ";
		run = false;
		break;
	  }
	}
	n+=2;
	while(isprime(n)) n+=2;
  }
}

int main(){
  brute_force();
  return 0;
}
