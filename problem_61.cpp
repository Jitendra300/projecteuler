#include<bits/stdc++.h>
using namespace std;

#define nl "\n"

// checks if the last two digits of the first parameter number are equal to the first two digits of the second parameter number;
bool checkDigitProperty(int n, int m){
  return (n%100 == (m - m%100)/100);
}

map<int, vector<pair<int, char>>> firstTwoDigitMap;
vector<int> nums; // reality is all nums come to 351, be it tri, hex,oct...

void fillMap(int lowerLimit, int upperLimit, int polygonType){
  for(int i=lowerLimit; i<upperLimit;++i){
	int num;
	char Type;
	if(polygonType == 3){
	  num = i*(i+1)/2;
	  Type = 'T';
	}
	else if(polygonType == 4){
	  num = i*i;
	  Type = 'S';
	}
	else if(polygonType == 5){
	  num = i*(3*i-1)/2;
	  Type = 'P';
	}
	else if(polygonType == 6){
	  num = i*(2*i - 1);
	  Type = 'H';
	}
	else if(polygonType == 7){
	  num = i*(5*i - 3)/2;
	  Type = '7'; // H is already stolen ;)
	}
	else if(polygonType == 8) {
	  num = i*(3*i - 2);
	  Type = 'O';
	}

	int firstTwoDigit = (num - num%100)/100;
	firstTwoDigitMap[firstTwoDigit].push_back({num, Type});
	nums.push_back(num);
  }
}

int SendNumFromType(char findType, pair<int, char> a, pair<int, char> b, pair<int, char> c, pair<int, char> d, pair<int, char> e, int n){
  if(a.second == findType) return a.first;
  else if(b.second == findType) return b.first;
  else if(c.second == findType) return c.first;
  else if(d.second == findType) return d.first;
  else if(e.second == findType) return e.first;
  else return n;
}

bool isSolution(int arr[6]){
  int triN = sqrt(1+8*arr[0]);
  int sqN = sqrt(arr[1]);
  int pentN = sqrt(1+24*arr[2]);
  int hexN = sqrt(1+8*arr[3]);
  int heptN = sqrt(9+40*arr[4]);
  int octN = sqrt(1+3*arr[5]);
  if(triN == sqN || triN == pentN || triN == hexN || triN == heptN || triN == octN || sqN == pentN || hexN == sqN || heptN == sqN || octN == sqN || pentN == hexN || pentN == heptN || pentN == octN || hexN == heptN || hexN == octN || heptN == octN) return false;
  return true;
}

void bruteforce(){
  // filling polygonmaps through our well defined function
  fillMap(45, 141, 3);
  fillMap(32, 100, 4);
  fillMap(26, 82, 5);
  fillMap(23, 71, 6);
  fillMap(21, 64, 7);
  fillMap(19, 59, 8);

  bool run = true;
  int ans = 0;

  for(int i=0;i<nums.size() && run;++i){
	int n = nums[i];
	for(auto v: firstTwoDigitMap[n%100]){
	  if(v.first == n) continue;
	  for(auto w: firstTwoDigitMap[v.first%100]){
		if(w.first == n || w.first == v.first) continue;
		// if(w.second == v.second) continue;
		for(auto x: firstTwoDigitMap[w.first%100]){
		  if(x.first==w.first || x.first==v.first || x.first==n) continue;
		  // if(x.second == w.second || x.second == v.second) continue;
		  for(auto y: firstTwoDigitMap[x.first%100]){
			if(y.first==x.first || y.first == w.first || y.first == v.first || y.first == n) continue;
			// if(y.second == x.second || y.second == w.second || y.second == v.second) continue;
			for(auto z: firstTwoDigitMap[y.first%100]){
			  if(z.first==y.first||z.first==x.first||z.first==w.first||z.first==v.first||z.first==n) continue;
			  // if(z.second == y.second || z.second == x.second || z.second == w.second || z.second == v.second) continue;
			  if(z.first%100 == (n-n%100)/100){
				if(z.second != y.second && z.second != x.second && z.second != w.second && z.second != v.second && y.second != x.second && y.second != w.second && y.second != v.second && x.second != w.second && x.second != v.second && w.second != v.second){
				  int arr[6] = {0, 0, 0, 0, 0, 0};
				  for(int i=0;i<6;++i){
					if(i == 0) arr[i] = SendNumFromType('T', v, w, x, y, z, n);
					if(i == 1) arr[i] = SendNumFromType('S', v, w, x, y, z, n);
					if(i == 2) arr[i] = SendNumFromType('P', v, w, x, y, z, n);
					if(i == 3) arr[i] = SendNumFromType('H', v, w, x, y, z, n);
					if(i == 4) arr[i] = SendNumFromType('7', v, w, x, y, z, n);
					if(i == 5) arr[i] = SendNumFromType('O', v, w, x, y, z, n);
				  }
				  if(isSolution(arr)){
					ans = n+v.first+w.first+x.first+y.first+z.first;
					// cout <<  n << " " << v.first << " " << w.first << " " << x.first << " " << y.first << " " << z.first << nl;
					cout << ans << "\n"; // correct answer is 28684
					// cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << " " << arr[5] << nl;
					// run = false;
					// break;
				  }
				}
			  }
			}
		  }
		}
	  }
	}
  }

  // cout << ans << "\n";
}

int main(){
  bruteforce();
  return 0;
}
