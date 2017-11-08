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


string a[10];



inline void Refresh() {
    
}

bool isInside(int x,int y) {
	return ((0 <= x && x < 10) && (0 <= y && y < 10));
}

bool IsHPossible(int x,int y) {
	int local_cnt = 1;
	for (int j = y + 1; j < 10; ++j) {
		if(a[x][j] == 'X') local_cnt++;
		else break;
	}
	for (int j = y - 1; j >= 0; --j) {
		if(a[x][j] == 'X') local_cnt++;
		else break;
	}
	return (local_cnt >= 5);
}

bool IsVPossible(int x,int y) {
	int local_cnt = 1;
	for (int i = x + 1; i < 10; ++i) {
		if(a[i][y] == 'X') local_cnt++;
		else break;
	}
	for (int i = x - 1; i >= 0; --i) {
		if(a[i][y] == 'X') local_cnt++;
		else break;
	}
	return (local_cnt >= 5);
}

bool IsD1Possible(int x,int y) {
	int local_cnt = 1;
	for (int j = y + 1, i = x + 1; i < 10 && j < 10; ++j,++i) {
		if(a[i][j] == 'X') local_cnt++;
		else break;
	}
	for (int j = y - 1, i = x - 1; i >= 0 && j >= 0; --j,--i) {
		if(a[i][j] == 'X') local_cnt++;
		else break;
	}
	return (local_cnt >= 5);
}

bool IsD2Possible(int x,int y) {
	int local_cnt = 1;
	for (int j = y + 1, i = x - 1; i >= 0 && j < 10; ++j,--i) {
		if(a[i][j] == 'X') local_cnt++;
		else break;
	}
	for (int j = y - 1, i = x + 1; i < 10 && j >= 0; --j,++i) {
		if(a[i][j] == 'X') local_cnt++;
		else break;
	}
	return (local_cnt >= 5);
}


bool IsPossible(int x,int y) {
	return (IsHPossible(x,y) || IsVPossible(x,y) || IsD1Possible(x,y) || IsD2Possible(x,y));
}

int main()
{
	for (int i = 0; i < 10; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if(a[i][j] == '.') {
				a[i][j] = 'X';
				if(IsPossible(i,j)) {
					cout << "YES" << endl;
					return 0;
				}
				a[i][j] = '.';
			}

		}
	}
	cout << "NO" << endl;
    return 0;
}