#include<bits/stdc++.h>
using namespace std;

// this is my algorithm...
void algo(){
  long long ans = 0;
  int n = 3;
  while(n<=1000){
	int k = 1, limit=n*n, mod=n*n, cur_ans=0;
	while(k<=limit){
	  cur_ans = max(cur_ans, (2*n*k)%mod);
	  k+=2;
	}
	if(cur_ans == 0) ans += 1;
	else ans+=cur_ans;
	++n;
  }
  cout << ans << "\n";
}

// got this from some other person...but nice...
void useMathSkills(){ 
  long long ans = 0LL;
  int a = 3;
  while(a<=1000){
	if(a%2 == 1) ans+= (a*a - a);
	else ans += (a*a - 2*a);
	++a;
  }
  cout << ans << "\n";
}

int main(){
  // algo();
  useMathSkills();
  return 0;
}
