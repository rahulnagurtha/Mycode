#include <bits/stdc++.h>

using namespace std;


// main code begins now

int main()
{
	int n,num[15],tmp,curnum,curans,ans;
	ans = 1;
	cin >> n ;
	for (int i = 0; i < n; ++i) {
		cin >> num[i] ;
	}
	tmp = 1 << n;
    //finding all subsets of a set
    for (int i = 1; i < tmp; i++) {
    	curnum = -1;
    	curans = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) {
            	if(curnum < num[j]) {
            		curans++;
            		curnum = num[j];
            	}
			}
		}
		if(curans > ans) ans = curans;
    }
    printf("%d\n",ans);
    return 0;
}