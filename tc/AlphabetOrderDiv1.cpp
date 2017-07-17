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


class AlphabetOrderDiv1
{
public:
	map<int,bool> visited;
	bool adjMatrix[26][26];
	bool isInStack[26];
	bool isThereCycle;

	void refresh() {
		fill(isInStack,false);
		visited.clear();
		return;
	}

	void initialise() {
		fill(adjMatrix,false);
		isThereCycle = false;
		return;
	}
	void dfs(int cur) {
		visited[cur] = true;
		isInStack[cur] = true;
		for (int i = 0; i < 26; ++i) {
			if((cur == i) || (!adjMatrix[cur][i])) continue;
			if(isInStack[i]) {
				isThereCycle = true;
			}
			if(!visited[i]) dfs(i);
		}
		isInStack[cur] = false;
		return;
	}
	string isOrdered(vector <string> words) {
		initialise();
		for (int i = 0; i < words.size(); ++i) {
			for (int j = 0; j < words[i].size(); ++j) {
				for (int k = j + 1; k < words[i].size(); ++k) {
					adjMatrix[words[i][j] - 'a'][words[i][k] - 'a'] = true;
				}
			}
		}
		for (int i = 0; i < 26; ++i) {
			refresh();
			dfs(i);
		}
		if(isThereCycle) return "Impossible";
		else return "Possible";
	}
};