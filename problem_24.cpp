#include<bits/stdc++.h>
using namespace std;

vector<int> a = {0,1,2,3,4,5,6,7,8,9};

void brute_force(){
  int i=0;
  do{
	if(i == 999999){
	  for(auto x: a) cout << x;
	  cout << "\n";
	  break;
	}
	++i;
  }while(next_permutation(a.begin(), a.end()));
}

int main(){
  brute_force();
  return 0;
}
