#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n,temp;
vector<pair<LL,LL> > numbers;
LL answer[300005];

void solve() {
	temp = numbers[0].first + 1;
	answer[numbers[0].second] = numbers[0].first;
	for (int i = 1; i < n; ++i) {
		if(numbers[i].first >= temp) {
			answer[numbers[i].second] = numbers[i].first;
			temp = numbers[i].first+1;
		}
		else {
			answer[numbers[i].second] = temp;
			temp++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%I64d ",answer[i]);
	}
	return;
}

// main code begins now

int main()
{
    scanf("%I64d",&n);
    for (LL i = 1; i <= n; ++i) {
    	scanf("%I64d",&temp);
    	numbers.push_back(make_pair(temp,i));
    }
    sort(numbers.begin(),numbers.end());
    solve();
    return 0;
}