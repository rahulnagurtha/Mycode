#include <bits/stdc++.h>

using namespace std;


class ColorfulRoad
{
	int temp,temp1,flag,minimum,last,tocheck;
	string totest;
	char test[3];
public:
	int getMin(string road) {
		minimum = 1000000;
		test[0] = 'R';
		test[1] = 'G';
		test[2] = 'B';
		temp = 1 << road.size();
		//finding all subsets of a set
		for (int i = 1; i < temp ; i++) {
			if ( (i & 1 )  &&  (i & temp/2 ) ) {
			    totest = "";
			    tocheck = 0;
			    // printf("checking \n");
			    for (int j = 0; j < road.size(); j++) {
			        if (i & (1 << j)) { // Check whether or not to include the j-th element
			        	totest += road[j]; // Get sum of all included elements			
						if(j!=0) tocheck += (j-last)*(j-last);
						last = j;
						// cout << road[j] ;
					}
				}
				// printf("\n");
				temp1 = 0;
				flag = 1;
				for (int i = 0; i < totest.size(); ++i) {
					if(totest[i] != test[temp1]) flag = 0 ;
					temp1++;
					temp1 = temp1 % 3 ;
				}
				if(flag==1) minimum = min(minimum,tocheck);
			}
		}

		if(minimum >=1000000) return -1;
		else return minimum;
	}
	
};

int main()
{
	ColorfulRoad test;
	int ans;
	string s;
	cin >> s ;
	ans = test.getMin(s);
	cout << ans ;
}