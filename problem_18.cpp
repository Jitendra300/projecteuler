#include<bits/stdc++.h>
using namespace std;

// int arr[15][15] = {
//   {0,0,0,0,0,0,0,75,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
//   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
// };

vector<vector<int>> a(20);
int memo[15][15];

int dp(int index, int index_of_index){
  if(index>=15 || index_of_index>=15) return 0;
  if(memo[index][index_of_index] != 0) return memo[index][index_of_index];
  memo[index][index_of_index] = a[index][index_of_index]+max(dp(index+1, index_of_index), dp(index+1, index_of_index+1));
  return memo[index][index_of_index];
}

void brute_force(){
  int ans = 0;
  // memo[0][0] = a[0][0];
  for(int i=0;i<a[a.size()-1].size();++i){
	memo[14][i] = a[14][i];
  }
  ans = dp(0,0);
  cout << ans << "\n";
}

int main(){
  memset(memo, 0, sizeof memo);
  // taking input from file.
  for(int i=0;i<15;++i){
	for(int j = 0;j<i+1;++j) {
	  int k; cin >> k;
	  a[i].push_back(k);
	}
  }

  brute_force();
  return 0;
}
