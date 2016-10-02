#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	string front,back,lft,ryt,up,down;
    	int ans = 0;
    	cin >> front >> back >> lft >> ryt >> up >> down;
    	if( front == lft && front == up) ans++;
    	if( front == lft && front == down) ans++;
    	if( front == ryt && front == up) ans++;
    	if( front == ryt && front == down) ans++;
    	if( back == lft && lft == up) ans++;
    	if( back == lft && down == lft) ans++;
    	if( ryt == back && ryt == up) ans++;
    	if( ryt == back && ryt == down) ans++;
    	if(ans < 1) cout << "NO" << endl;
    	else cout << "YES" << endl;
    }
    return 0;
}