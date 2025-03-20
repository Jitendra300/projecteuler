#include<bits/stdc++.h>
using namespace std;

vector<int> v = {1,2,3,4,5,6,7};

bool isprime(long long n){
  if(n <= 1) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(long long i=3;i<=(int(sqrt(n))+1);i=i+2){
	if(n%i == 0) return false;
  }
  return true;
}

void bruteforce(){
  int ans = 0;
  do{
	int num=0, i=v.size()-1;
	while(i>=0){
	  num *= 10;
	  num += v[i];
	  --i;
	}
	if(isprime(num)){
	  ans = max(num, ans);
	}
	// cout << num << "\n";
  }while(next_permutation(v.begin(), v.end()));

  cout << ans << "\n";
}

int main(){
  bruteforce();
  return 0;
}
