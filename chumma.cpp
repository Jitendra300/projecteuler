#include<bits/stdc++.h>
using namespace std;

#define for0(i, n) for(int i=0;i<(int)(n); ++i)
#define for1(i, n) for(int i=1;i<=(int)(n); ++i)
#define forc(i, l, r) for(int i=(int)(l);i<=(int)(r);++i)
#define forr0(i, n) for(int i=(int)(n);i>=0;--i)

#define pb push_back
#define fi first
#define se second
#define nl "\n"

const int pmod = 1000000007;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<ll> coins;
vector<ll> ans(100, 0);

bool isprime(int n){
  if(n <= 1) return 0;
  if(n == 2) return 1;
  if(n%2 == 0) return 0;
  for(int i=3;i<(int(sqrt(n)+1));i=i+2){
	if(n%i == 0) return 0;
  }
  return 1;
}

void fill_primes(int x){
  int y = 0;
  int n = 3;
  while(y<x){
	if(isprime(n)){
	  coins.push_back(n);
	  y++;
	}
	n+= 2;
  }
}

void dp(){
  ans[0] = 1;
  coins.push_back(2);
  fill_primes(99);

  for(int x=0;x<coins.size();++x){
	for(int i=1;i<=100;++i){
	  if(i-coins[x]>=0){
		ans[i] += ans[i-coins[x]];
	  }
	}
  }

  for(int i=1;i<ans.size();++i){
	if(ans[i] >= 5000){
	  cout << i << "\n";
	  break;
	}
  }
}

// What is the first value which can be written as the sum of primes in over five thousand different ways?
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	dp();
	return 0;
}
