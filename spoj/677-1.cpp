#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void sieve() {
	bool prime[1005] = {true};
	for (int i = 2; i < 1001; ++i) {
		if(prime[i]) {
			primes.push_back(i);
			for (int j = 1; j*i <= 1000; ++j) {
				prime[i*j] = false;
			}
		}
	}
	return;
}

inline string toString(int i) {
    string s;
    stringstream ss;
    ss<<i;
    ss>>s;
    return s;
}



class PalindromePrime
{
	sieve();
public:
	int count(int n) {
		int ans = 0;
		string one,two;
		for (int i = 0; i < 168; ++i) {
			if(primes[i] >= L && primes[i] <= R) {
				one = toString(primes[i]);
				two = one;
				reverse(one.begin(),one.end());
				if(one == two) ans++;
			}
		}
		return ans;
	}
	
};