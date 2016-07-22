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

class FiringEmployees
{
public:
	VOVI graph;
	int profit[2505];
	void init() {
		graph.resize(2505);
		return;
	}
	int dfs(int cur) {
		int childrenProfit = 0;
		for (int i = 0; i < graph[cur].size(); ++i) {
			childrenProfit += dfs(graph[cur][i]);
		}
		return max(0,profit[cur] + childrenProfit);
	}
	int fire(vector <int> manager, vector <int> salary, vector <int> productivity) {
		init();
		for (int i = 0; i < manager.size(); ++i) {
			graph[manager[i]].pb(i+1);
		}
		profit[0] = 0;
		for (int i = 0; i < manager.size(); ++i) {
			profit[i+1] = productivity[i] - salary[i];
		}
		return dfs(0);
	}
};