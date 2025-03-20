#include<bits/stdc++.h>
using namespace std;



string add_string(string a, string b){
  string ans = "";
  int carry = 0;
  int a_index = a.size()-1;
  
  for(int i=b.size()-1;i>=0;--i){
	int cur_a = 0;
	if(a_index >= 0) cur_a = a[a_index]-'0';
	int cur_b = b[i] - '0';
	int cur_whole_digit = cur_a+cur_b+carry;
	int cur_digit = cur_whole_digit%10;
	carry = (cur_whole_digit-cur_digit)/10;
	if(i == 0){
	  ans = to_string(cur_whole_digit)+ans;
	}
	else{
	  ans = to_string(cur_digit)+ans;
	}
	--a_index;
  }
  return ans;
}

void simulation(){
  string a1="1";
  string b1="1";
  string c = add_string(a1, b1);  
  int n = 1000;
  int i = 2;
  while(c.size() < n){
	a1 = b1;
	b1 = c;
	c = add_string(a1,b1);
	++i;
  }
  cout << i+1 << "\n";
}

int main(){
  simulation();
  // string a;string b;
  // cin >> a >> b;
  // cout << add_string(a, b) << "\n";
  return 0;
}
