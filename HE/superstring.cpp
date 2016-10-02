#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        string ans;
    	int n,k;
    	bool present[30] = {false};
    	string tmp;
    	cin >> n >> k;
    	cin >> tmp;
    	for(int i = 0;i < tmp.size(); i++) {
    		present[tmp[i] - 'a'] = true;
    	}
    	for(int i = 0;i < 26; i++) {
    		if(present[i]) {
    			if(k > 1) cout << (char)('a' + i) << endl;
    			else {
                    if(tmp[0] == (char)('a' + i)) ans = (char)('a' + i);
    				for (int j = 0; j < tmp.size(); ++j) {
                        if(ans.size() == 0) {
                            ans = tmp.substr(j,tmp.size());
                        }
                        else {
                            if(tmp.substr(j,tmp.size()) < ans) ans = tmp.substr(j,tmp.size());
                        }
                    }
                    cout << ans << endl;
    			}
    			break;
    		}
    	}
    }
    return 0;
}