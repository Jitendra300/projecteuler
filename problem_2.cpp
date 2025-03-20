#include<bits/stdc++.h>
using namespace std;

//classic brute force; stupid method
void brute_force_it(){
  long long ans = 0LL;
  int a=1, b=2, c=(a+b);
  while(a < 4000000){
	if(!(a&1))
	  ans+=a;
	a = b;
	b = c;
	c = (a+b);
  }
  cout << ans << "\n";
}

int main(){
  brute_force_it();
  return 0;
}
