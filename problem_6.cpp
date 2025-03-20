#include<bits/stdc++.h>
using namespace std;

void brute_force_it(){
  int n1_term = ((100)*(101)*(201)/6); // 1^2 + 2^2 + 3^2 +... + 100^2;
  int n2_term = ((100*101)/2)*((100*101)/2);  // (1+2+3+....+100)^2
  cout << n2_term-n1_term << "\n";
}

int main(){
  brute_force_it();
  return 0;
}
