#include<bits/stdc++.h>
using namespace std;

bool ispandigital(int x, int y, int n){
  int k = 0;
  map<int, bool> m;
  while(x){
	int digit = x%10;
	if((digit) == 0) return false;
	if(m.count(digit) == 0) m[digit] = true;
	else return false;
	k += (digit);
	x /= 10;
  }
  while(y){
	int digit = y%10;	
	if((digit) == 0) return false;
	if(m.count(digit) == 0) m[digit] = true;
	else return false;	
	k += (digit);
	y /= 10;
  }
  while(n){
	int digit = n%10;
	if((digit) == 0) return false;
	if(m.count(digit) == 0) m[digit] = true;
	else return false;	
	k += (digit);
	n /= 10;
  }
  return (45 == k);
}

void brute_force_it(){
  int n = 1500;
  int sum = 0;
  set<int> s;
  for(int i=2;i<9999;++i){
	for(int j=2;j<99;++j){
	  if(ispandigital(i, j, i*j)){
		s.insert(i*j);
	  }
	}
  }
  for(auto x: s){
	sum +=x;
  }
  cout << sum << "\n";
}

int main(){
  brute_force_it();
  return 0;
}
