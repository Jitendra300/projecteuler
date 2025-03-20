#include<bits/stdc++.h>
using namespace std;

void operation(){
  int k = 90; // this comes from a mathematical constraits
  int soln = 0;
  while(k<100){
	string ans = to_string(k);
	for(int i=2;i<=99;++i){
	  int n = ans.size()-1;
	  string ans2 = "";
	  int carry = 0;
	  for(int j=n;j>=0;--j){
		int digit = (ans[j]-'0');
		int multiplier = digit*k + carry;
		int curr_digit = multiplier%10;
		carry = (multiplier-curr_digit)/10;
		if(j>0) ans2 = to_string(curr_digit) + ans2;
		else ans2 = to_string(multiplier) + ans2;

		int cursoln = 0;
		for(int i=0;i<ans2.size();++i) cursoln += (ans2[i]-'0');
		soln = max(cursoln, soln);
	  }
	  ans = ans2;
	}
	++k;
  }
  cout << soln << "\n";
}

int main(){
  operation();
  return 0;
}
