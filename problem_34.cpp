#include<bits/stdc++.h>
using namespace std;

int digit_factorial[10] = {1,1, 2,6,24,120,720, 5040, 40320,362880};

void brute_force(){
  int s = 0;
  for(int i=11;i<100000;++i){
	int isum = 0;
	int num = i;
	while(num){
	  int digit = num%10;
	  isum += digit_factorial[digit];
	  num/=10;
	}
	if(isum == i){
	  s+=i;
	  cout << i << "\n";
	}
  }
  cout << s << "\n";
}

int main(){
  brute_force();
  return 0;
}
