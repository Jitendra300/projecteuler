#include<bits/stdc++.h>
using namespace std;

bool isans(int x){
  int xsum = 0;
  int num = x;
  while(num !=0){
	int remainder = (num%10);
	xsum += remainder*remainder*remainder*remainder*remainder;
	num = num/10;
  }
  return xsum == x;
}

void brute_force(){
  int sum=0;
  int n = 2;
  while(n<=295245){
	if(isans(n)){
	  sum+=n;
	  cout << n << "\n";
	}
	++n;
  }
  cout <<"\n";
  cout << sum << "\n";
}

int main(){
  brute_force();
  return 0;
}
