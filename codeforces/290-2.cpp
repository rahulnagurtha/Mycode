#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              
#endif

#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


int m,n;
char cell[52][52];
bool visited[52][52],cycle;
bool instack[52][52];


void init() {
	cycle = false;
	fill(cell,'.');
	fill(visited,false);
	fill(instack,false);
	return;
}

bool possible(int x,int y,char req) {
	if(x >= 1 && x <= m && y >= 1 && y <= n && cell[x][y] == req) return true;
	return false;
}

bool check(int chX,int chY,int parX,int parY) {
	if( (chX == parX && chY == parY) || !instack[chX][chY] ) return false;
	return true;	
}

void dfs(int curX,int curY,int parX,int parY) {
	visited[curX][curY] = true;
	instack[curX][curY] = true;
	if(possible(curX+1,curY,cell[curX][curY])) {
		if(!visited[curX+1][curY]) dfs(curX+1,curY,curX,curY);
		else if(check(curX+1,curY,parX,parY)) cycle = true; 
	}
	if(possible(curX-1,curY,cell[curX][curY])) {
		if(!visited[curX-1][curY]) dfs(curX-1,curY,curX,curY);
		else if(check(curX-1,curY,parX,parY)) cycle = true;
	}
	if(possible(curX,curY+1,cell[curX][curY])) {
		if(!visited[curX][curY+1]) dfs(curX,curY+1,curX,curY);
		else if(check(curX,curY+1,parX,parY)) cycle = true;
	}
	if(possible(curX,curY-1,cell[curX][curY])) {
		if(!visited[curX][curY-1]) dfs(curX,curY-1,curX,curY);
		else if(check(curX,curY-1,parX,parY)) cycle = true;
	}
	instack[curX][curY] = false;
	return;
}

void solve() {
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(!visited[i][j]) dfs(i,j,-1,-1);
			if(cycle) {
				printf("Yes\n");
				return;
			}
		}
	}
	printf("No\n");
	return;
}


int main()
{
	init();
	string temp;
	si2(m,n);
	for (int i = 1; i <= m; ++i) {
	   	cin >> temp;
	   	for (int j = 0; j < n; ++j) cell[i][j+1] = temp[j];
	}
	solve();
    return 0;
}
