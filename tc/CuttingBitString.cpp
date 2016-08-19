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

class CuttingBitString
{
	string source;
public:
	
	inline ll toInt(string s) {
	    ll ans = 0;
	    ll tmp = 1;
	    for (ll i = s.size()-1; i >= 0; --i) {
	    	ans += (s[i]-'0')*(tmp);
	    	tmp = tmp << 1;
	    }
	    return ans;
	}
	bool isValid(int i,int j) {
		if(source[i] == '0') return false;
		ll val = toInt(source.substr(i,j-i+1));
		if(val == 0) return false;
		while(val % 5 == 0) {
			val /= 5;
		}
		return (val == 1 ? true : false);
	}
	int getmin(string s) {
		source = s;
		int dp[55][55];
		for (int i = 0; i < 55; ++i) {
			for (int j = 0; j < 55; ++j) {
				if(i <= j) dp[i][j] = INT_MAX;
				else dp[i][j] = 0;
			}
		}
		for (int d = 0; d < s.size(); ++d) {
			for (int i = 0; i + d < s.size(); ++i) {
				for (int j = 0; i + j <= i+d; ++j) {
					if(isValid(i,i+j) && dp[i+j+1][i+d] != INT_MAX) {
						dp[i][i+d] = min(dp[i][i+d],1+dp[i+j+1][i+d]);
					}
				}
			}
		}
		return (dp[0][s.size()-1] == INT_MAX ? -1 : dp[0][s.size()-1]);
	}
};