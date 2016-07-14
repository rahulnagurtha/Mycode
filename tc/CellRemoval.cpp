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


class CellRemoval
{
public:
	bool isLeaf[55];
	bool visited[55];
	VOVI graph;
	void init() {
		graph.resize(55);
		fill(visited,false);
		fill(isLeaf,false);
	}
	void dfs(int cur,int deletedCell) {
		if(cur == deletedCell) return;
		if(graph[cur].size() == 0) {
			isLeaf[cur] = true;
			return;
		}
		for (int i = 0; i < graph[cur].size(); ++i) {
			dfs(graph[cur][i],deletedCell);
		}
		return;
	}
	int cellsLeft(vector<int> parent,int deletedCell) {
		init();
		int numCells = 0,start;
		for (int i = 0;i < parent.size(); ++i) {
			if(parent[i] != -1) graph[parent[i]].pb(i);
			else start = i;
		}
		dfs(start,deletedCell);
		for (int i = 0; i < parent.size(); ++i) {
			if(isLeaf[i]) numCells++;
		}
		return numCells;
	}
};


int main()
{
	CellRemoval test;
	vector<int> parent;
	int sz,deletedCell,tmp;
	cin >> sz >> deletedCell ;
	for (int i = 0; i < sz; ++i) {
		cin >> tmp;
		parent.pb(tmp);
	}
	cout << test.cellsLeft(parent,deletedCell) << endl;
	return 0;
}