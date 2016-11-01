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
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF                     INT_MAX
#define N                       100007


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


int ans;
int lps[N];
string P,T;


void buildLPS() {
    lps[0] = 0;
    for (int i = 1; i < P.size(); ++i) {
    	int cur = lps[i-1];
    	while(P[cur] != P[i] && cur != 0) {
    		cur = lps[cur - 1];
    	}
    	if(cur == 0) {
    		lps[i] = (P[cur] == P[i] ? 1 : 0);
    	}
    	else {
    		lps[i] = cur + 1;
    	}
    }
    return;
}

void solve() {
	int target = 0;
	for (int i = 0; i < T.size(); ++i) {
		while(T[i] != P[target] && target != 0) {
			target = lps[target - 1];
		}
		if(T[i] == P[target]) target++;
		if(target == P.size()) {
			ans++;
			target = lps[P.size() - 1];
		}
	}
	return;
}


int main()
{
    cin >> P;
    cin >> T;
    buildLPS();
    solve();
    cout << ans << endl;
    return 0;
}