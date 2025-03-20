#include<bits/stdc++.h>
using namespace std;

bool isRightTriangle(double a, double b, double c){
  return (a == (b + c)) || (b == (a + c)) || (c == (a + b));
}

void bruteforce(){
  int LIMIT = 50;
  int ans = 0;

  for(int x1=0;x1<=LIMIT;++x1){
	for(int y1=0;y1<=LIMIT;++y1){
	  for(int x2=0;x2<=LIMIT;++x2){
		for(int y2=0;y2<=LIMIT;++y2){
		  if(x1 == x2 && y1 == y2 && y1 == x2) continue;
		  if((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0)) continue;
		  if(x1 == x2 && y1 == y2) continue;
		  int AB = (x1*x1 + y1*y1);
		  int AC = (x2*x2 + y2*y2);
		  int BC = ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		  if(isRightTriangle(AB, AC, BC)){
			 ++ans;
		  }
		}
	  }
	}
  }
  
  cout << ans/2 << "\n";
}

int main(){
  bruteforce();
  return 0;
}
