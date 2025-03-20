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

int SIZE = 400;

vector<ll> coins;
vector<ll> ans(SIZE+1, 0);

void dp(){
  ans[0] = 1;

  for(int j=1;j<=SIZE;++j){
	for(int i=1;i<=SIZE;++i){
	  if(i-j >= 0){
		ans[i] += ans[i-j];
	  }
	}
  }

  for(int i=1;i<=SIZE;++i){
	cout << ans[i] << "\n";
  }
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	dp();
	return 0;
}
