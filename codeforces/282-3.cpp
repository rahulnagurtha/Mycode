#include <bits/stdc++.h>

using namespace std;


// main code begins now

int main()
{
    string A,newstring;
    bool status;
    int left = 0,right = 0,lastindex = INT_MAX,cnt = 0,toadd = 0;
    vector<int> solution;
    cin >> A;
    for (int i = 0; i < A.size(); ++i) {
    	if(A[i] == '#') {
    		cnt++;
    		lastindex = i;
    		A[i] = ')';
			right++;
			solution.push_back(1);
		}
		else if(A[i] == '(') left++;
		else right++;
    }
    if(lastindex != INT_MAX) {
    	newstring = A.substr(0,lastindex+1);
    	for (int i = 0; i < left-right; ++i) {
    		newstring += ')';
    	}
    	newstring += A.substr(lastindex+1);
    	solution[solution.size()-1] = left-right+1;
    }
    else {
    	newstring = A;
    }
    // cout << newstring << endl;
    left = right = 0;
    for (int i = 0; i < newstring.size(); ++i) {
    	if(newstring[i] == '(') left++;
    	else right++;
    	if(left < right) {
    		printf("-1\n");
    		return 0;
    	}
    }
    for (int i = 0; i < solution.size(); ++i) {
    	printf("%d\n",solution[i]);
    }
    return 0;
}