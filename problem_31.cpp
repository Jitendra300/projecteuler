#include<bits/stdc++.h>
using namespace std;

vector<int> coins = {1,2,5,10,20,50,100,200};
vector<int> ans(201,0);

void dp(){
  ans[0] = 1;
  for(int i=1;i<=200;++i){	    
	for(auto x: coins){
	  if(i-x >= 0){
		ans[i] += ans[i-x];
	  }
	}
  }
  cout << ans[200]<<"\n";
}

int main(){
  dp();
  return 0;
}
