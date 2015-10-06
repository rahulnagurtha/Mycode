#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL arr[100005],asum[100005],ssum[100005],n,q,type,l,r;

void preprocess() {
	for (int i = 1; i <= n; ++i) {
		asum[i] = asum[i-1]+arr[i];
	}
	sort(arr+1,arr+n+1);
	for (int i = 1; i <= n; ++i) {
		ssum[i] = ssum[i-1]+arr[i];
	}
	return;
}

void solve() {
	cin >> q ;
	for (int i = 0; i < q; ++i) {
		cin >> type >> l >> r ;
		if(type == 1) printf("%I64d\n",asum[r]-asum[l-1]);
		else printf("%I64d\n",ssum[r]-ssum[l-1]);
	}
	return;
}


// main code begins now

int main()
{
    cin >> n ;
    for (int i = 1; i <= n; ++i) {
    	cin >> arr[i];
    }
    preprocess();
    solve();
    return 0;
}