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


ll compareCnt;
ll swapCnt;

inline void Refresh() {
    compareCnt = swapCnt = 0;
    return;
}


int compare(int a,int b) {
	compareCnt++;
    if (a > b) return 1;
    else return -1;
}
        

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	Refresh();
        int n;
        int a[10005];
        int pos[10005];
        int finalPos[10005];
        ll ans = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
        	cin >> a[i];
        	pos[a[i]] = i;
        }
		sort(a,a+n);
		for (int i = 0; i < n; ++i) {
			finalPos[a[i]] = i;
		}
		for (int i = 1; i < n; ++i) {
			// cout << a[i] << " " << finalPos[a[i]] << " " << pos[a[i]] << endl;
			if(finalPos[a[i]] <= pos[a[i]]) {
				ans++;
			}
			else ans++;
		}
        cout << ans << endl;
    }
    return 0;
}