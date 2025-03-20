#include<bits/stdc++.h>
using namespace std;

bool ispandigital_string(int x, int y, int n){
  string num = to_string(x)+to_string(y)+to_string(n);
  string list_digit = "0000000000";
  bool is = false;
  for(int i=0;i<num.size();++i){
	if(num[i] == '0') return false;
	if(list_digit[(num[i]-'0')] != '0') return false;
	else list_digit[(num[i]-'0')] = '1';
  }
  if(list_digit == "0111111111") return true;
  return false;
}

// in my machine this runs in 58.08 millis
void brute_force_it(){
  int n = 1500;
  int sum = 0;
  set<int> s;
  for(int i=2;i<2000;++i){
	for(int j=2;j<50;++j){
	  if(ispandigital_string(i, j, i*j)){		
		s.insert(i*j);
		// cout << i << "*" << j << "=" << i*j << "\n";
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
