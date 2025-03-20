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

void smart_trick(){
  int n = 1;
  int no_of_primes = 0;
  int no_of_numbers = 1;
  double percentage = 0;
  
  while(true)
	{
	  int curr_num = 4*n*n + 1;
	  if(isprime(curr_num+2*n)) ++no_of_primes;
	  if(isprime(curr_num-2*n)) ++no_of_primes;
	  if(isprime(curr_num+4*n)) ++no_of_primes;
	  if(isprime(curr_num)) ++no_of_primes;

	  no_of_numbers += 4;
	  percentage = 100 * ((double)(no_of_primes))/((double)(no_of_numbers));
	  if(percentage<10)
		{
		  cout << 2*n + 1 << "\n";
		  break;
		}
	  ++n;
	}
}

int main(){
  smart_trick();
  return 0;
}
