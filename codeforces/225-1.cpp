#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif

#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define rep(i,a,b)				for(int i = (a); (i) <= (b); (i)++)
#define per(i,a,b)				for(int i = (a); (i) >= (b); (i)--)
#define reps(i,a,b,s)			for(int i = (a); (i) <= (b); i += (s))
#define pers(i,a,b,s)			for(int i = (a); (i) >= (b); i -= (s))

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF 					INT_MAX
#define N                     	100007


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



int n;
char board[1005][1005];


bool isInside(int x,int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}


int main()
{
	fill(board,'1');
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			bool isSafe = true;
			for (int k = 0; k < 4; ++k) {
				if(isInside(i + dX[k],j + dY[k]) && board[i + dX[k]][j + dY[k]] == 'C') {
					isSafe = false;
					break;
				}
			}
			if(isSafe) {
				board[i][j] = 'C';
				cnt++;
			}
			else {
				board[i][j] = '.';
			}
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
    return 0;
}