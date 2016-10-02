#include <bits/stdc++.h>

using namespace std;


// main code begins now

int main()
{

	int temp[4],length;
	long long int sum=0;
	vector<int> a,b,c,d,one,two;
    cin >> length ;
    for (int i = 0; i < length; ++i) {
    	cin >> temp[0] >> temp[1] >> temp[2] >> temp[3] ;
    	a.push_back(temp[0]);
    	b.push_back(temp[1]);
    	c.push_back(temp[2]);
    	d.push_back(temp[3]);
    }
    for (int i = 0; i < length; ++i) {
    	for (int j = 0; j < length ; ++j) {
    		one.push_back(a[i]+b[j]);
    	}
    }
    // sort (one.begin(), one.end());
    for (int i = 0; i < length; ++i) {
    	for (int j = 0; j < length ; ++j) {
    		two.push_back(c[i]+d[j]);
    	}
    }
    sort (two.begin(), two.end());
    for (int i = 0; i < one.size(); ++i) {
    	if(binary_search (two.begin(), two.end(),-(one[i]) )) sum++;
    }
    cout << sum << endl ;
    return 0;
}