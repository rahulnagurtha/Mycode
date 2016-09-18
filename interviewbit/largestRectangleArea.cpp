#include <bits/stdc++.h>

using namespace std;


#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif


int largestRectangleArea(vector<int> &A) {
	vector<int> lftNearestSmall;
	vector<int> rytNearestSmall;
	int ans = 0;
	int base;
	int lft,ryt;
	stack<int> T;
	for (int i = 0; i < A.size(); ++i) {
		lftNearestSmall.push_back(-1);
		rytNearestSmall.push_back(A.size());
	}
	//calculate lftNearestSmall
	for (int i = A.size()-1; i >= 0; --i) {
		while(!T.empty() && A[T.top()] > A[i]) {
			lftNearestSmall[T.top()] = i;
			T.pop();

		}
		T.push(i);
	}
	while(!T.empty()) T.pop();
	//calculate rytNearestSmall
	for (int i = 0; i < A.size(); ++i) {
		while(!T.empty() && A[T.top()] > A[i]) {
			rytNearestSmall[T.top()] = i;
			T.pop();
		}
		T.push(i);
	}
	cout << lftNearestSmall << endl;
	cout << rytNearestSmall << endl;
	//check all possible cases
	for (int i = 0; i < A.size(); ++i) {
		if(lftNearestSmall[i] != i) lft = lftNearestSmall[i] + 1;
		else lft = lftNearestSmall[i];
		if(rytNearestSmall[i] != i) ryt = rytNearestSmall[i] - 1;
		else ryt = rytNearestSmall[i];
		cout << A[i] << " <> " << A[lft] << " to " << A[ryt] << endl;
		ans = max((ryt - lft + 1)*A[i],ans);
	}
	return ans;
}







int main()
{
    vector<int> test;
    int n,tmp;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	cin >> tmp;
    	test.push_back(tmp);
    }
    cout << largestRectangleArea(test) << endl;
    return 0;
}