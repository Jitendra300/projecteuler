#include<bits/stdc++.h>
using namespace std;

int returnCharDigitValue(char k){
  if(k-'0' == 0) return 10;
  return k-'0';
}

bool conditionisSatisfied(string s){
  int x1 = returnCharDigitValue(s[1]);
  int x2 = returnCharDigitValue(s[2]);
  int x3 = returnCharDigitValue(s[3]);
  int x4 = returnCharDigitValue(s[4]);
  int x5 = returnCharDigitValue(s[5]);
  int x6 = returnCharDigitValue(s[6]);
  int x7 = returnCharDigitValue(s[7]);
  int x8 = returnCharDigitValue(s[8]);
  int x9 = returnCharDigitValue(s[9]);
  int x10 = returnCharDigitValue(s[0]);

  if(x1 >= 6 || x2 >= 6 || x3 >= 6 || x4 >= 6 || x5 >=6) return false; // check it urself buddy
  if(x10 != 10) return false; // check it urself
  
  int block1 = x6+x5+x1;
  int block2 = x10+x5+x4;
  int block3 = x9+x4+x3;
  int block4 = x8+x3+x2;
  int block5 = x7+x2+x1;

  if(block1 == block2 && block2 == block3 && block3 == block4 && block4 == block5 && block5 == block1) return true;

  return false;
}

string returnPatternString(string s, int p, int q, int r){
  string block = "";
  if(s[p] == '0') block += "10";
  else block += s[p];
  
  if(s[q] == '0') block += "10";
  else block += s[q];
  
  if(s[r] == '0') block += "10";
  else block += s[r];

  return block;
}

string convertFormat(string s){
  int arr[5] = {stoi(returnPatternString(s, 6, 1, 5)), stoi(returnPatternString(s, 0, 5, 4)), stoi(returnPatternString(s, 9, 4, 3)), stoi(returnPatternString(s, 8, 3, 2)), stoi(returnPatternString(s, 7, 2, 1))};
  string num = "";
  for(int i=0;i<5;++i) num+=to_string(arr[i]);
  return num;
}

void bruteforce(){
  long long ans = 0LL;
  string ansS = "";
  string s= "0123456789";
  while(next_permutation(s.begin(), s.end())){
	if(conditionisSatisfied(s)){
	  string curNum = convertFormat(s);
	  if(curNum.size() == 16){
		ans = max(ans, stoll(curNum));
		cout << s << " ->" << curNum << "\n";
	  }
	}
  }
  cout << ans << "\n";
}

int main(){
  bruteforce();
  return 0;
}
