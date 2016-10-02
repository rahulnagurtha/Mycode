#include <bits/stdc++.h>

using namespace std;


// main code begins now

int main()
{
    int n,m,temp = 1000000;
    int dp[100005],a[100005],l[100005];
    bool status[100005];
    for (int i = 0; i <= 100005; ++i) {
    	status[i] = false;
    }
    cin >> n >> m ;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i] ;
    }
    for (int i = 1; i <= m; ++i) {
    	cin >> l[i] ;
    }
    for (int i = 1; i <= m; ++i) {
    	if(l[i] < temp) temp = l[i];
    }
    dp[n+1] = 0;
    for (int i = n; i >= temp; --i) {
    	if(status[a[i]] == false) {
    		dp[i] = dp[i+1] + 1;
    		status[a[i]] = true;
    	}
    	else dp[i] = dp[i+1];
    }
    for (int i = 1; i <= m; ++i) {
    	printf("%d\n",dp[l[i]]);
    }
    return 0;
}