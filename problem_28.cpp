// upper left --> 1+6n + 4(n-1)(n)
// down left --> 1+4n + 4(n-1)(n)
// down right --> 1+ 2n + 4(n-1)(n)
// upper right ---> 1 + 8n + 4(n-1)(n)

#include<bits/stdc++.h>
using namespace std;

int LIMIT = 500; // cause we don't want '1'
long long sum = 1;
void using_newton_formula(){
  for(int i=1;i<=LIMIT;++i){
	sum += (1+6*i+4*(i-1)*(i)); // upper left side
	sum += (1+4*i+4*(i-1)*(i)); // down left side
	sum += (1+2*i+4*(i-1)*(i)); // down right side
	sum += (1+8*i+4*(i-1)*(i)); // upper right side	  
  }

  cout << sum << "\n";
}

int main(){
  using_newton_formula();
  return 0;
}
