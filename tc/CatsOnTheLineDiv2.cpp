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

class CatsOnTheLineDiv2
{
public:
	string getAnswer(VI position, VI count, int time) {
		VOII data;
		int lastFilledPos = INT_MIN;
		for (int i = 0; i < position.size(); ++i) {
			data.pb(mp(position[i],count[i]));
		}
		sort(data.begin(),data.end());
		for (int i = 0; i < data.size(); ++i) {
			int lft = data[i].FF - time;
			int ryt = data[i].FF + time;
			lft = max(lastFilledPos + 1,lft);
			lastFilledPos = lft + data[i].SS - 1;
			if(lastFilledPos > ryt) return "Impossible"
		}
		return "Possible";
	}
};