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

bool ispermutation(ll n, ll m){
  int digits[] = {0,0,0,0,0,0,0,0,0,0};
  while(n){
	digits[n%10]++;
	n/=10;
  }
  while(m){
	digits[m%10]--;
	m/=10;
  }
  for(int i=0;i<10;++i){
	if(digits[i] != 0) return false;
  }
  return true;
}

void brute_force(){
  int sLimit = 5000;
  int eLimit = 10000;
  int interval = eLimit-sLimit;  
  ll arr[interval];
  for(ll i=sLimit;i<eLimit;++i){
	arr[i-sLimit] = i*i*i;
  }

  ll smallcube = 9223372036854775807;
  int maxcount = 0;

  for(int i=1;i<interval;++i){ // we can keep running this till interval variable but ik already[cause i ran before and found out] tht this ends at;
	int count = 0;
	for(int j=i+1;j<interval;++j){ // and here we can customize that we have 8384 as last permutation connection with 5027;
	  if(ispermutation(arr[i], arr[j])){
		count++;
	  }
	}
	if(maxcount < count){
	  maxcount = count;
	  smallcube = arr[i];
	}
	if(maxcount+1 == 5) break;
  }
  cout << smallcube << nl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	brute_force();
	return 0;
}
