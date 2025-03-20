#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll C(int n, int k){
  long double res = 1;
  for(int i=1;i<=k;++i)
	res = res*(n-k+i)/i;
  return (long)(res+0.01);
}

// found the sequence and it's formula from oeis website...
void usingOEIS(){
  ll d = 51; // cause the formula gives f(n+1) value
  ll ans = 0LL;
  for(ll k=0LL;k<=floor(d/4);++k)
	ans += C(d - 2*k, 2*k);
  cout << ans << "\n";
}

void dpSolution(){
  ll dp[55];
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  int d = 50;
  for(int i=4;i<=d;++i){
	dp[i] = 2*dp[i-1] - dp[i-2] + dp[i-4];
  }
  cout << dp[50] << "\n";
}

void dpSolution2(){
  ll dp[55];
  int d = 50;
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  dp[4] = 4;

  for(int i=5;i<=d;++i){
	ll curDpSoln = 2LL; // this is the pre value of f(-1);
	for(int j=1;j<=i;++j){
	  if(j == 3 || j==2) continue;
	  curDpSoln += dp[i-j];
	}
	dp[i] = curDpSoln;
  }
  cout << dp[50] << "\n";
}

int main(){
  // usingOEIS();
  // dpSolution();
  dpSolution2();  
  return 0;
}
