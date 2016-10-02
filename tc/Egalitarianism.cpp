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

class Egalitarianism
{
public:
	int maxDifference(VS isFriend,int d) {
		int dp[105][105];
		fill(dp,-1);
		for (int i = 0; i < isFriend.size(); ++i) {
			for (int j = 0; j < isFriend.size(); ++j) {
				if(isFriend[i][j] == 'Y') dp[i][j] = 1;
			}
		}
		for (int k = 0; k < isFriend.size(); ++k) {
			for (int i = 0; i < isFriend.size(); ++i) {
				for (int j = 0; j < isFriend.size(); ++j) {
					if(dp[i][k] != -1 && dp[k][j] != -1) {
						if(dp[i][j] ==  -1)
	                    	dp[i][j] = dp[i][k] + dp[k][j];
						else if(dp[i][j] > dp[i][k] + dp[k][j])
		                    dp[i][j] = dp[i][k] + dp[k][j];
					}
				}
			}
		}
		for (int i = 1; i < isFriend.size(); ++i) {
			if(dp[0][i] == -1) return -1;
		}
		int ans = -1;
	    for(i = 0; i < isFriend.size(); i++)
	        for(j = i + 1; j < isFriend.size(); j++)
	            ans = max(ans, dp[i][j]);
	    return ans * d;
	}
};