#include<bits/stdc++.h>
using namespace std;

// this problem asks us for n where n = a+b+c where c^2 = a^2 + b^2 and c,b,a are all unique.
#define ll long long

ll arr[750015];

bool isOurNum(int n){
  int bIndex=sqrt(n), cIndex=n/2;
  int count = 0;
  while(bIndex<cIndex){
	ll B = sqrt(arr[bIndex]);
	ll C = sqrt(arr[cIndex]);
	long double num = B + C + sqrt(C*C - B*B);
	if(num == long(num) && num == n){
	  cout << sqrt(C*C-B*B) << " " << B << " " << C << "\n";
	  count++;
	  bIndex++;
	}
	else if(num < n) bIndex++;
	else if(num > n) cIndex--;
	
	if(C < n/3) break;
	if(B > floor((n-C)/2)) break;
	if(count > 1) return false;
  }
  return count == 1;
}

void bruteforce(){
  for(ll i=0;i<750010;++i) arr[i] = i*i;
  // int ans = 1;
  // ll L = 24;
  // // ll LIMIT = 1500000;
  // ll LIMIT = 1000;
  // while(L <= LIMIT){
  // 	if(isOurNum(L)){
  // 	  ++ans;
  // 	  cout << L << "\n";
  // 	}
  // 	L += 2;
  // }
  // cout << ans << "\n";
}

int main(){
  bruteforce();
  int n; cin >> n;
  isOurNum(n);
  return 0;
}
