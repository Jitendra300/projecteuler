#include<bits/stdc++.h>
using namespace std;

// stupid brute_force
void brute_force_it(){
  int ans = 0;
  for(int i=1;i<=700;++i){
	for(int j=1;j<=700;++j){
	  for(int k=1;k<=999;++k){
		if(i+j+k == 1000 && ((i*i+j*j) == k*k)){
		  cout << i << " " << j << " " << k << "\n";
		  ans = i*k*j;
		  break;
		}
	  }
	}
  }
  cout << ans << "\n";
}

// runs faster than above implementation
void clever_brute_force(){
  int ans = 0;
  for(int i=1;i<=999;++i){
	for(int j=i+1;j<=999-i;++j){
	  float c = sqrt(i*i + j*j);
	  if(c == int(c) && (i+j+c == 1000)){
		ans = i*j*c;
		break;
	  }
	}
  }
  cout << ans << "\n";
}

// using maths;;
void smarter_way(){
  //every pythagorean triplet can be expressed as: a=2mn, b=m^2-n^2, and c=m^2+n^2;
  // thus this gives m(m+n) = 500; [just sub values of a, b, and c in a+b+c = 1000]

  // then we find some of the biggest factors of 500 then we find 25 and 20 thus we try our loops on this range and find answer;
  for(int i=1;i<=25;++i){ 
	for(int j=1;j<=20;++j){
	  if(i*(i+j) == 500){
		cout << (2*i*j)*(i*i - j*j)*(i*i+j*j) << "\n";
		break;
	  }
	}
  }
}

int main(){
  // brute_force_it();
  // clever_brute_force();
  smarter_way();
  return 0;
}
