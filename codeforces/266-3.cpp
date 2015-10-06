#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n,num[500005],sum = 0,req,answer = 0,temp1;
vector<LL> lef;
deque<LL> ri;


// main code begins now

int main()
{
    cin >> n ;
    for (LL i = 1; i <= n; ++i) {
    	cin >> num[i];
    }
    for (LL i = 1; i <= n; ++i) {
    	sum += num[i];
    }
    if(sum%3 != 0) {
    	printf("0\n");
    	return 0;
    }
    req = sum/3;
    sum = 0;
    for (LL i = 1; i <= n; ++i) {
    	sum += num[i];
    	if(sum == req) lef.push_back(i);
    }
    sum = 0;
    for (LL i = n; i > 0; --i) {
    	sum += num[i];
    	if(sum == req) ri.push_front(i);
    }

    temp1 = 0;
    //do the required calculation from data
    for (LL i = 0; i < lef.size(); ++i) {
    	for (LL j = temp1; j < ri.size(); ++j) {
    		if(ri[j]-lef[i] > 1) {
    			answer += ri.size()-j;
    			temp1 = j;
    			break;
    		}
    	}
    }
    cout << answer ;
    return 0;
}