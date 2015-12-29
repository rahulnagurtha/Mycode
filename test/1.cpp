#include <bits/stdc++.h>

using namespace std;



class PalindromePrime
{
public:
	vector<int> primes;

void sieve() {
	bool prime[1005];
	for(int i = 0; i < 1001;i++) {
        prime[i] = true;
	}
	for (int i = 2; i < 1001; ++i) {
        cout << prime[i] << " ";
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
	int count(int L,int R) {

		sieve();
		cout << "primes size is " <<primes.size() << endl;
		int ans = 0;
		string one,two;
		for (int i = 0; i < primes.size(); ++i) {
                cout << primes[i] << "->";
			if(primes[i] >= L && primes[i] <= R) {
				one = toString(primes[i]);
				two = one;
				reverse(one.begin(),one.end());
				cout << "checking if " << one << " == " << two << endl;
				if(one == two) ans++;
			}
		}
		return ans;
	}

};


int main()
{
    PalindromePrime test;
    cout << test.count(1,9);
    return 0;
}
