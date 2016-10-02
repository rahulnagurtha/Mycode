#include <bits/stdc++.h>

using namespace std;

class NumberofFiboCalls
{
	
public:
	vector <int> fiboCallsMade(int n) {
		vector<int> count;
		vector<int> one;
		vector<int> two;
		int a[51][2];
		count.reserve(2);
		one.reserve(2);
		two.reserve(2);
		one[0] = 1;
		one[1] = 0;
		two[0] = 0;
		two[1] = 1;
		if(n == 1) return two;
		else if(n==0) return one;
		else {
			a[0][0] = 1;
			a[0][1] = 0;
			a[1][0] = 0;
			a[1][1] = 1;
			for (int i = 2; i <= n ; ++i) {
				a[i][0] = a[i-1][0] + a[i-2][0] ;
				a[i][1] = a[i-1][1] + a[i-2][1] ;
			}
			count[0]=a[n][0];
			count[1]=a[n][1];
			printf("returning %d,%d\n",count[0],count[1]);
			return count;
		}

	}
	
};
