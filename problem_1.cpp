#include<bits/stdc++.h>
using namespace std;

// classic brute_force; stupid method
void brute_force_it(){
  long long ans = 0LL;
  for(int i=1;i<1000;++i) if(i%5 == 0 || i%3 == 0) ans+= i;
  cout << ans << "\n";
}

// using formulas; kinda neat...
void using_gauss_formulas(){
  // 3+6+9+12+15+..+999 --> 3(1+2+3+...333) -> (3*333*334)/2;
  // 5+10+15+.....+199 --> 5(1+2+3+....199) -> (5*199*200)/2;
  // 15+30+45+...+990 --> 15(1+2+3+...66) -> (15*66*67)/2;
  cout << ((3*333*334)/2)+((5*199*200)/2) - ((15*67*66)/2) << "\n";
}

int main(){
  // here i can show various ways to answer a problem;
  //brute-force;
  brute_force_it();
  using_formulas();
  return 0;
}
