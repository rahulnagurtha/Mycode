#include <bits/stdc++.h>

using namespace std;

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
    ll n;
    ll height[N];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> height[i];
    }
    ll curpos = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
    	ans += (abs(curpos - height[i]) + 1);
    	curpos = height[i];
    	if(i + 1 <= n) {
    		ans += abs(curpos - height[i+1]);
    		ans++;
    		curpos = height[i+1];
    	}
    }
    cout << ans << endl;
    return 0;
}