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

class AlienAndHamburgers
{
public:
	int getNumber(VI type,VI taste) {
		VI kind[105];
		VI info;
		int ans = 0,cur = 0,cnt = 0;
		for (int i = 0; i < 102; ++i) {
			kind[type[i]].pb(taste[i]);
		}
		for (int i = 1; i <= 105; ++i) {
			if(kind[i].size() > 0) {
				sort(kind[i].begin(),kind[i].end());
				reverse(kind[i].begin(),kind[i].end());
				if(kind[i][0] < 0) info.pb(kind[i][0]);
				else {
					int tmp = 0;
					for (int j = 0; j < kind[i].size(); ++j) {
						if(kind[i][j] >= 0) tmp += kind[i][j];
						else break;
					}
					info.pb(tmp);
				}
			}
		}
		sort(info.begin(),info.end());
		reverse(info.begin(),info.end());
		for (int i = 0; i < info.size(); ++i) {
			if(cur + info[i] + cnt*info[i] >= 0) {
				ans += (cur + info[i] + cnt*info[i]);
				cur += info[i];
				cnt++;
			}
			else break;
		}
		return ans;
	}
	
};