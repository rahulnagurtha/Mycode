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

class WinterAndCandies
{
public:
	int getNumber(VI type) {
		int ans = 0;
		int typeCount[55] = {0};
		for (int i = 0; i < ; ++i) {
			typeCount[type[i]]++;
		}
		int tmp = 1;
		for (int i = 1; i <= type.size(); ++i) {
			tmp = tmp*typeCount[i];
			ans += tmp;
		}
		return ans;
	}
};