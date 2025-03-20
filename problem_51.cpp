#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
  if(n <= 1 ) return false;
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(int i=3;i<=(int(sqrt(n))+1);i+=2){
	if(n%i == 0) return false;
  }
  return true;
}

void bruteforce(){
  int size=65000;
  vector<int> primes;
  int n=120001; // 234361 -> checked this number till 2 digit swap
  while(primes.size() < size){
	if(isprime(n)) primes.push_back(n);
	n+=2;
  }

  int not_found = true;
  for(int i=0;i<size && not_found;++i){
	string cur_prime = to_string(primes[i]);
	for(int j=0;j<cur_prime.size() && not_found;++j){
	  for(int k=j+1;k<cur_prime.size() && not_found;++k){
		for(int p=k+1;p<cur_prime.size() && not_found;++p){
		int count = 1;
		for(int l=0;l<10;++l){
		  string new_prime = "";
		  for(int m=0;m<cur_prime.size();++m){
			if(m == 0 && l == 0) new_prime += "-";
			if(m == j || m == k || m == p) new_prime += to_string(l);
			else new_prime += cur_prime[m];
		  }
		  int num = stoi(new_prime);
		  auto ranges = equal_range(primes.begin(), primes.end(), num);
		  if(ranges.second-ranges.first == 1 && cur_prime != new_prime){
			count++;
		  }
		  if(count >= 8) break;
		}
		if(count >=8){
		  cout << "Permutation of this prime with 3 same digits gives 8 key family primes: " << cur_prime << "\n";
		  not_found = false;
		  break;
		}
		}
	  }
	}
  }
}


int main(){
  bruteforce();
  return 0;
}
