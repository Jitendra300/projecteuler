#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

bool isPythagoras(long double c, long double b){
  return sqrt(c*c  - b*b) == long(sqrt(c*c - b*b));
}

void bruteforce(){
  ll ans = 0LL;
  ll NUM_LIMIT = 333333335;
  // ll NUM_LIMIT = 1000;
  ll PERIMETER_LIMIT = 1000000000;
  ll c = 5;

  while(c < NUM_LIMIT){
	// checking if c, and c-1 make a almost equilateral triangle;
	long double weird_side = (c-1)/2;
	long double height1 = sqrt(c*c - weird_side*weird_side);
	if(2*weird_side == c-1 && height1 == long(height1)){
	  cout << c << " " << 2*weird_side << " " << height1 << nl;
	  if(3*c - 1 > PERIMETER_LIMIT) break;
	  ans += (3*c-1);
	}

	//checking if c, c+1 make a almost equilateral triangle;
	long double weird_side2 = (c+1)/2;
	long double height2 = sqrt(c*c - weird_side2*weird_side2);
	if(2*weird_side2 == c+1 && height2 == long(height2)){
	  cout << c << " " << 2*weird_side2 << " " << height2 << nl;
	  if(3*c + 1 > PERIMETER_LIMIT) break;
	  ans += (3*c + 1);
	}
	c+=2;
  }
  
  cout << ans << "\n";
}

void using_flaw_mathematics(){ // cause this is using some conjecture...lol
  ll ans = 0;
  ll dp[20] = {1, 1, 1};
  ll LIMIT = 1000000000;
  for(int i=3;i<20;++i){
	if(3*dp[i]+1 > LIMIT) break;
	if(3*dp[i]-1 > LIMIT) break;

	dp[i] = 3*dp[i-1] + 3*dp[i-2] - dp[i-3];

	ll weird_side1 = (dp[i]-1)/2;
	ll height1 = sqrt(dp[i]*dp[i] - weird_side1*weird_side1);
	if(height1 == long(height1)){
	  ll perimeter = 3*dp[i] - 1;
	  if(perimeter < LIMIT) ans+=perimeter;
	  else break;
	}

	ll weird_side2 = (dp[i]+1)/2;
	ll height2 = sqrt(dp[i]*dp[i] - weird_side2*weird_side2);
	if(height2 == long(height2)){
	  ll perimeter = 3*dp[i] + 1;
	  if(perimeter < LIMIT) ans+=perimeter;
	  else break;
	}
  }
  cout << ans/2 << "\n"; // i hv no idea why this works...maybe that's why its a conjecture lol! 555
  // for(int i=3;i<10;++i) cout << dp[i] << " ";
}
  
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	// bruteforce();
	using_flaw_mathematics();
	return 0;
}
