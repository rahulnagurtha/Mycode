#include <bits/stdc++.h>

using namespace std;

string one;
int n,k;

int changeones() {
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		if(one[i] == 'a') v[i] = 0;
		else v[i] = 1;
		v[i] = v[i]^1;
	}
	int start = 0;
	int end = 0;
	int solstart, solend;
	int cursum = 0;
	int res = 0;
	while(end < n) {
		cursum+=v[end];
		while(cursum > k && start<=end){
				cursum-=v[start++];
		}
		if(res < end - start + 1) {
			solstart = start;
			solend = end;
			res = end - start + 1;
		}
		end++;
	}
	return res;
}

int changezeroes() {
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		if(one[i] == 'a') v[i] = 1;
		else v[i] = 0;
		v[i] = v[i]^1;
	}
	int start = 0;
	int end = 0;
	int solstart, solend;
	int cursum = 0;
	int res = 0;
	while(end < n) {
		cursum+=v[end];
		while(cursum > k && start<=end){
				cursum-=v[start++];
		}
		if(res < end - start + 1) {
			solstart = start;
			solend = end;
			res = end - start + 1;
		}
		end++;
	}
	return res;
}


int main()
{
	cin>>n>>k;
	cin >> one;
	int ans = 0;
	ans = max(ans,changezeroes());
	ans = max(ans,changeones());
	cout << ans << endl;
	return 0;
}