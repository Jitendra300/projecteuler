#include<bits/stdc++.h>
using namespace std;



bool isprime(int n){
  if(n <= 1) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  else{
	for(int i=3;i<=(int(sqrt(n))+1);i=i+2){
	  if(n%i == 0) return false;
	}
  }
  return true;
}


bool iscircularprime(int n){
  // if it contains an even number then it's not a circular prime;
  int num = n;
  int no_digits = 0;
  while(num){
	if((num%10)%2 == 0) return false;
	num /= 10;
	++no_digits;
  }
  int initial_num = n;
  int fake_digits = no_digits;

  while(no_digits){
	if(!isprime(initial_num)) return false;
	initial_num += (initial_num%10)*pow(10, fake_digits);
	initial_num = (initial_num-(initial_num%10))/10;

	// it should be of form 6k+1 nor 6k-1, then only it can be prime [for primes greater than 2 and 3]
	if(!(((initial_num-1)%6 == 0) || ((initial_num+1)%6) == 0)) return false;
	
	--no_digits;
  }
  return true;
}

void brute_force_it(){
  int ans = 2;
  int n = 6;
  while(n<1000000){
	if(iscircularprime(n-1)){
	  // cout << n << "\n";
	  ++ans;
	}
	if(iscircularprime(n+1)){
	  // cout << n << "\n";
	  ++ans;
	}
	n=n+6;
  }
  cout << ans << "\n";
}

int main(){
  brute_force_it();
  return 0;
}
