#include<bits/stdc++.h>
using namespace std;

// this problem asks us for n where n = a+b+c where c^2 = a^2 + b^2 and c,b,a are all unique.
#define ll long long

bool isPythagoreanTriplet(int n, int m){
  return ((n*n - m*m)*(n*n - m*m) + (2*m*n)*(2*m*n) == (n*n + m*m)*(n*n + m*m));
}

bool isOurNum(int n){
  int count = 0;
  vector<int> factors;
  // n /= 2; // cause n is even and n=2*m*(m+n) and we have to find the m and n value so 2 is just a distraction!
  for(int i=1;i*i<=n;++i){
	if(n%i == 0){
	  factors.push_back(i);
	  if(i != n/i) factors.push_back(n/i);
	}
  }

  // for(auto x: factors) cout << x << " ";
  // cout << "\n";

  for(int i=0;i<factors.size();++i){
	for(int j=0;j<factors.size();++j){
	  int mfactor = factors[i];
	  int nfactor = factors[j];
	  if(2*mfactor*(mfactor+nfactor) == n) cout << mfactor << " " << nfactor << "\n";
	}
  }
  
  return count == 1;
}

void bruteforce(){
}

int main(){
  int n; cin >> n;
  isOurNum(n);
  return 0;
}
