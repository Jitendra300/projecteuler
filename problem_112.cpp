#include<bits/stdc++.h>
using namespace std;

bool isBouncy(int n){
  vector<int> arr;
  while(n){
	arr.push_back(n%10);
	n/=10;
  }
  reverse(arr.begin(), arr.end()); //reversing the array;

  // checking for increasing number;
  bool is_increasing = true;
  bool is_decreasing = true;

  for(int i=0;i<arr.size()-1;++i){
	if(arr[i] > arr[i+1]){
	  is_increasing = false;
	}
	if(arr[i] < arr[i+1]){
	  is_decreasing = false;
	}
  }
  if(is_increasing) return false;
  if(is_decreasing) return false;

  return true;
}

void bruteforce(){
  int num = 21780;
  int bouncy = 19602;
  long double percentage = 90;
  bool run = true;
  while(run){
	if(isBouncy(num)){
	  bouncy += 1;
	  percentage = (1.0*bouncy)/num * 100.0;

	  if(percentage == 99){
		cout << num << "\n";
		run = false;
		break;
	  }
	}
	++num;
  }
}

int main(){
  bruteforce();
  // int n; cin >> n;
  // cout << isBouncy(n) << "\n";
  return 0;
}
