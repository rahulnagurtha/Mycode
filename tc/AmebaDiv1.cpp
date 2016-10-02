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

class AmebaDiv1
{
	map<ll,bool> canMake;
public:
	int count(VI X) {
		int ans = 0;
		for (int i = 0; i < X.size(); ++i) {
			canMake[X[i]] = false;
		}
		for (int i = 0; i < X.size(); ++i) {
			ll cur = X[i];
			for (int j = 0; j < X.size(); ++j) {
				if(cur == (ll)X[j]) cur = cur << 1;				
			}
			canMake[cur] = true;
		}
		for (int i = 0; i < X.size(); ++i) {
			if(!canMake[X[i]]) {
				ans++;
				canMake[X[i]] = true;
			}
		}
		return ans;
	}
};