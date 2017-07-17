#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n,p;
    cin >> n;
    vector<int> primes;
    for (int i = 0; i < n; ++i) {
    	cin >> p;
    	primes.push_back(p);
    }
    vector<pair<int,int> > rem;
    vector<int> ans;
    for (int i = 0; i < primes.size(); ++i) {
    	rem.push_back(make_pair(1,1));
    	ans.push_back(-1);
    }
    for (int i = 3; i <= 1000000; ++i) {
    	for (int j = 0; j < rem.size(); ++j) {
    		int cur = (rem[j].first + rem[j].second) % primes[j];
    		if((cur == 0) && (ans[j] == -1)) {
    			ans[j] = i;
    		}
    		rem[j].first = rem[j].second;
    		rem[j].second = cur;	
    	}
    }
    for (int i = 0; i < ans.size(); ++i) {
    	cout << ans[i] << endl;	
    }
    return 0;
}