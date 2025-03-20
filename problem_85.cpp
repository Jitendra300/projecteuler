#include<bits/stdc++.h>
using namespace std;

int gaussformula(int n){
  return n*(n+1)/2;
}

void classicformula(){
  int AIM = 2000000;
  int limit = 1000;
  int area = 0;
  int best = INT_MAX;
  // int dimensionx = 0;
  // int dimensiony = 0;
  // int rectangles = 0;
  for(int i=1;i<limit;++i){
	for(int j=1;j<limit;++j){
	  int curr_rectangles = gaussformula(i)*gaussformula(j);
	  if(abs(AIM-curr_rectangles) <= best){
		best = abs(AIM-curr_rectangles);
		area = i*j;
		// rectangles = curr_rectangles;
		// dimensionx = i;
		// dimensiony = j;
	  }
	}
  }
  cout << area << "\n";
  // cout << dimensionx << " " << dimensiony << "\n";
  // cout << rectangles << "\n";
}

int main(){
  classicformula();
  return 0;
}
