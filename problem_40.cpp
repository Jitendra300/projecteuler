#include<bits/stdc++.h>
using namespace std;

int check[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

void brute_force(){
  int ans = 1;
  string num = "";
  int n = 1;
  int counter = 0;
  while(num.size() <= 1000000){
	num = num + to_string(n);
	// if(n == check[counter]){
	// cout << n << "  ";
	++n;
  }

  ans = (num[0]-'0');
  ans *= (num[9]-'0');
  ans *= (num[99]-'0');
  ans *= (num[999]-'0');
  ans *= (num[9999]-'0');
  ans *= (num[99999]-'0');
  ans *= (num[999999]-'0');
  
  cout << ans << "\n";
}

void clever_trick(){
  int ans = 1;
  while(n <= 1000000){
  }
}

int main(){
  brute_force();
  clever_trick();
  return 0;
}
