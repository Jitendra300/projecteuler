#include<bits/stdc++.h>
using namespace std;

int n = 21;
long long grid[21][21];

void dp_solution(){
  for(int i=0;i<n;++i) grid[i][0] = 1;
  for(int i=0;i<n;++i) grid[0][i] = 1;

  for(int i=1;i<n;++i){
	for(int j=1;j<n;++j){
	  grid[i][j] = grid[i-1][j] + grid[i][j-1];
	}
  }

  for(int i=0;i<n;++i){
	for(int j=0;j<n;++j){
	  cout << grid[i][j] << " ";
	}
	cout << "\n";
  }
  cout << "\n";
  
  cout << grid[n-1][n-1] << "\n";
}

int main(){
  dp_solution();
  return 0;
}
