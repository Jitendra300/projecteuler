#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool ispalindrome(ll n){
  ll copyN = n;
  ll reverseN = 0;
  while(copyN){
	reverseN *= 10;
	reverseN += copyN%10;
	copyN /= 10;
  }
  return (reverseN == n);
}

void solution(){
  unordered_set<int> s;
  ll ans = 0LL;
  int n = 7070;
  ll squares[n+2];
  squares[0] = 0LL;
  
  for(int i=1;i<=n;++i) squares[i] = i*i+squares[i-1];

  for(int i=0;i<=n;++i){
	for(int j=i+2;j<=n;++j){
	  ll difference = squares[j]-squares[i];
	  if((difference < 100000000LL) && ispalindrome(difference)){
		s.insert(difference);
	  }
	}
  }

  for(auto x: s) ans+=x;
  printf("%lld\n", ans);
}

int main(){
  solution();
  return 0;
}
