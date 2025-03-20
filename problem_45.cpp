#include<bits/stdc++.h>
using namespace std;

void bruteforce(){
  long double i = 150;
  bool run = true;
  while(run){
	long double hnum = i*(2*i - 1);
	if((1+sqrt(1+24*hnum))/6 == (long)((1+sqrt(1+24*hnum))/6)){
	  cout << (long long)(i*(2*i-1)) << "\n";
	  // cout << i << "\n";
	  run  = false;
	  break;
	}
	++i;
  }
}

int main(){
  bruteforce();
  return 0;
}
