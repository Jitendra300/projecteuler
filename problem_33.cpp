#include<bits/stdc++.h>
using namespace std;

bool property(double x, double y){
  if(fmod(x,10) == fmod(y,10)){
	double real  =x/y;
	double imaginary = ((x- fmod(x,10))/10)/((y- fmod(y,10))/10);
	if(real == imaginary) return  true;
  }
if((x-fmod(x,10))/10 ==fmod(y, 10)){
	double real  =x/y;
	double imaginary = ((fmod(x,10)))/((y-fmod(y,10))/10);
	if(real == imaginary) return  true;
  }
if((x-fmod(x,10))/10 == (y-fmod(y,10))/10){
	double real  =x/y;
	double imaginary = fmod(x,10)/fmod(y,10);
	if(real == imaginary) return  true;
 }
if(fmod(x,10) == ((y-fmod(y,10))/10)){
	double real  =x/y;
	double imaginary = ((x-fmod(x,10))/10)/fmod(y,10);
	if(real == imaginary) return  true;
  }
  return false;
}

void brute_force(){
  int product = 1;
  double numerator = 1;
  double dumerator = 1;
  vector<pair<double, double>> num;
  for(double i=11;i<99;++i){
	if(fmod(i,10) == 0) continue;
	for(double j=i+1;j<99;++j){
	  if(fmod(j,10) == 0) continue;
	  // if(!check(i, j)) continue;
	  if(property(i, j)){
		num.push_back({i, j});
		numerator *= i;
		dumerator *= j;
	  }
	}
  }
  lowest_form(numerator, dumerator);
  // cout << numerator << "/" << dumerator << "\n";
}

int main(){
  brute_force();
  // cout << property(49, 98) << "\n";
  // cout << property(double(88),double(98)) << "\n";
  return 0;
}
