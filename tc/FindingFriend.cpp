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


class FindingFriend
{
public:
	int find(int roomSize, vector <int> leaders, int friendPlace) {
		int ans = 0;
		sort(leaders.begin(), leaders.end());
		for (int i = 0; i < leaders.size(); ++i) {
			if(leaders[i] == friendPlace) return 1;
		}
		for (int i = 0; i < leaders.size(); ++i) {
			//check if he can come under this guy
			if(leaders[i] > friendPlace) continue;
			bool isPossible = true;
			int cnt = 0;
			int total = roomSize*leaders.size();
			for (int j = leaders.size() - 1; j >= 0; --j) {
				int available = (total - leaders[i]) - cnt*(roomSize);
				if((leaders[j] < friendPlace) && (leaders[i] < leaders[j])) {
					available--;
				}
				if(available < (roomSize - 1)) {
					isPossible = false;
					break;
				}
				cnt++;
			}
			if(isPossible) ans++;
		}
		return ans;
	}
};