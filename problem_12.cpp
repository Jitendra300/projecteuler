#include<bits/stdc++.h>
using namespace std;

bool num_of_divisors(long long number){
  map<int, int> m;
  int i = 2;
  while(number != 1){
	if(number%i == 0){
	  while((number%i == 0)){
	   if(m.count(i) == 0) m[i] = 1;
	   else m[i]++;
	   number/=i;
	  }
	}
	++i;
  }
  
  int ans=1;
  for(auto x: m){
	ans*=(x.second + 1);
  }
  return ans > 500;
}

void brute_force_it(){
  int j = 7;
  bool run = true;
  while(run){
	long long num = ((j)*(j+1))/2;
	if(num_of_divisors(num)){
	  cout << num << "\n";
	  run = false;
	  break;
	}
	++j;
  }
}

int main(){
  brute_force_it();
  return 0;
}
