#include <bits/stdc++.h>

using namespace std;


#define MAX 100000

// main code begins now

int main()
{
    int numbers[MAX+5],n;
    vector<int> A;
    vector<int>::iterator low;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
    	scanf("%d",&numbers[i]);
    }
	A.push_back(numbers[0]);
    for (int i = 1; i < n; ++i) {
    	low = lower_bound(A.begin(), A.end(),numbers[i]);
    	if(low == A.end()) A.push_back(numbers[i]);
    	else A[low- A.begin()] = numbers[i];
    }
    printf("%d\n",A.size());
    return 0;
}