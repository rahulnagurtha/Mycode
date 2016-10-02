#include <bits/stdc++.h>

using namespace std;

#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};

class AlienAndGame
{
	int dp[2][55][55];
public:
	void preprocess(VS board) {
		fill(dp,0);
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				dp[0][i][j] = ( j-1 >= 0 ? dp[0][i][j-1] : 0);
				dp[1][i][j] = ( j-1 >= 0 ? dp[1][i][j-1] : 0);
				if(board[i][j] == 'W') dp[0][i][j]++;
				else dp[1][i][j]++;
			}
		}
		return;
	}
	bool possible(int x1,int y1,int y2) {
		return (y1 == 0 ? (dp[0][x1][y2] == 0||dp[1][x1][y2] == 0) : ((dp[0][x1][y2] == dp[0][x1][y1-1]) || (dp[1][x1][y2] == dp[1][x1][y1-1])));
	}
	int getNumber(vector<string> board) {
		preprocess(board);
		bool canChange = true;
		int ans = 0;
		for (int d = 0; d < 51; ++d) {
			for (int i = 0; i+d < board.size(); ++i) {
				for (int j = 0; j+d < board[i].size(); ++j) {
					canChange = true;
					for (int k = 0; k <= d; ++k) {
						if(!possible(i+k,j,j+d)) canChange = false; 
					}
					if(canChange) ans = d+1;
				}
			}
		}
		return ans*ans;
	}
};