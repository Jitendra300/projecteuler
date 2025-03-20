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

int n;
ll a[85][85];
ll paths[85][85];
bool visited[85][85];
vector<vector<int>> route = {{0, 1}, {1, 0}, {-1, 0}};

ll dijkstar_algo(int i, int j){
  ll ans = 0;
  paths[i][j] = 0;
  priority_queue<tuple<int, int, int>> q;
  q.push(make_tuple(0, i, j));
  bool run = true;
  while(!q.empty() && run){
	tuple<int, int, int> Tuple = q.top();
	int ith = get<1>(Tuple);
	int jth  = get<2>(Tuple);
	q.pop();
	// cout << ith << " " << jth << "\n";
	if(visited[ith][jth]) continue;
	visited[ith][jth] = true;
	for(int k=0;k<3;++k){
	  int w = get<0>(Tuple);
	  int ith2 = ith+route[k][0];
	  int jth2 = jth+route[k][1];
	  if(paths[ith][jth]+w < paths[ith2][jth2]){
		paths[ith2][jth2] = paths[ith][jth]+w;
		q.push(make_tuple(paths[ith2][jth2]*-1, ith2, jth2));

		if(jth2 == n-1){
		  run = false;
		  ans = paths[ith2][jth2];
		  break;
		}
	  }
	}
  }
  return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;

	for(int i=0;i<n;++i){
	  for(int j=0;j<n;++j){
		cin >> a[i][j];
	  }
	}
	
	ll ans = 9223372037758;
	for(int i=0;i<n;++i){
	  memset(visited, false, sizeof visited);
	  memset(paths, 923376854, sizeof paths);
	  ans = min(ans, dijkstar_algo(i, 0));
	}

	cout << ans << "\n";
	return 0;
}
