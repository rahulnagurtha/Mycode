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



int data[501][501],cnt[100001],x,y,xx,yy,pre_x,pre_y;
string a;

void init() {
	fill(cnt,0);
	for (int i = 1; i <= x; ++i) {
    	for (int j = 1; j <= y; ++j) {
    		data[i][j] = a.size();
    	}
    }
    data[xx][yy] = 0;
    return;
}


bool valid(char dir) {
	if(dir == 'U' && pre_x == 1) return false;
	else if(dir == 'D' && pre_x == x) return false;
	else if(dir == 'L' && pre_y == 1) return false;
	else if(dir == 'R' && pre_y == y) return false;
	return true;
}

void update(char dir) {
	if(dir == 'U') pre_x--;
	else if(dir == 'D') pre_x++;
	else if(dir == 'L') pre_y--;
	else pre_y++;
	return;
}


int main()
{
	SYNC;
    cin >> x >> y >> xx >> yy;
    init();
    cin >> a;
    pre_x = xx;
    pre_y = yy;
    init();
    for (int i = 0; i < a.size(); ++i) {
    	if(valid(a[i])) {
    		update(a[i]);
    		if(data[pre_x][pre_y] > i + 1) data[pre_x][pre_y] = i + 1;
    	}
    }
    for (int i = 1; i <= x; ++i) {
    	for (int j = 1; j <= y; ++j) {
    		// cout << data[i][j] << " ";
    		cnt[data[i][j]]++;
    	}
    	// printf("\n");
    }
    for (int i = 0; i <= a.size(); ++i) {
    	cout << cnt[i] << " ";
    }
    printf("\n");
    return 0;
}
