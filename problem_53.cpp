#include<bits/stdc++.h>
using namespace std;

int total = 0;
vector<int> arr;
void check(int n){
  long double num = 1;
  int i=0;
  while(n>0){
	num *= n;
	if(num > 1000000){
	  if(i < arr.size()){
		while(num > 0 && i < arr.size()){
		  num /= arr[i];
		  ++i;
		}
	  }
	  else{
		++total;
		return;
	  }
	}
	--n;
  }
}

void soln(){
  int n = 10;
  while(n <= 100){
	for(int i=1;i<=n;++i){
	  for(int j=2;j<=i;++j) arr.push_back(j);
	  for(int k=2;k<=n-i;++k) arr.push_back(k);
	  check(n);
	  // cout << "term: " << i << " other stuff: ";
	  // for(auto x: arr) cout << x << " ";
	  // cout << " and total is: " << total;
	  // cout << "\n";
	  arr.clear();
	}
	++n;
  }
  cout << total << "\n";
}

int main(){
  soln();
  return 0;
}
