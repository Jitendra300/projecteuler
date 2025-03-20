#include<bits/stdc++.h>
using namespace std;

int isamicable(int x){
  int x_sum = 0;
  // find divisors of x;
  for(int i=1;i<(int(sqrt(x))+1);++i){
	if(x%i == 0 && i*i != x){
	  if(i!=1)
		x_sum += (i+(x/i));
	  else
		x_sum +=i;
	}
	if(x%i == 0 && i*i == x){
	  x_sum += (i);
	}
  }

  int y_sum = 0;
  for(int i=1;i<(int(sqrt(x_sum))+1);++i){
	if(x_sum%i == 0 && i*i != x_sum){
	  if(i!=1)
		y_sum += (i+(x_sum/i));
	  else
		y_sum += i;
	}
	if(x_sum%i && i*i == x_sum){
	  x_sum+=(i);
	}
  }
  return (x == y_sum && x_sum != y_sum);
}

void brute_force_it(){
  int sums = 0;
  for(int i=1;i<10000;++i){
	if(isamicable(i)){
	  sums+=i;
	}
  }
  cout << sums << "\n";
}

int main(){
  brute_force_it();
  return 0;
}
