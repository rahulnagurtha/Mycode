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

class PackingBallsDiv2
{
public:
	int minPacks(int R, int G, int B) {
		int ans = 500;
		int maxPossible = min(R,min(G,B));
		for (int i = 0; i <= maxPossible; ++i) {
			int tmp = i + (R - i)/3 + (G - i)/3 + (B - i)/3;
			if((R - i)%3 + (G - i)%3 + (B - i)%3 > 0) {
				if((R - i)%3 != 2 && (G - i)%3 != 2 && (B - i)%3 != 2) tmp++;
				else tmp += 2;
			}
			ans = min(ans,tmp);
		}
		return ans;
	}
};