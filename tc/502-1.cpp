#include <bits/stdc++.h>

using namespace std;

class FoxProgression
{
public:
	int theCount(vector <int> seq) {
		int ans = 0;
		if(seq.size() == 1) ans = -1;
		if(seq.size() == 2) {
			if(seq[1] % seq[0] == 0 && seq[1]*seq[1]/seq[0] != seq[1] + (seq[1] - seq[0])) ans = 2;
			else ans = 1;
		}
		else {
			int r,d,ans1 = INT_MIN;
			if(seq[1] % seq[0] == 0) {
				r = seq[1]/seq[0];
				for (int i = 1; i < seq.size(); ++i) {
					if(seq[i] == seq[i-1]*r) {
						if(i == seq.size() - 1) ans1 = seq[i]*r;
					}
					else break;
				}
			}
			if(ans1 != INT_MIN) ans++;
			d = seq[1] - seq[0];
			for (int i = 1; i < seq.size(); ++i) {
				if(seq[i] == seq[i-1] + d) {
					if(i == seq.size() - 1 && seq[i] + d != ans1) {
						ans++;
					}
				}
				else break;
			}
		}
		return ans;
	}
};


int main() {
	FoxProgression test;
	vector<int> seq;
	seq.push_back(1);
	seq.push_back(1);
	cout << test.theCount(seq) << endl;
}