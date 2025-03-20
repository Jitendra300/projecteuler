#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a[100];

int main(){
  ll ans = 0LL;
  int d = 50;
  a[0] = 1; // chumma kept
  a[1] = 1; // g
  a[2] = 2; // gg RR
  a[3] = 4; // ggg RRg gRR GGG
  a[4] = 8; // gggg RRRR ggRR RRgg gRRg GGGg gGGG BBBB 

  for(int i=5;i<=d;++i){
	a[i] = a[i-1]+a[i-2]+a[i-3]+a[i-4];
  }
  
  cout << a[50] << "\n";
  return 0;
}
