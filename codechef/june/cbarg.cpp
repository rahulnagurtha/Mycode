#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	long long int n,tmp,cur = 0,ranswer = 0;
    	cin >> n ;
    	for (long long int i = 0; i < n; ++i) {
    		cin >> tmp;
    		if(cur < tmp) ranswer += tmp-cur;
    		cur = tmp;
    	}
    	cout << ranswer << endl;
    }
    return 0;
}