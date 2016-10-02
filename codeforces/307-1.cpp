#include <bits/stdc++.h>

using namespace std;




// main code begins now

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    int rank[4005];
    int a[4005];
    int tbs[4005];
    cin >> n ;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] ;
        tbs[i] = a[i];
    }
    sort(tbs+1,tbs+n+1,greater<int>());
    rank[tbsn[1]] = 1;
    for (int i = 2; i <= n; ++i) {
    	if(tbs[i] != tbs[i-1]) {
    		rank[tbs[i]] = i;
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	printf("%d ",rank[a[i]]);
    }
    printf("\n");
    return 0;
}