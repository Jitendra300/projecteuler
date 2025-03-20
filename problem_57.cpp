#include<bits/stdc++.h>
using namespace std;

long long pell_num[1005];
long long lucas_pell_num[1005];

long long numerator(long long n1, long long n2){
  return (2*n2 + n1);
}

long long denominator(long long n1, long long n2){
  return (2*n2 + n1)/2;
}

string multiply_by_two(string s1, string s2)
{
  
}

string add_string(string s1, string s2)
{
  string new_string = "";
  int carry = 0;
  if(s1.size() >= s2.size()){
	int j = s2.size()-1;
	for(int i=s1.size()-1;i>=0;--i)
	  {
		int curr_sum = carry;
		if(j<0) curr_sum += (s1[i]-'0');
		else{
		  curr_sum += ((s1[i]-'0') + (s2[j]-'0'));
		  --j;
		}
		
		int digit = curr_sum%10;
		carry = (curr_sum-digit)/10;
		if(i==0) new_string = to_string(curr_sum) + new_string;
		else new_string = to_string(digit) + new_string;
		cout << new_string << "\n";
	  }
  }
  else
	{
	  int j=s1.size()-1;
	for(int i=s2.size()-1;i>=0;--i)
	  {
		int curr_sum = carry;
		if(j<0) curr_sum += (s2[i]-'0');
		else{
		  curr_sum += ((s1[j]-'0') + (s2[i]-'0'));
		  --j;
		}

		int digit = curr_sum%10;
		carry = (curr_sum-digit)/10;
		if(i==0) new_string = to_string(curr_sum) + new_string;
		else new_string = to_string(digit) + new_string;
	  }
	}
  return new_string;
}


int total = 0;

void using_formulas(){
  pell_num[0] = 0;
  pell_num[1] = 1;

  lucas_pell_num[0] = 2;
  lucas_pell_num[1] = 2;
  int n = 1;
  while(n < 100){
	string dum = to_string(numerator(pell_num[n-1], pell_num[n]));
	string num = to_string(denominator(lucas_pell_num[n-1], lucas_pell_num[n]));	
	cout << num << "/" << dum << "\n";
	pell_num[n+1] = numerator(pell_num[n-1], pell_num[n]);
	lucas_pell_num[n+1] = 2*denominator(lucas_pell_num[n-1], lucas_pell_num[n]);

	if(num.size() > dum.size()) ++total;
	++n;
  }
  cout << total << "\n";
}

int main(){
  // using_formulas();
  string n,m; cin >> n >> m;
  cout << add_string(n, m) << "\n";
  return 0;
}
