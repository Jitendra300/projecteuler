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

typedef unsigned long long ULL;

ULL mod = 10000000000;

long long powmod(long long base, long long expo){
  long long ans = 1;

  if(base%mod == 0) return 0LL;
  while(expo > 0){
	if(expo&1) ans = (ans*base)%mod;
	expo = expo >> 1;
	base = (base*base)%mod;
  }
  return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	long long factor, base, expo, add;
	// cin >> factor >> base >> exponent >> add;
	factor = 2357207;
	base = 2;
	expo = 7830457;
	add = 1;
	// unsigned long long ans = (powmod(base, exponent)*factor + add)%mod;;
	long long ans = powmod(base, expo);
	// cout << powmod(base, exponent) << "\n";
	cout << ans << nl;
	return 0;
}
