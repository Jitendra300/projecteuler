#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
  if(n <= 1) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(int i=3;i<=(int(sqrt(n))+1);i=i+2){
	if(n%i == 0) return false;
  }
  return true;
}

bool isAP(int a, int b, int c){
  return ((a+c) == 2*b);
}

vector<int> primes_4d;

void generate_primes(){
  for(int i=1001;i<=9999;i=i+2){
	if(isprime(i)) primes_4d.push_back(i);
  }
}

bool ispermutation(int a, int b, int c){
  int copy_b=b;
  int copy_c=c;
  int arr_a_b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  
  while(a) {arr_a_b[a%10]++; a/=10;}
  while(b) {arr_a_b[b%10]--; b/=10;}
  for(int i=0;i<10;++i){
	if(arr_a_b[i] != 0) return false;
  }

  int arr_b_c[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  while(copy_b) {arr_b_c[copy_b%10]++; copy_b/=10;}
  while(copy_c) {arr_b_c[copy_c%10]--; copy_c/=10;}
  for(int i=0;i<10;++i){
	if(arr_b_c[i] != 0) return false;
  }
  
  return true;
}

void bruteforce(){
  generate_primes();
  int size = primes_4d.size();
  for(int i=0;i<size;++i){
	for(int j=i+1;j<size;++j){
	  for(int k=j+1;k<size;++k){
		int a = primes_4d[i];
		int b = primes_4d[j];
		int c = primes_4d[k];
		if(ispermutation(a,b,c) && isAP(a,b,c)){
		  printf("%d %d %d\n", a,b,c);
		}
	  }
	}
  }
}

int main(){
  bruteforce();
  return 0;
}
