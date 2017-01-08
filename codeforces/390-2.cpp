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

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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






inline void Refresh() {
    
}


string board[4];

bool isInside(int x,int y) {
	return ((0 <= x) && (x <= 3) && (0 <= y) && (y <= 3));
}

int main()
{
	bool isPossible = false;
	for (int i = 0; i < 4; ++i) {
		cin >> board[i];
	}
	//check if horizontal is possible
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			map<char,int> data;
			for (int yy = y,xx = x; yy < y + 3; ++yy) {
				if(isInside(xx,yy)) data[board[xx][yy]]++;
			}
			if((data['x'] == 2) && (data['.'] == 1)) {
				isPossible = true;
			}
		}
	}
	//check if vertical is possible
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			map<char,int> data;
			for (int yy = y,xx = x; xx < x + 3; ++xx) {
				if(isInside(xx,yy)) data[board[xx][yy]]++;
			}
			if((data['x'] == 2) && (data['.'] == 1)) {
				isPossible = true;
			}
		}
	}
	//check if diagonal is possible
	for (int x = 0; x < 4; ++x) {
		for (int y = 0; y < 4; ++y) {
			map<char,int> data;
			for (int xx = x,yy = y; xx < x + 3; ++xx,++yy) {
				if(isInside(xx,yy)) data[board[xx][yy]]++;
			}
			if((data['x'] == 2) && (data['.'] == 1)) {
				isPossible = true;
			}
		}
	}
	if(isPossible) cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}