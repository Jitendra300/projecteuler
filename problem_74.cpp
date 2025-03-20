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

int factorial[10] = {1,1,2,6,24,120,720,5040,40320,362880};

bool notinlist(int n, vector<int> Arr){
  for(int i=0;i<Arr.size();++i){
	if(Arr[i] == n) return false;
  }
  return true;
}

int fac_num(int n){
  int num = 0;
  while(n){
	num += factorial[n%10];
	n/=10;
  }
  return num;
}

void bruteforce(){
  int ans = 0;
  int n=0;
  while(n<1000000){
	vector<int> cur_list;
	int cur_num = n;
	while(notinlist(cur_num, cur_list)){
	  cur_list.push_back(cur_num);
	  cur_num = fac_num(cur_num);
	  if(cur_list.size() == 60){
		ans++;
		break;
	  }
	}
	++n;
  }
  cout << ans << nl;
}

void clevertrick(){
  int ans = 0;
  int n=0;
  while(n<1000000){
	if(fac_num(n) == 367945) ++ans; // cause we have to check just the permutation of 1479 and 0479 # making sure 0 isn't being above.
	if(fac_num(n) == 367954) ++ans; // cause we have to check just the permutation of 223479 while not counting double 2's.
	++n;
  }
  cout << ans << nl;
}

void maths(){
  cout << (fac_num(6)/2 + fac_num(4) + 3*3*2) << nl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	// bruteforce(); // pretty dull soln, takes more than 15seconds
	// clevertrick(); 
	maths();
	return 0;
}
