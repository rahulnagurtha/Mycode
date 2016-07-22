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

class Family
{
private:
	VI graph[105];
	VI orgGraph[105];
	bool visited[105];
	bool processed[105];
	bool inStack[105];
	int colour[105];
	int inComing[105];
public:
	void init();
	bool isDAG(int);
	bool checkIsDerCycle(int);
	bool canColourFrom(int,int);
	string isFamily(vector <int>, vector <int>);
};

void Family::init() {
	fill(colour,-1);
	fill(inComing,0);
	fill(inStack,false);
	fill(visited,false);
	fill(processed,false);
	return;
}

bool Family::checkIsDerCycle(int cur) {
	bool cycle = false;
	inStack[cur] = true;
	processed[cur] = true;
	for (int i = 0; i < orgGraph[cur].size(); ++i) {
		if(inStack[orgGraph[cur][i]]) {
			cycle = true;
			break;
		}
		if(!processed[orgGraph[cur][i]]) cycle = checkIsDerCycle(orgGraph[cur][i]);
		if(cycle) break;
	}
	inStack[cur] = false;
	return cycle;
}

bool Family::isDAG(int sz) {
	bool cycle = true;
	for (int i = 0; i < sz; ++i) {
		if(inComing[i] == 0) {
			cycle = checkIsDerCycle(i);
			if(cycle) break;
		}
	}
	for (int i = 0; i < sz; ++i) {
		if(!processed[i]) cycle = true;
	}
	return !cycle;
}

bool Family::canColourFrom(int cur,int curColour) {
	bool possible = true;
	visited[cur] = true;
	colour[cur] = curColour;
	for (int i = 0; i < graph[cur].size(); ++i) {
		if(!visited[graph[cur][i]]) {
			possible = canColourFrom(graph[cur][i],(curColour+1)%2);
			if(!possible) break;
		}
		else if(colour[graph[cur][i]] == curColour) return false;
	}
	return possible;
}

string Family::isFamily(vector <int> parent1, vector <int> parent2) {
	init();
	bool possible = false;
	for (int i = 0; i < parent1.size(); ++i) {
		if(parent1[i] != -1 && parent2[i] != -1) {
			inComing[parent1[i]]++;
			inComing[parent2[i]]++;
			orgGraph[i].pb(parent1[i]);
			orgGraph[i].pb(parent2[i]);
			graph[parent1[i]].pb(parent2[i]);
			graph[parent2[i]].pb(parent1[i]);
		}
	}
	if(isDAG(parent1.size())) {
		for (int i = 0; i < parent1.size(); ++i) {
			if(!visited[i]) possible = canColourFrom(i,0);
			if(possible == false) break;
		}
	}
	if(!possible) return "Impossible";
	else return "Possible";
}


int main()
{
	Family test;
	VI one;
	VI two;
	int n,tmp1,tmp2;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tmp1 >> tmp2;
		one.pb(tmp1);
		two.pb(tmp2);
	}
	cout << test.isFamily(one,two) << endl;
}