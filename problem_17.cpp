#include<bits/stdc++.h>
using namespace std;

int n = 1000;

void simulation(){
  map<int, string> ones;
  map<int, string> tens;
  map<int, string> spl;  
  //for single digit;
  ones[1] = "one";
  ones[2] = "two";
  ones[3] = "three";
  ones[4] = "four";
  ones[5] = "five";
  ones[6] = "six";
  ones[7] = "seven";
  ones[8] = "eight";
  ones[9] = "nine";

  //for two digits;
  tens[1] = "ten";
  tens[2] = "twenty";
  tens[3] = "thirty";
  tens[4] = "forty";
  tens[5] = "fifty";
  tens[6] = "sixty";
  tens[7] = "seventy";
  tens[8] = "eighty";
  tens[9] = "ninety";
  
  //this ones for spl digits;
  spl[1] = "eleven";
  spl[2] = "twelve";
  spl[3] = "thirteen";
  spl[4] = "fourteen";
  spl[5] = "fifteen";
  spl[6] = "sixteen";
  spl[7] = "seventeen";
  spl[8] = "eighteen";
  spl[9] = "nineteen";

  // sum of digits;
  int real_sum = 0;

  // single digit from [0-9]
  // for(int i=1;i<=9;++i) real_sum += ones[i].size();
  
  // // for ten
  // real_sum += 10;
  
  // // for more than ten but less than 20
  for(int i=1;i<=9;++i) real_sum += spl[i].size();
  
  // // for number greater or equal to 20
  // for(int i=20;i<=99;++i){
  // 	if(i%10 == 0) real_sum += tens[i%10].size();  // for numbers like 20, 30, 40, 50...
  // 	else real_sum += (tens[(i-(i%10))/10].size() + ones[i%10].size()); // for numbers like 23, 45, 99;
  // }

  // // for 100
  // real_sum += 10;

  // // for more than hundred;
  // for(int i=101;i<=999;++i){
  // 	// if(i%100 == 0) real_sum += (ones[i/100].size() + 7);
  // 	if(i%10 != 0) real_sum += (ones[i%10].size());  // this is for last digit....
  // 	if((i-(i%10))/10 != 0) real_sum += (tens[i%10].size())
  // }
  
  // // real_sum += 11;
  cout << real_sum << "\n";
}

int main(){
  simulation();
  return 0;
}
