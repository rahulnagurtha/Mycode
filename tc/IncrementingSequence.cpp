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

class IncrementingSequence
{
public:
	string canItBeDone(int k, VI A) {
		VOVI data;
		bool inserted;
		bool made[A.size() + 1];
		fill(made,false);
		for (int i = 0; i < A.size(); ++i) {
			inserted = false;
			for (int j = 0; j < data.size(); ++j) {
				if(abs(data[j].back() - A[i]) % k == 0) {
					data[j].pb(A[i]);
					inserted = true;
					break;
				}
			}
			if(!inserted) {
				VI tmp;
				tmp.pb(A[i]);
				data.pb(tmp);
			}
		}
		for (int i = 0; i < data.size(); ++i) {
			sort(data[i].begin(),data[i].end());
			for (int j = 0; j < data[i].size(); ++j) {
				int tmp = data[i][j];
				while(tmp <= A.size()) {
					if(!made[tmp]) {
						made[tmp] = true;
						break;
					}
					tmp += k;
				}
			}
		}
		for (int i = 1; i <= A.size(); ++i) {
			if(!made[i]) return "IMPOSSIBLE";
		}
		return "POSSIBLE";
	}
};