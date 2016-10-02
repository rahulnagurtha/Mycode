#include <bits/stdc++.h>

using namespace std;

// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int n,a[100005],temp,max=0,count,ans;
    	memset(a,-1,sizeof(a));
    	cin >> n ;
    	for (int i = 0; i < n; ++i) {
    		cin >> temp ;
    		a[temp]++;
    	}
    	ans=n-1;
    	for (int i = 0; i < n; ++i) {
    		if (a[i]>max) {
    			max=a[i];
    		}
    	}
    	ans=ans-max;
    	cout << ans << endl ;
    }
    return 0;
}