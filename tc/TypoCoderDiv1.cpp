#include <bits/stdc++.h>

using namespace std;


#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)

typedef long long int ll;
typedef vector<int> VI;

class TypoCoderDiv1
{
public:
	int dp[2205][55];
	vector<int> possibleRating;
	void init() {
		for (int i = 0; i < 2205; ++i) {
			for (int j = 0; j < 55; ++j) {
				dp[i][j] = -1;				
			}
		}
		return;
	}
	int maxChanges(int curRating,int idx) {
		if(curRating >= 2200) {
			if(idx == possibleRating.size() - 1 ) {
				if(curRating-possibleRating[idx] < 2200) return 1;
				else return 0;
			}
			else {
				if(curRating-possibleRating[idx] < 2200) return 1 + maxChanges(max(0,curRating-possibleRating[idx]),idx+1);
				else return 0;
			}
		}
		else {
			if(dp[curRating][idx] != -1) return dp[curRating][idx];
			dp[curRating][idx] = 0;
			if(idx == possibleRating.size() - 1 ) {
				if(curRating+possibleRating[idx] >= 2200) dp[curRating][idx] = 1;
				else dp[curRating][idx] = 0;
			}
			else {
				if(curRating+possibleRating[idx] >= 2200 && curRating+possibleRating[idx]-possibleRating[idx+1] < 2200) dp[curRating][idx] = 1;
				dp[curRating][idx] += maxChanges(curRating+possibleRating[idx],idx+1);
				dp[curRating][idx] = max(dp[curRating][idx],maxChanges(max(0,curRating-possibleRating[idx]),idx+1));
			}
			return dp[curRating][idx];
		}
	}
	int getmax(vector<int> D, int X) {
		init();
		possibleRating = D;
		return maxChanges(X,0);
	}
};