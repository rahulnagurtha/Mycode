#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n,m,k,tmp,tmp1,tmp2,tmp3;
LL apps[100005],position[100005],cnt;

void solve(LL a) {
	tmp1 = position[a];
	if(tmp1 % k == 0) {
		cnt += tmp1/k;
	}
	else {
		cnt += 1 + tmp1/k;
	}
	if(tmp1 != 1) {
		position[a] -= 1;
		position[apps[tmp1-1]] += 1;
		swap(apps[tmp1],apps[tmp1-1]);
	}
}


// main code begins now

int main()
{
	cnt = 0;
    cin >> n >> m >> k;
    for (LL i = 1; i <= n; ++i) {
    	cin >> apps[i] ;
    	position[apps[i]] = i;
    }
    for (LL i = 0; i < m; ++i) {
    	cin >> tmp ;
    	solve(tmp);
    }
    cout << cnt ;
    return 0;
}