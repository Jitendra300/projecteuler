#include<bits/stdc++.h>
using namespace std;

bool ispytha(int a, int b, int c){
  if((a*a + b*b) == c*c) return true;
  if((a*a + c*c) == b*b) return true;
  if((c*c + b*b) == a*a) return true;
  return false;
}

void brute_force(){
  int ans = 0;
  int n = 3;
  int real_n = 0;
  while(n < 1000){
	int count = 0;
	for(int i=3;i<n;++i){
	  for(int j=i+1;j<n;++j){
		for(int k=j+1;k<n;++k){
		  if(((i+j+k) == n) && ispytha(i, j, k)){
			count++;
		  }
		}
	  }
	}
	if(ans < count){
	  ans = count;
	  real_n = n;
	  cout << real_n << "  " << ans << "\n";
	}
	++n;
  }
  cout << ans << "\n";
}

int main(){
  brute_force();
  return 0;
}
