#include <bits/stdc++.h>

using namespace std;

int n;
int a[50];
int dp[50][100][100][100];
int x,y,z;


int recurse(int idx,int i,int j,int k) {
	// cout << idx << " " << i << " " << j << " " << k << endl;
	if((dp[idx][i][j][k] != -1) || (idx >= 47)) {
		return 0;
	}
	x = max(x,i);y = max(y,j);z = max(z,k);
	dp[idx][i][j][k] = 0;
	if((i > 0) && (j > 0)) return recurse(idx,i-1,j-1,k + 1) + recurse(idx+1,j,k,a[idx+3]);
	else return recurse(idx + 1,j,k,a[idx + 3]);
}

int main()
{
	memset(dp,-1,sizeof(dp));
    for (int i = 0; i < 50; ++i) {
    	a[i] = 50;
    }
    recurse(0,50,50,50);
    cout << x << " " << y << " " << z << endl;
    return 0;
}