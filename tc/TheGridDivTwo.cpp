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


class TheGridDivTwo
{
public:
	set<PII> visited;
	set<PII> blocked;
	int ans;
	int find(VI x, VI y, int k) {
		deque<pair<PII,int> > Q;
		ans = 0;
		for (int i = 0; i < x.size(); ++i) {
			blocked.insert(mp(x[i],y[i]));
		}
		visited.insert(mp(0,0));
		Q.pb(mp(mp(0,0),0));
		while(!Q.empty()) {
			PII curPoint = Q.front().FF;
			int curDis = Q.front().SS;
			Q.pop_front();
			ans = max(ans,curPoint.FF);
			if(curDis >= k) continue;
			for (int i = 0; i < 4; ++i) {
				int xx = curPoint.FF + dX[i];
				int yy = curPoint.SS + dY[i];
				if(visited.find(mp(xx,yy)) == visited.end() && blocked.find(mp(xx,yy)) == blocked.end()) {
					visited.insert(mp(xx,yy));
					Q.pb(mp(mp(xx,yy),curDis + 1));
				}
			}
		}
		return ans;
	}	
};