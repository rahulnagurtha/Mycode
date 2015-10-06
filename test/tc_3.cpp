#include <bits/stdc++.h>

using namespace std;


void dsequence(vector<int>& v) {
	int size;
	size=v.size();
	for (int i = 0; i < size-1; ++i) {
		v[i]=v[i+1]-v[i];
	}
	v.pop_back();
}


// main code begins now

int main()
{
    int t;
    freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int size,temp,order;
    	vector<int> num;
    	cin >> size >> order ;
    	for (int i = 0; i < size; ++i) {
    		cin >> temp ;
    		num.push_back(temp);
    	}
    	for (int i = 0; i < order; ++i) {
    		dsequence(num);
    	}
    	size=num.size();
    	for (int i = 0; i < size; ++i) {
    		cout << num[i] << " " ;
    	}
    	printf("\n");
    }
    return 0;
}