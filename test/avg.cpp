#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

int main() {
	int t; cin >> t;
	while(t-->0) {
		int n,i,a[107],sum=0,avg,res=0; cin >> n;
		for (i = 0; i <n; ++i)
		{
			cin >> a[i];
			sum += a[i];
		}
		avg = sum/n;
		for(i=0;i<n;i++) {
			if(a[i]>avg) res++;
		}

		cout << res << "\n";




	}
	
return 0;	
}