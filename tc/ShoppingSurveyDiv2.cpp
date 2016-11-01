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


class ShoppingSurveyDiv2
{
public:
	int minValue(int n, VI s) {
		int K = s.size();
		VI data;
		int ans = 0;
		priority_queue<int,VI,greater<int> > Q;
		deque<int> buffer;
		for (int i = 0; i <= n; ++i) {
			bool possible = true;
			data = s;
			while(!Q.empty()) Q.pop();
			for (int j = 0; j < data.size(); ++j) {
				data[j] = max(data[j] - i, 0);
			}
			for (int j = 1; j <= n - i; ++j) {
				Q.push(0);
			}
			for (int j = 0; j < data.size(); ++j) {
				buffer.clear();
				while(data[j] > 0) {
					buffer.pb(Q.top());
					Q.pop();
					data[j]--;
				}
				while(!buffer.empty()) {
					if(buffer.front() + 1 >= K) possible = false;
					Q.push(buffer.front() + 1);
					buffer.pop_front();
				}
			}
			if(possible) {
				ans = i;
				break;
			}
		}
		return ans;
	}
};