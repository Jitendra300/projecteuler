#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int pentagonal_num(ll n){
  return n*(3*n - 1)/2;
}

bool ispentagonal(long double n){
  long double num = (1 + (double)(sqrt(24*n)))/6;
  long long num2 = (1+sqrt(24*n))/6;
  return num == num2;
}

void soln(){
  ll ans = 0;
  ll n=1;
  bool run=true;
  while(run){
	ll d = 1;
	while((n-d)>0){
	  if(ispentagonal(pentagonal_num(n)-pentagonal_num(n-d)) && ispentagonal(pentagonal_num(n)+pentagonal_num(n-d))){
		run = false;
		cout << abs(pentagonal_num(n)-pentagonal_num(n-d)) << "\n";
		break;
	  }
	  ++d;
	}
	cout << n << "\n";
	++n;
  }
}

int main(){
  soln();
  return 0;
}
