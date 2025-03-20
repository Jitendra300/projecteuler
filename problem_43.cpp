#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl "\n"

vector<int> arr ={0,1,2,3,4,5,6,7,8,9};
int primes[7] = {2,3,5,7,11,13,17};

bool check(int i, int index){
  int k = i+2;
  int num = 0;
  while(i<=k){
	num *= 10;
	num += arr[i];
	++i;
  }
  if(num%primes[index] == 0) return true;
  return false;
}

void brute_force(){
  ll sum = 0LL;
  do{
	if(arr[0] == 0) continue;
	int i=1;
	int index = 0;
	bool found  = false;
	for(i;i<=7;++i){
	  if(check(i, index)){
		found = true;
		++index;
	  }
	  else{
		found = false;
		break;
	  }
	}
	if(found){
	  int curr = 0;
	  ll num = 0;
	  while(curr <= 9){
		num *= 10;
		num += arr[curr];
		++curr;
	  }
	  sum += num;
	}
  }while(next_permutation(arr.begin(), arr.end()));

  cout << sum << "\n";
}

int main(){
  brute_force();
  return  0;
}
