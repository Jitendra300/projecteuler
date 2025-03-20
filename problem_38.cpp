#include<bits/stdc++.h>
using namespace std;

// global variables
const int LIMIT = 10000;

int convert_string_to_int(string s){
  string checker  = "0000000000";
  int size = s.size();  
  for(int i=0;i<size;++i){
	if(checker[(s[i]-'0')] == '0') checker[(s[i]-'0')] = '1';
	else return -1;
  }
  if(checker == "0111111111"){
	int n=0;
	for(int i=size-1;i>=0;--i){
	  n*=10;
	  n+=(s[i]-'0');
	}
	return n;
  }
  return -1;
}

bool validity(string prod){
  if(prod.size() > 9) return false;
  return true;
}

void bruteforce(){
  int ans = INT_MIN;
  int n = 9;
  while(n <= LIMIT){
	int m = 1;
	string prod = "";
	string prev_prod = prod;
	while(validity(prod)){
	  prev_prod = prod;
	  string new_ = to_string(n*m);
	  reverse(new_.begin(), new_.end());
	  prod = new_ +prod;
	  ++m;
	}
	int prob_ans = convert_string_to_int(prev_prod);
	if(ans <= prob_ans){
	  // cout << prob_ans << "  " << n << "  " << m <<"\n";
	  ans = max(ans, prob_ans);
	}
	++n;
  }
  cout << ans <<  "\n";
}

int main(){
  bruteforce();
  return 0;
}
