#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> a(100);
int memo[100][100];

int dp(int index, int index_of_index){
  if(index>=100 || index_of_index>=100) return 0;
  if(memo[index][index_of_index] != 0) return memo[index][index_of_index];
  memo[index][index_of_index] = a[index][index_of_index]+max(dp(index+1, index_of_index), dp(index+1, index_of_index+1));
  return memo[index][index_of_index];
}

void soln(){
  int ans = 0;
  for(int i=0;i<a[a.size()-1].size();++i){
	memo[99][i] = a[99][i];
  }
  ans  = dp(0, 0);
  cout << ans << "\n";
}
int main(){
  // taking input form file 0067_triangle.txt
  memset(memo, 0, sizeof memo);

  for(int i=0;i<100;++i){
	for(int j=0;j<i+1;++j){
	  int k; cin >> k;
	  a[i].push_back(k);
	}
  }
  // solution 
  soln();
  return 0;
}
