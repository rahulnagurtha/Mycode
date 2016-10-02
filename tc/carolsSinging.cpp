#include <bits/stdc++.h>

using namespace std;

class CarolsSinging
{
public:
	int ans;
	int bitsSet(int key) {
		int ret = 0;
		while(key > 0) {
			if(key%2 == 1) ret++;
			key /= 2;
		}
		return ret;
	}
	int choose(vector<string> lyrics) {
		ans = 50;
		for (int config = 0; config < (1 << lyrics[0].size()) ; ++config) {
			bool visit[42] = {false};
			for (int bitNum = 0; bitNum < lyrics[0].size(); ++bitNum) {
				if((1 << bitNum) & config) {
					for (int k = 0; k < lyrics.size(); ++k) {
						if(lyrics[k][bitNum] == 'Y') {
							visit[k] = true;
						}
					}
				}
			}
			bool coverAll = true;
			for (int member = 0; member < lyrics.size(); ++member) {
				if(!visit[member]) {
					coverAll = false;
					break;
				}
			}
			if(coverAll) {
				ans = min(ans,bitsSet(config));
			}
		}
		return ans;
	}
};