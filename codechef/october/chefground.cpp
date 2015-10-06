#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

	
int main()
{
	int test;
	cin >> test ;
	while(test--) {
		int n,m,max=-5,sum=0;
		int a[105];
		cin >> n >> m ;
		for (int i = 0; i < n; ++i) {
			cin >> a[i] ;
			if(a[i]>max) max=a[i];
		}
		for (int i = 0; i < n; ++i) {
			sum+=abs(a[i]-max);
		}
		if((m-sum)>=0 && ((m-sum)%n)==0) cout << "Yes" << endl ;
		else cout << "No" << endl ;

	}
	return 0;
}