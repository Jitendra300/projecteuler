#include<bits/stdc++.h>
using namespace std;

int LIMIT = 28123;
bool num[30000] = {false};

bool is_abundat(int x){
  int x_sum = 0;
  for(int i=1;i<(int(sqrt(x))+1);++i){
	if(x%i == 0 && i*i != x){
	  if(i!=1)
		x_sum += (i+x/i);
	  else
		x_sum += (i);
	}
	if(x%i == 0 && i*i == x){
	  x_sum += i;
	}
  }
  return (x_sum>x);
}

void get_all_abundant_numbers(){
  memset(num,false, sizeof(num));
  for(int i=1;i<=LIMIT;++i){
	if(is_abundat(i)){
	  num[i] = true;
	}
	else num[i] = false;
  }
}

void brute_force(){
  long long sum = 0LL;
  int size = 30000;
  for(int i=1;i<=LIMIT;++i){
	bool found = false;
	for(int j=1;j<size;++j){
	  if(num[j]){
		if(i-j > 0 && num[i-j]){
		  found = true;
		  // cout << i << "\n";
		  break;
		}
	  }
	}
	if(!found){
	  sum+=i;
	}
  }
  cout << sum << "\n";
}
int main(){
  get_all_abundant_numbers();
  brute_force();
  return 0;
}
