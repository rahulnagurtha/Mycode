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

class CasketOfStar
{
public:
	int maxEnergy(VI weight) {
		int dp[505][505];
		for (int d = 1; d < weight.size()-1; ++d) {
			for (int i = 0; i+d < weight.size(); ++i) {
				dp[i][i+d] = 0;
				for (int j = i + 1; j < i + d; ++j) {
					dp[i][i+d] = max(dp[i][i+d],dp[i][j] + dp[j][i+d] + weight[i]*weight[i+d]);
				}
			}
		}
		return dp[0][weight.size()-1];
	}
};

int main()
{
    freopen("in.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) {
		int n;
		in tmp;
		VI weight;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> tmp;
			weight.pb(tmp);
		}
		CasketOfStar test;
		cout << test.maxEnergy(weight) << endl;
	}
}