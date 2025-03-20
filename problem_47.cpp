#include<bits/stdc++.h>
using namespace std;

void check2(int n, vector<int> &f){
  for(int i=2;i*i<=n, n>1;++i){
	int k = 1;
	if(n%i == 0){
	  while(n%i == 0){
		k*=i;
		n /= i;
	  }
	  f.push_back(k);
	}
  }
}

bool check(int nums){

  vector<int> fac1;
  vector<int> fac2;
  vector<int> fac3;
  vector<int> fac4;

  check2(nums, fac1);
  check2(nums+1, fac2);
  check2(nums+2, fac3);
  check2(nums+3, fac4);

  // for(auto x: fac1) cout << x << " ";
  // cout << "\n";
  // for(auto x: fac2) cout << x << " ";
  // cout << "\n";
  // for(auto x: fac3) cout << x << " ";
  // cout << "\n";
  // for(auto x: fac4) cout << x << " ";
  // cout << "\n";
  // printf("%d %d %d %d %d\n",nums, fac1.size(), fac2.size(), fac3.size(), fac4.size());
  
  if(fac1.size() == 4 && fac2.size() == 4 && fac3.size() == 4 && fac4.size() == 4){
	set<int> s;
	for(int i=0;i<4;++i){
	  s.insert(fac1[i]);
	  s.insert(fac2[i]);
	  s.insert(fac3[i]);
	  s.insert(fac4[i]);
	}
	if(s.size() == 16) return true;
	else return false;
  }
  else return false;
  return true;
}

void bruteforce(){
  int n=1000;
  while(n){
	if(check(n)){
	  printf("%d %d %d %d", n, n+1, n+2, n+3);
	  break;
	}
	++n;
  }
}

int main(){
  bruteforce();
  // int n; cin >> n;
  // check(n);
  return 0;
}
