#include<bits/stdc++.h>
using namespace std;

#define ll long long

int numberOfSolutions(int M){
  int ans = 0;
  for(int i=1;i<=M;++i){
	for(int j=i;j<=M;++j){
	  for(int k=j;k<=M;++k){
		double short_distance1 = sqrt(k*k + (i+j)*(i+j));
		if(short_distance1 == int(short_distance1)) ++ans;

		if(ans > 1000000) return -1; // here we will keep -1 as a resort that we have exceed a million...
	  }
	  if(ans > 1000000) return -1; // here we will keep -1 as a resort that we have exceed a million...
	}
	if(ans > 1000000) return -1; // here we will keep -1 as a resort that we have exceed a million...
  }
  return ans;
}

void algo(){
  int n = 500;
  while(true){
	int numOfSolutionsOfN = numberOfSolutions(n);
	if(numOfSolutionsOfN > 1000000 || numOfSolutionsOfN == -1){
	  cout << n << "\n";
	  break;
	}
	// cout << n << " -> " <<  numOfSolutionsOfN << "\n";
	n+=3;
  }
}

int main(){
  algo(); // we gonna make separate cuboid into rectangle cardboard.....flat
  return 0;
}
