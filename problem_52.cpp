#include<bits/stdc++.h>
using namespace std;

bool check(int n){
  map<int, int>  s;
  
  int num = n;
  while(num){
	if(s.count(num%10) == 0) s[(num%10)] = 1;
	else s[(num%10)]++;
	num /= 10;
  }

  num = 2*n;
  while(num){
	if(s.count(num%10) == 0) s[(num%10)] = 1;
	else s[(num%10)]++;
	num /= 10;
  }
  
  num = 3*n;
  while(num){
	if(s.count(num%10) == 0) s[(num%10)] = 1;
	else s[(num%10)]++;
	num /= 10;
  }
  
  num = 4*n;
  while(num){
	if(s.count(num%10) == 0) s[(num%10)] = 1;
	else s[(num%10)]++;
	num /= 10;
  }
  
  num = 5*n;
  while(num){
	if(s.count(num%10) == 0) s[(num%10)] = 1;
	else s[(num%10)]++;
	num /= 10;
  }
  
  num = 6*n;
  while(num){
	if(s.count(num%10) == 0) s[(num%10)] = 1;
	else s[(num%10)]++;
	num /= 10;
  }

  for(auto x: s){
	if(x.second % 6 != 0) return false;
  }
  return true;
}

void bruteforce(){
  int i=123456;
  int LIMIT = 166666;
  while(i<=LIMIT){
	if(i == 111111){
	  ++i;
	  continue;
	}
	if(check(i)){
	  cout << i << "\n";
	  break;
	}
	++i;
  }
}

int main(){
  bruteforce();
  return 0;
}
