#include<bits/stdc++.h>
using namespace std;

// this problem asks us for n where n = a+b+c where c^2 = a^2 + b^2 and c,b,a are all unique.
#define ll long long

bool satisfyCondition(int n, int m){
  if(__gcd(n, m) != 1) return false;
  if((m+n)%2 == 0) return false;
  if(__gcd(2*m*n, m*m-n*n) != 1) return false;
  if(__gcd(2*m*n, m*m+n*n) != 1) return false;
  if(__gcd(m*m-n*n, m*m+n*n) != 1) return false;
  return true;
}

void bruteforce(){ // this isn't bruteforce...but yea it is..its just using clever tricks and doing stuff....hehe!555
  int ans = 0;
  int L = 1500001;
  vector<int> a(L, 0);
  
  int LIMIT = 900;
  for(int i=1;i<LIMIT;++i){
	for(int j=i+1;j<LIMIT;++j){
	  if(satisfyCondition(i, j)){
		int perimeter = 2*j*(i+j);
		int AdditiveTerm = 2*j*(i+j);
		while (perimeter < L){
		  a[perimeter]++;
		  perimeter+=AdditiveTerm;
		}
	  }
	}
  }

  for(auto x: a) if(x == 1) ans++;

  cout << ans << "\n";
}

int main(){
  bruteforce();
  return 0;
}
