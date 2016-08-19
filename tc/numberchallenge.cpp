#include <bits/stdc++.h>

using namespace std;

bool status[20000002];


class NumbersChallenge
{
	int sum1,ans,te;
	vector <int> bags;
	vector <int> tobepushed;
public:
	int MinNumber(vector <int> S) {
		sort(S.begin(),S.end());
		bags.push_back(0);
		sum1 = 0 ;
 		for (int i = 0; i < S.size(); ++i) {
 			sum1+=S[i];
 		}
		for (int i = 0; i < S.size(); ++i) {
			te = bags.size();
			for (int j = 0; j < te; ++j) {
				if(status[bags[j]+S[i]] == false){
					status[bags[j]+S[i]] = true;
					bags.push_back(bags[j]+S[i]);
				}
			}
		}

		for (int i = 1; i <= sum1 + 1; ++i) {
			if(status[i]==false) {
				ans = i;
				break;
			}
		}
		return ans;

	}

};


int main()
{
	NumbersChallenge test;
	vector<int> s;
	int n,ans,temp;
	cin >> n ;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp ;
		s.push_back(temp);
	}
	ans = test.MinNumber(s);
	cout << ans << endl ;
	return 0;
}