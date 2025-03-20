#include<bits/stdc++.h>
using namespace std;

string ans = "2";

void operation(){
  int k; cin >> k;
  for(int i=2;i<=k;++i){
	int n = ans.size()-1;
	string ans2 = "";
	int carry = 0;	
	for(int j=n;j>=0;--j){
	  int digit = (ans[j]-'0');
	  int multiplier = digit*2 + carry;
	  int curr_digit = multiplier%10;
	  carry = (multiplier-curr_digit)/10;
	  if(j>0)
		ans2 = to_string(curr_digit) + ans2;
	  else
		ans2 = to_string(multiplier) + ans2;
	}
	ans = ans2;
  }
  int digit = 0;
  for(int i=0;i<ans.size();++i){
	digit += ans[i] - '0';
  }
  cout << digit << "\n";
}

int main(){
  operation();
  return 0;
}
