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


bool isprime(ll n){
  if(n <= 1 ) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(ll i=3;i<=(ll(sqrt(n))+1);i+=2){
	if(n%i == 0) return false;
  }
  return true;
}

ll adjoint(ll x, ll base){
  ll num = 0;
  string strnum = to_string(x) + to_string(base);
  num = stol(strnum);
  return num;
}

void bruteforce(){
  vector<ll> primes;
  primes.push_back(3);
  int num = 7;
  while(primes.size() < 1500){
	if(isprime(num)) primes.push_back(num);
	num+=2;
  }

  int size = primes.size();
  bool run = true;

  int loop1 = 0;
  while(run){
	ll Prime1 = primes[loop1];
	int loop2 = loop1+1;
	bool run2 = true;
	// second loop to find second such prime.
	while(run2){
	  ll Prime2 = primes[loop2];
	  if(isprime(adjoint(Prime1, Prime2)) && isprime(adjoint(Prime2, Prime1))){ // checking for adjoint prime property
		int loop3 = loop2+1;
		bool run3 = true;
		while(run3){
		  ll Prime3 = primes[loop3];
		  if(isprime(adjoint(Prime3, Prime2)) && isprime(adjoint(Prime2, Prime3)) && isprime(adjoint(Prime1, Prime3)) && isprime(adjoint(Prime3, Prime1))){
			int loop4 = loop3+1;
			bool run4 = true;
			while(run4){
			  ll Prime4 = primes[loop4];
			  if(isprime(adjoint(Prime4, Prime3)) && isprime(adjoint(Prime3, Prime4)) && isprime(adjoint(Prime4, Prime2)) && isprime(adjoint(Prime2, Prime4)) && isprime(adjoint(Prime4, Prime1)) && isprime(adjoint(Prime1, Prime4))){
				int loop5 = loop4+1;
				bool run5 = true;
				while(run5){
				  ll Prime5 = primes[loop5];
				  if(isprime(adjoint(Prime5, Prime4)) && isprime(adjoint(Prime4, Prime5)) && isprime(adjoint(Prime5, Prime3)) && isprime(adjoint(Prime3, Prime5)) && isprime(adjoint(Prime5, Prime2)) && isprime(adjoint(Prime2, Prime5)) && isprime(adjoint(Prime5, Prime1)) && isprime(adjoint(Prime1, Prime5))){
					cout << Prime1 << " " << Prime2 << " " << Prime3 << " " << Prime4 << " " << Prime5 << nl;
					run=false;
					run2=false;
					run3=false;
					run4=false;
					run5=false;
					loop1 = size;
					loop2 = size;
					loop3 = size;
					loop4 = size;
					loop5 = size;
					break;
				  }
				  loop5++;
				  if(loop5>=size) run5 = false;
				}
			  }
			  loop4++;
			  if(loop4 >= size) run4 = false;
			}
		  }
		  loop3++;
		  if(loop3>=size) run3 = false;
		}
	  }
	  loop2++;
	  if(loop2 >= size) run2 = false;
	}

	loop1++;
	if(loop1 >= size) run = false;
  }


  // for(auto x: primes) cout << x << " ";
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	bruteforce();
	// int n,m; cin >> n >> m;
	// cout << adjoint(n,m) << nl;
	// cout << adjoint(m,n) << nl;	
	return 0;
}
