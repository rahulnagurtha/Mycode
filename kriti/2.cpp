#include <bits/stdc++.h>

using namespace std;


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
#define N                       10000007


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




int cnt[N];

void preProcess() {
	fill(cnt,0);
	for (ll i = 2; i < N; ++i) {
		if(cnt[i] == 0) {
			// cnt[i] = 1;
			for (ll j = i; j < N; j += i) {
				cnt[j]++;
			}
		}
	}
	return;
}


int main()
{
	preProcess();
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    int testcase = 1;
    while(t--) {
    	ll a,b,n;
    	ll ans = 0;
    	cin >> a >> b >> n;
    	for (ll i = a; i <= b; ++i) {
    		if(cnt[i] == n) ans++;
    		// cout << cnt[i] << " ";
    	}
    	// cout << endl;
    	cout << "Case #" << testcase << ": "<< ans << endl;
    	testcase++;
    }
    return 0;
}