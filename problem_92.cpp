#include<bits/stdc++.h>
using namespace std;

void soln(){
  long long n=2;
  int total = 0;
  while(n < 100){
	long long num = n;
	while(num != 1){
	  if(num == 89){
		++total;
		break;
	  }
	  long long k=num;
	  long long l = 0;
	  while(k){
		// l *= 10;
		l += (k%10)*(k%10);
		k/=10;
	  }
	  // cout << l << " ";
	  num = l;
	}
	// cout << "\n";
	++n;
	cout << n << " total: " << total << "\n";
  }
  cout << total << "\n";
}

int main(){
  soln();
  return 0;
}
