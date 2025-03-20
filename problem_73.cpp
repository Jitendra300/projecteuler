#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl "\n"

int SIZE; // extra +1 for safety // also this isn't size this is the largest denominator we can have....
ll farey[12002];
ll phin[12002];

ll  phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	SIZE = 12000;
	
	farey[0] = 0;
	farey[1] = 2;

	phin[0]=0;
	phin[1] = 1;

	for(int i=2;i<=SIZE;++i){
	  phin[i] = phi(i);
	  farey[i] = farey[i-1]+phin[i];
	}

	cout << (farey[SIZE])/6 << nl; // answer would be very near to this.....
	return 0;
}
