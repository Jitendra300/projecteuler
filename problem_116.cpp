#include<bits/stdc++.h>
using namespace std;

#define ll long long

int D = 50; // here this is the number of tiles...

ll C(int n, int k){
  long double res = 1;
  for(int i=1;i<=k;++i)
	res = res*(n-k+i)/i;
  return (long)(res+0.01);
}

ll NumberOfWaysForNTile(int n){
  ll ans = 0LL;
  for(int k=1;k<=(D/n);++k){
	ans += C(D-((n-1)*k), k);
  }
  return ans;
}

/*
Simple Math solution:
for 2 block tile....
   ans2 = 0
   for k in range(1, 25):
       ans2 += Binomial(50-k, k)
for 3 block tile....
   ans3 = 0
   for k in range(1, 16):
       ans3 += Binomial(50-2*k, k)
for 4 block tile....
   ans4 = 0
   for k in range(1, 12):
       ans4 += Binomial(50-3*k, k)
ans = ans2+ans3+ans4

give ans   ;)
 */

int main(){
  ll ans = 0LL;
  ans += NumberOfWaysForNTile(2); // this is the no of ways to get 2 tiles settled...
  ans += NumberOfWaysForNTile(3); // this is the no of ways to get 2 tiles settled...
  ans += NumberOfWaysForNTile(4); // this is the no of ways to get 2 tiles settled...
  cout << ans << "\n";
  return 0;
}
