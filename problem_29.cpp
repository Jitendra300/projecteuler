#include<bits/stdc++.h>
using namespace std;

int total = 0; 

/*
Here we note that we only get replicate of numbers who r power of only one number ...for example 4, 25, 36, ....
thus we only have to make sure of this...
 */

int nums[101] = {-1};
vector<int> primes;

bool isprime(int n){
  if(n <= 1) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  else{
	for(int i=3;i<=int(sqrt(n))+1;i=i+2){
	  if(n%i == 0) return false;
	}
  }
  primes.push_back(n);
  return true;
}

int is_pair_number(int n){
  int num = n;
  for(int i=1;i<=(int(sqrt(num))+1);++i){
	if(num%i == 0 && i*i == n){
	  nums[n] = i;
	  return i;
	}
  }
  return -1;
}

int check_continuos_primes(int n){
  bool only_one = true;
  int divisible_prime = 2;
  for(auto x: primes){
	if(n%x == 0 && only_one == true){
	  only_one = false;
	  divisible_prime = x;
	}
	else if(n%x == 0 && only_one == false) break;
  }
  if(!only_one) return -1;
  return divisible_prime;
}

void check_operation(int n){
  if(isprime(n)) nums[n] = 0;
  else if(is_pair_number(n) != -1) nums[n] = is_pair_number(n); // here pair_number is the number which is twice in the number like 36 = 6*6 or 4=2*2;
  else if(check_continuos_primes(n) != -1) nums[n] =  check_continuos_primes(n);
  else nums[n] = 0;
}

// void calc_ans(int n){
//   if(nums[n] == 0) total += 99;
  
// }

void solve_using_math(){
  int n=2;
  while(n<=50){
	check_operation(n);
	// calc_ans(n);
	++n;
  }
  for(int i=2;i<=50;++i){
	cout << i << "->" << nums[i] << "\n";
  }
  cout << "\n";
}

int main(){
  solve_using_math();
  return 0;
}
