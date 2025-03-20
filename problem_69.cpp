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

bool isprime(int n){
  if(n<1) return false;
  if(n==2) return true;
  if(n%2 == 0) return false;
  for(int i=3;i<=int(sqrt(n)+1);i=i+2){
	if(n%i == 0) return false;
  }
  return true;
}

void smart_trick(){
  int n=3;
  int ans = 2;
  while(n<1000000){
	if(isprime(n)) ans*=n;
	if(ans>1000000){
	  cout << ans/n << "\n";
	  break;
	}
	n=n+2;
  }
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	/*
	  Info we know:
	  -> let f(n) be euler totient function of n then we know f(p) for all prime p is equal to p-1;
      -> also  we know euler totient function is multiplicative thus; we can conclude 
      -> any number of the form k = 2*3*5*6*....*p where the k  is less than 1million is our answer;
	 */
	smart_trick();
	return 0;
}
