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

int a[82][82];
int n = 80;
int arr[82][82];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n; cin >> n;

	for(int i=0;i<=n;++i){
	  for(int j=0;j<=n;++j){
		if(i == 0 || j == 0){
		  a[i][j] = 0;
		  continue;
		}
		cin >> a[i][j];
	  }
	}

	for(int i=1;i<=n;++i){
	  for(int j=1;j<=n;++j){
		arr[i][j] = a[i][j];

		if(arr[i-1][j] == 0 && arr[i][j-1] != 0) arr[i][j] += arr[i][j-1];
		if(arr[i][j-1] == 0 && arr[i-1][j] != 0) arr[i][j] += arr[i-1][j];
		else arr[i][j] += min(arr[i-1][j], arr[i][j-1]);
	  }
	}

	cout << arr[n][n] << "\n";
	return 0;
}
