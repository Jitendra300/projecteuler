#include<bits/stdc++.h>
using namespace std;

void more_clever_trick(){
  // the below solution comes from the fact that we only need to search primes and we use OEIS for our help...and then find the increasing length of the repeating digits...[we cheated using OEIS and clever cheating tricks]
  cout << 983 << "\n";
}

bool isprime(int x){
  if(x%2 == 0) return false;
  for(int i=3;i<=(int(sqrt(x))+1);i=i+2){
	if(x%i == 0) return false;
  }
  return true;
}

void clever_trick(){
  int ans = 0;
  int large_k = 0;
  int n=3;
  while(n < 1000){
	int k = 1;
	int num = 10%n;
	int p_mod = num%n;
	
	while(p_mod != 1){
	  ++k;
	  num = 1;
	  for(int i=1;i<=k;++i){
		num *=10;
		num %= n;
	  }
	  p_mod  = num%n;
	}
	
	if(large_k <= k){
	  ans = n;
	  large_k = k;
	  cout << n << "\n";
	}
	++n;
	cout << n << "\n";	
	while(!isprime(n)) ++n;
  }
  cout << ans << "\n";
}

int main(){
  clever_trick();
  // more_clever_trick();
  return 0;
}
