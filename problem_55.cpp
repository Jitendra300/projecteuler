#include<bits/stdc++.h>
using namespace std;

string add_strings(string s){
  string s2 = "";
  for(int i=s.size()-1;i>=0;--i) s2 += s[i];

  string new_string = "";
  int carry = 0;
  for(int i=s.size()-1;i>=0;--i){
	int curr_sum = (s[i]-'0') + (s2[i]-'0')+carry;
	int digit = curr_sum%10;
	carry = (curr_sum-digit)/10;
	if(i == 0){
	  new_string =to_string(curr_sum) + new_string;
	}
	else{
	  new_string = to_string(digit) + new_string;
	}
  }
  return new_string;
}

bool ispalindome(string s){
  int n = s.size();
  for(int i=0;i<n/2;++i){
	if(s[i] != s[n-i-1]) return  false;
  }
  return true;
}

void bruteforce(){
  int n=10;
  int count = 0;  
  while(n < 10000){
	string num = to_string(n);
	bool found = true;
	for(int i=1;i<50;++i){
	  if(i > 1 && ispalindome(num)){
		found = false;
		break;
	  }
	  num = add_strings(num);
	  // cout << num << "\n";
	}
	if(found) ++count;
	++n;
  }
  cout << count << "\n";
}

int main(){
  bruteforce();
  // string s; cin >> s;
  // cout << add_strings(s) << "\n";
  return 0;
}
