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

class AddElectricalWires
{
	int numcmp;
	int verCnt[55];
	int edgeCnt[55];
	bool visited[55];
	int component[55];
	VI special;
	VI normal;
	VS grid;
public:
	void init(VS wires) {
		numcmp = 0;
		grid = wires;
		fill(verCnt,0);
		fill(edgeCnt,0);
		fill(component,-1);
		fill(visited,false);
		return;
	}
	void dfs(int cur,int cmp) {
		verCnt[cmp]++;
		component[cur] = cmp;
		visited[cur] = true;
		for (int i = 0; i < grid[cur].size(); ++i) {
			if(grid[cur][i] == '1' && !visited[i]) {
				dfs(i,cmp);
			}
		}
		return;
	}
	int accumAll() {
		int ans = 0,tmp = 0;
		int specialMax = 0,normalSum = 0;
		for (int i = 0; i < special.size(); ++i) {
			specialMax = max(verCnt[special[i]],specialMax);
			ans += ((verCnt[special[i]]*(verCnt[special[i]]-1))/2 - edgeCnt[special[i]]);
		}
		if(normal.size() != 0) tmp = 1;
		for (int i = 0; i < normal.size(); ++i) {
			ans += (normalSum*verCnt[normal[i]]);
			normalSum += verCnt[normal[i]];
			ans += ((verCnt[normal[i]]*(verCnt[normal[i]]-1))/2 - edgeCnt[normal[i]]);	
		}
		ans += (specialMax)*(normalSum);
		return ans;
	}
	int maxNewWires(VS wires,VI gridConnections) {
		init(wires);
		for (int i = 0; i < wires.size(); ++i) {
			if(!visited[i]) {
				dfs(i,numcmp);
				numcmp++;
			}
		}
		for (int i = 0; i < wires.size(); ++i) {
			for (int j = i+1; j < wires.size(); ++j) {
				if(grid[i][j] == '1') {
					edgeCnt[component[i]]++;
				}
			}
		}
		for (int i = 0; i < gridConnections.size(); ++i) {
			special.pb(component[gridConnections[i]]);
		}
		for (int i = 0; i < numcmp; ++i) {
			bool Push = true;
			for (int j = 0; j < special.size(); ++j) {
				if(special[j] == i) Push = false;
			}
			if(Push) normal.pb(i);
		}
		return accumAll();
	}
};