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


inline void Refresh() {
    
}


int main()
{
    int t;
    cin >> t;
    while(t--) {
    	string cell[5];
    	int col,trains;
    	cin >> col >> trains;
    	for (int i = 1; i <= 3; ++i) {
    		cin >> cell[i];
    	}
    	for (int i = 0; i <= 20; ++i) {
    		cell[1] += '.';
    		cell[2] += '.';
    		cell[3] += '.';
    	}
    	bool dp[5][120];
    	fill(dp,true);
    	for (int colNum = col-1; colNum >= 0; --colNum) {
    		for (int rowNum = 1; rowNum <= 3; ++rowNum) {
    			dp[rowNum][colNum] = false;
    			if((cell[rowNum][colNum] == 's' || cell[rowNum][colNum] == '.') && cell[rowNum][colNum+1] == '.'){
    				for (int nxtRow = 1; nxtRow <= 3; ++nxtRow) {
    					if(abs(rowNum-nxtRow) > 1) continue;
    					if( cell[nxtRow][colNum+1] == '.' && 
    						cell[nxtRow][colNum+2] == '.' &&
    						cell[nxtRow][colNum+3] == '.') dp[rowNum][colNum] |= dp[nxtRow][colNum+3]; 
    				}
    			}
    		}
    		if(cell[1][colNum] == 's') {
    			if(dp[1][colNum]) cout << "YES" << endl;
    			else cout << "NO" << endl;
    			break;
    		}
    		else if(cell[2][colNum] == 's') {
    			if(dp[2][colNum]) cout << "YES" << endl;
    			else cout << "NO" << endl;
    			break;
    		}
    		else if(cell[3][colNum] == 's') {
    			if(dp[3][colNum]) cout << "YES" << endl;
    			else cout << "NO" << endl;
    			break;
    		}
    	}
    }
    return 0;
}