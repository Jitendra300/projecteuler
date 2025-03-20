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

int reverse_num(int n){
  int k=0;
  while(n){
	k *= 10;	
	k+=(n%10);
	n/=10;
  }
  return k;
}

bool left_truncatble(int n){
  while(n){
	if(!isprime(n)) return false;
	n = reverse_num(n);
	n = (n-(n%10))/10;
	n = reverse_num(n);
  }
  return true;
}

bool right_truncatble(int n){
  int num = n;
  while(n){
	if(!isprime(n)) return false;
	n = (n-(n%10))/10;
  }
  return true;
}

bool istruncatable(int n){
  return (right_truncatble(n) && left_truncatble(n));
}

void bruteforce(){
  int sum = 0;
  int ith = 0;
  int n = 11;
  while(n){
	if(istruncatable(n)){
	  // cout << n << "\n";
	  sum += n;
	  ++ith;
	  if(ith == 11) break;
	}
	n += 2;
  }
  cout << sum << "\n";
}

int main(){
  bruteforce();
  return 0;
}
