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

class TheMatrix
{
	int dp[105][105];
	int N;
public:
	void fillDp(VS board) {
		N = board.size();
		for (int i = 0; i < board[0].size(); ++i) {
			dp[N-1][i] = 1;
		}
		for (int i = N-2; i >= 0; --i) {
			for (int j = 0; j < board[0].size(); ++j) {
				dp[i][j] = 1;
				if(board[i][j] != board[i+1][j]) dp[i][j] += dp[i+1][j];
			}
		}
		return;
	}
	int MaxArea(VS board) {
		int ans = 0;
		fillDp(board);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				int curMin = dp[i][j];
				ans = max(ans,curMin);
				for (int k = j + 1; k < board[i].size(); ++k) {
					if(board[i][k-1] == board[i][k]) break;
					curMin = min(curMin,dp[i][k]);
					ans = max(ans,(k-j+1)*curMin);
				}
			}
		}
		return ans;
	}	
};

int main()
{
	freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		VS board;
		string tmp;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			board.pb(tmp);
		}
		TheMatrix test;
		cout << test.MaxArea(board) << endl;
	}
	return 0;
}