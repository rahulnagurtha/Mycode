#include <bits/stdc++.h>

using namespace std;

#define MAXV 10005

vector<vector<int> > graph(MAXV);
bool visited[MAXV];
int n,m,in,out;

bool dfs() {

}

int main() 
{
	scanf("%d",n,m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d",out,in);
		graph[out].pb(in);
	}
	for (int i = 1; i <= n; ++i) {
		if(!visited[i]) dfs(i);
	}

	return 0;
}