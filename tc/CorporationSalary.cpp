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

class CorporationSalary
{
private:
	int inEdges[50];
public:
	ll dfs(int cur) {
		ll ans = 0;
		for (int i = 0; i < relations[cur].size(); ++i) {
			if(relations[cur][i] == 'Y') ans += dfs(i);
		}
		if(ans == 0) ans = 1;
		return ans;
	}
	ll totalSalary(VS relations) {
		for (int i = 0; i < relations.size(); ++i) {
			for (int j = 0; j < relations.size(); ++j) {
				inEdges[j] += (relations[i][j] == 'Y' ? 1 : 0);
			}
		}
		for (int i = 0; i < relations.size(); ++i) {
			if(!inEdges[i]) return dfs(i);
		}
	}
};