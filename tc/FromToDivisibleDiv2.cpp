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

class FromToDivisibleDiv2
{
public:
	int ans;
	bool visited[200005];
	int dis[200005];
	deque<int> Q;
	int shortest(int N, int S, int T, vector <int> A, vector <int> B) {
		fill(visited,false);
		fill(dis,-1);
		int cur;
		dis[S] = 0;
		Q.pb(S);
		while(!Q.empty()) {
			if(Q.front() == T) {
				break;
			}
			cur = Q.front();
			Q.pop_front();
			for (int i = 0; i < A.size(); ++i) {
				if(cur % A[i] == 0) {
					for (int j = 1; j <= N; ++j) {
						if(!visited[j] && j % B[i] == 0) {
							visited[j] = true;
							Q.pb(j);
							dis[j] = dis[cur] + 1;
						}
					}
				}
			}
		}
		return dis[T];
	}
	
};