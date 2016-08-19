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

class Fragile2
{
public:
	bool visited[25];
	VS nGraph;
	void init(int x,int y,VS tmp) {
		nGraph = tmp;
		fill(visited,false);
		for (int i = 0; i < nGraph.size(); ++i) {
			nGraph[x][i] = 'N';
			nGraph[y][i] = 'N';
			nGraph[i][x] = 'N';
			nGraph[i][y] = 'N';
		}
		return;
	}
	void dfs(int cur) {
		visited[cur] = true;
		for (int i = 0; i < nGraph.size(); ++i) {
			if(nGraph[cur][i] != 'N' && !visited[i]) {
				dfs(i);
			}
		}
		return;
	}
	int countPairs(VS graph) {
		int ans = 0;
		int actual = 0;
		fill(visited,false);
		nGraph = graph;
		for (int i = 0; i < graph.size(); ++i) {
			if(!visited[i]) {
				actual++;
				dfs(i);
			}
		}
		for (int i = 0; i < graph.size(); ++i) {
			for (int j = i + 1; j < graph.size(); ++j) {
				init(i,j,graph);
				int cnt = 0;
				for (int k = 0; k < graph.size(); ++k) {
					if(k == i || k == j) continue;
					if(!visited[k]) {
						cnt++;
						dfs(k);
					}
				}
				if(cnt > actual) {
					cout << i << " " << j << endl;
					ans++;
				}
			}
		}
		return ans;
	}
};

int main()
{
	VS graph;
	string tmp;
	int n;
	cin >> n ;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		graph.pb(tmp);
	}
	Fragile2 test;
	cout << test.countPairs(graph) << endl;
}