#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL students[100005],n,price[100005];

void solve() {
	LL answer = 0;
	sort(students,students+n);
	sort(price,price+n);
	for (int i = 0; i < n; ++i) {
		answer += students[i]*price[n-i-1];
	}
	cout << answer << endl;
}


// main code begins now

int main()
{
    while(1) {
    	cin >> n ;
    	if(n == 0) break;
    	for (int i = 0; i < n; ++i) {
    		cin >> students[i] ;
    	}
    	for (int i = 0; i < n; ++i) {
    		cin >> price[i] ;
    	}
    	solve();
    }
    return 0;
}