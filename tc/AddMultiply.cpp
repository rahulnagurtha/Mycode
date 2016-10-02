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
#define N                     	100007

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

class AddMultiply
{
public:
	VI makeExpression(int y) {
		VI ans;
		for (int x0 = -1000; x0 <= 1000; ++x0) {
			if(x0 == 0 || x0 == 1) continue;
			for (int x1 = -1000; x1 <= 1000; ++x1) {
				if(x1 == 0 || x1 == 1) continue;
				int tmp = y - x0*x1;
				if(tmp != 0 && tmp != 1 && && -1000 <= tmp && tmp <= 1000) {
					ans.pb(x0);
					ans.pb(x1);
					ans.pb(tmp);
					return ans;
				}
			}
		}
		return ans;
	}
};