#include<bits/stdc++.h>
using namespace std;

void simulation(){
  int ans = 0;
  int start =7;

  for(int i=1900;i<=2000;++i){
	for(int j=1;j<=12;++j){
	  // if it's 30 days....
	  if(j == 4 || j == 6 || j == 9 || j == 11){
		for(int k=1;i<=30;++k){
		  if(k == 1 && k == start) ++ans;
		  if(k == start){
			start = (k+7)%30;
			if(start == 0){
			  start = 8;
			}
		  }
		}
	  }
	  // if it's 31 days....
	  if(j== 1 || j == 3 || j == 5 || j== 7 || j == 8 || j == 10 || j == 12){
		for(int k=1;k<=31;++k){
		  if(k == 1 && k == start) ++ans;
		  if(k == start){
			start = (k+7)%31;
			if(start == 0){
			  start = 8;
			}
		  }
		}
	  }
	  // if it's damn feb...
	  if(j==2){
		// if it's a leap year...
		if(i!=1900 && i%4 == 0){
		  for(int k=1;k<=29;++k){
		  if(k == 1 && k == start) ++ans;			
			if(k == start){
			  start = (k+7)%29;
			  if(start == 0) start = 8;
			}
		  }
		}
		else{
		  for(int k=1;k<=28;++k){
		  if(k == 1 && k == start) ++ans;			
			if(k == start){
			  start = (k+7)%28;
			  if(start == 0){
				start = 8;
			  }
			}
		  }
		}
	  }
	}
  }
  cout << ans << "\n";
}

int main(){
  simulation();
  return 0;
}
