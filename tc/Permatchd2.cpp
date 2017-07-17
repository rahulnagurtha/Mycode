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


class Permatchd2
{
public:
	VOII odd;
	VOII even;
	bool visited[55];
	VI curVertices;
	void init() {
		fill(visited,false);
		return;
	}

	void dfs(int cur,VS &graph) {
		visited[cur] = true;
		curVertices.pb(cur);
		for (int i = 0; i < graph[cur].size(); ++i) {
			if((graph[cur][i] == 'Y') && (!visited[i])) {
				dfs(i,graph);
			}
		}
		return;
	}

	void enumerateAndAdd(VS &graph) {
		int vertices = curVertices.size();
		int totalEdges = 0;
		for (int i = 0; i < curVertices.size(); ++i) {
			for (int j = 0; j < graph.size(); ++j) {
				if(graph[curVertices[i]][j] == 'Y') totalEdges++;
			}
		}
		if(((totalEdges/2) % 2) == 0) even.pb(mp(vertices,totalEdges/2));
		else odd.pb(mp(vertices,totalEdges/2));
		return;
	}

	int compute() {
		int ans = 0;
		bool isPossible = true;
		VI odd;
		VI even;

		if((odd.size() % 2) == 0) return (odd.size())/2;
		if(even.size() > 0) return odd.size();



		//vertices and edges
		for (int i = 0; i < odd.size(); ++i) {
			if((odd[i].SS % 2) != 0) {
				int maxPossible = ((odd[i].FF)*(odd[i].FF-1))/2;
				if(odd[i].SS + 1 <= maxPossible) ans++;
				else isPossible = false;
			}
		}
		if(isPossible) 1 + odd.size()/2;
		return -1;
	}


	int fix(vector <string> graph) {
		init();
		for (int i = 0; i < graph.size(); ++i) {
			if(!visited[i]) {
				curVertices.clear();
				dfs(i,graph);
				enumerateAndAdd(graph);
			}
		}
		return compute();
	}
};