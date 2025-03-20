#include<bits/stdc++.h>
using namespace std;

int LIMIT = 1000000;
int dp[1000002];

int ReturnSumDivisors(int num) {
  int copyNum = num;
    int total = 1;
    for (int i = 2; (int)i*i <= num; i++) {
	  if (num % i == 0) {
		int e = 0;
		do{
		  e++;
		  num /= i;
		}while (num % i == 0);
		
		int sum = 0, pow = 1;
		do{
		  sum += pow;
		  pow *= i;
		}while (e-- > 0);
		total *= sum;
	  }
    }
    if (num > 1) {
	  total *= (1 + num);
    }
	if(total-copyNum >= LIMIT) return -1;
    return total-copyNum;
}

int getSmallNumber(int n){
  int sumDivisorsOfN = ReturnSumDivisors(n);
  int minElement = sumDivisorsOfN;
  while(n != sumDivisorsOfN){
	sumDivisorsOfN = ReturnSumDivisors(sumDivisorsOfN);
	minElement = min(minElement,sumDivisorsOfN);
  }
  return minElement;
}


void bruteforce(){
  // default dp values...
  dp[0] = 0;
  dp[1] = 1;

  int n=2;
  while(n<LIMIT){
	int sumDivisorsOfN = ReturnSumDivisors(n);
	if(sumDivisorsOfN == -1 || sumDivisorsOfN == 0) dp[n] = 1;
	else dp[n] = sumDivisorsOfN;
	++n;
  }

  int smallestNum = INT_MAX;
  int largestChain = 0;

  for(int k=1;k<LIMIT;++k){
	if(dp[k] == 1) continue;

	int currentChainLength = 1;
	int currentElement = dp[k];
	set<int> Elements;

	while(currentElement != k){
	  if(Elements.count(dp[currentElement])){
		currentChainLength = -1;
		break;
	  }
	  currentElement = dp[currentElement];
	  if(currentElement == -1){
		currentChainLength = -1;
		break;
	  }
	  ++currentChainLength;
	  Elements.insert(currentElement);
	}

	if(currentChainLength >= largestChain){
	  largestChain = currentChainLength;
	  smallestNum = k;
	  // cout << smallestNum << "\n";
	}
  }
  cout << getSmallNumber(smallestNum) << "\n";
  // cout << largestChain << "\n";
}

int main(){
  bruteforce();
  // // int n; cin >> n;
  // for(int i=1;i<100;++i)
  // 	cout << i << " " << ReturnSumDivisors(i) << "\n";
  return 0;
}
