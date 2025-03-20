#include<bits/stdc++.h>
using namespace std;

vector<long long> m(1000001, 0LL);

long long stimulation(long long n){
  int ans = 0;
  while(n != 1){
	if(n%2 == 0) n/=2;
	else n = 3*n + 1;
	++ans;
  }
  return ans;
}

void brute_force_it(){
  long long n = 1;
  long long largest = 0;
  long long ans = 0;
  while(n < 1000000){
	long long k = stimulation(n);
	if(k > largest){
	  largest = k;
	  ans = n;
	}
	cout << n << " : " << k << "\n";
	++n;
  }
  cout << ans << "\n";
}

long long dp(long long n){
  if(m[n]) return m[n];
  if(n%2) m[n] = dp(n/2)+1;
  else{
	long long num = 3*n+1;
	long long ans2 = 1;
	if(num >= 1000000){
	  while(num >= 1000000){
		if(num%2 == 0) num/=2;
		else num = 3*num +1;
		++ans2;
	  }
	}
	m[n] = dp(num)+ans2;
  }
  return m[n];
}

void clever_trick(){
  long long n = 1;
  long long largest = 1;
  long long ans = 1;
  while(n < 1000000){
	long long k = dp(n);
	if(k > largest){
	  largest = k;
	  ans = n;
	}
	++n;
  }
  cout << ans << "\n";
}

int main(){
  // brute_force_it();
  clever_trick();
  return 0;
}
