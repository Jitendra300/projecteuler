#include<bits/stdc++.h>
using namespace std;

void trick_probably(){
  long long ans = 0;
  for(int i=1;i<=1000;++i){
	long long term = 1;
	for(int j=1;j<=i;++j){
	  term = ((term%10000000000)*(i%10000000000))%10000000000;
	}
	ans = (ans+(term%10000000000))%10000000000;
  }
  cout << ans << "\n";
}

int main(){
  trick_probably();
  return 0;
}
