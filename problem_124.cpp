#include<bits/stdc++.h>
using namespace std;

int radical(int n){
  int ans = 1;
  int k = 2;
  while(n!=1){
	if(n%k == 0){
	  ans *= k;
	  n/=k;
	  while(n%k == 0) n/=k;
	}
	++k;
  }
  return ans;
}

void bruteforce(){
  int n=2;
  int limit = 100000;

  vector<pair<int, int>> arr;
  arr.push_back({1,1});
  while(n<=limit){
	arr.push_back({radical(n), n});
	++n;
  }
  sort(arr.begin(), arr.end());
  cout << arr[9999].second << "\n";
}

int main(){
  bruteforce();
  return 0;
}
