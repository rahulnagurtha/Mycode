#include <bits/stdc++.h>

using namespace std;

#define si(i)                   scanf("%d",&i)
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)


char a[102][102];
int n,incount[30];
deque<int> zeroin;
bool connected[27][27];
bool visited[30],instack[30],cycle;


void init() {
	fill(connected,false);
	fill(instack,false);
	fill(visited,false);
	fill(incount,0);
	fill(a,'.');
	cycle = false;
	return;
}

void add(int a,int b) {
	if(connected[a][b]) return;
	connected[a][b] = true;
	incount[b]++;
	return;
}

void dfs(int cur) {
	visited[cur] = true;
	instack[cur] = true;
	for (int i = 0; i < 26; ++i) {
		if(!connected[cur][i]) continue;
		if(!visited[i]) dfs(i);
		else if(instack[i]) {
			cycle = true;
		}
	}
	instack[cur] = false;
	return;
}

void buildgraph() {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < 101; ++j) {
			if(a[i][j] == a[i+1][j]) continue;
			if(a[i][j] == '.') break;
			if(a[i+1][j] == '.') {
				add(1,2);
				add(2,1);
				break;
			}
			add(a[i][j] - 'a',a[i+1][j] - 'a');
			break;
		}
	}
	return;
}

bool DAG() {
	for (int i = 0; i < 26; ++i) {
		if(!visited[i]) dfs(i);
	}
	if(cycle) return false;
	else return true;
}

void top_sort() {
	char pre;
	int cur;
	for (int i = 0; i < 26; ++i) {
		if(incount[i] == 0) zeroin.pb(i);
	}
	while(!zeroin.empty()) {
		cur = zeroin.front();
		pre = (char)(97+cur);
		printf("%c",pre);
		zeroin.pop_front();
		for (int i = 0; i < 26; ++i) {
			if(!connected[cur][i]) continue;
			incount[i]--;
			if(incount[i] == 0) zeroin.pb(i);
		}
	}
	printf("\n");
	return;
}

int main()
{
	init();
	string temp;
	si(n);
	for (int i = 0; i < n; ++i) {
		cin >> temp ;
		for (int j = 0; j < temp.size(); ++j) a[i][j] = temp[j];
	}
    buildgraph();
    if(DAG()) top_sort();
    else printf("Impossible\n");
    return 0;
}