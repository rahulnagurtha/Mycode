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

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

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


class DAGConstruction
{
public:
	VI construct(VI x) {
		VI ans;
		bool isPossible = true;
		VI available;
		VOII data;
		for (int i = 0; i < x.size(); ++i) {
			data.pb(mp(x[i] - 1,i));
		}
		sort(data.begin(), data.end());
		for (int i = 0; i < x.size(); ++i) {
			if(data[i].FF > available.size()) {
				isPossible = false;
				break;
			}
			for (int j = 0; j < data[i].FF; ++j) {
				ans.pb(data[i].SS);
				ans.pb(available[j]);
			}
			available.pb(data[i].SS);
		}
		if(!isPossible) {
			VI tmp;
			tmp.pb(-1);
			return tmp;
		}
		return ans;
	}
	
};