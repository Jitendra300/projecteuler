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

bool ispermutation(int n, int m){
  int digit[] = {0,0,0,0,0,0,0,0,0,0};
  while(n){
	digit[n%10]++;
	n/=10;
  }
  while(m){
	digit[m%10]--;
	m/=10;
  }
  for(int i=0;i<10;++i){
	if(digit[i] != 0) return false;
  }
  return true;
}

int  phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void bruteforce(){
  double limit = 100000;
  int ans = 0;
  int n = 2;
  while(n<=9999999){
	int phiValue = phi(n);
	if(ispermutation(n, phiValue)){
	  if(limit >= (n*1.0/phiValue)){
		ans = n;
		limit = (n*1.0/phiValue);
	  }
	}
	n++;
  }
  cout << ans << nl;
}

bool isprime(int n){
  if(n<=1) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(int i=3;i<=(int(sqrt(n))+1);i+=2){
	if(n%i == 0) return false;
  }
  return true;
}

void smarttrick(){
  vector<int> primes;
  primes.push_back(2);
  int n=3;

  while(n <= 3600){
	if(isprime(n)) primes.push_back(n);
	n+=2;
  }

  int size = primes.size();
  int ans = 0;
  double diff = 10000.0;
  
  for(int i=size-1;i>=size/2;--i){
	for(int j=i-1;j>=size/2;--j){
	  int num = primes[i]*primes[j];
	  if(num > 9999999) continue;
	  int phiValue = phi(num);
	  if(ispermutation(num, phiValue)){
		if(diff > (num*1.0/phiValue)){
		  diff = (num*1.0)/phiValue;
		  ans = num;
		}
	  }
	}
  }
  cout << ans << nl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	// bruteforce();
	smarttrick();
	return 0;
}
