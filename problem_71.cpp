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

void formula(){
  int n = 8;
  int a=0,b=1,c=1,d=n;
  printf("%d %d\n", a, b);
  while(0<=c && c<=n){
	printf("%d %d %d %d", a, b, c, d);	
	int k = int((n+b)) /d;
	a = c;
	b = d;
	c = k*c - a;
	d = k*d-b;
	printf("%d / %d", a, b);
  }
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	formula();
	
	return 0;
}
