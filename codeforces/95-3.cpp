#include <bits/stdc++.h>

using namespace std;


typedef long long int LL;

#define rows		32
#define columns		32

//dp[i][j] indicates J choose I

LL dp[rows][columns],b,g,t,answer;


void precalculate() {
	for (int i = 0; i <= 32; ++i) dp[i][0] = 1;
	for (int i = 1; i <= 32; ++i) {
		for (int j = 1; j <= i ; ++j) {
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
		}
	}
	return;
}

void solve() {
	LL one,two,p;
	p = t - 5;
	answer = 0;
	for (LL i = 0; i <= p; ++i) {
		one = ((b >= 4 + i) ? dp[b][4+i] : 0 );
		two = ((g >= 1 + p - i) ? dp[g][1+p-i] : 0 ); 
		answer += one*two;
	}
	cout << answer << endl ;
}



// main code begins now

int main()
{
    precalculate();
    cin >> b >> g >> t;
    solve();
    return 0;
}