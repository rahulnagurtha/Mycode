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

#define rep(i,a,b)              for(int i = (a); (i) <= (b); (i)++)
#define per(i,a,b)              for(int i = (a); (i) >= (b); (i)--)
#define reps(i,a,b,s)           for(int i = (a); (i) <= (b); i += (s))
#define pers(i,a,b,s)           for(int i = (a); (i) >= (b); i -= (s))

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



VL primes;


void process() {
	bool isPrime[N];
	fill(isPrime,true);

	isPrime[1] = false;
	for (int i = 2; i < N; ++i) {
		if(!isPrime[i]) continue;
		primes.pb(i);
		for (int j = i + i; j < N; j += i) {
			isPrime[j] = false;
		}
	}
	return;
}

int main()
{
    process();
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	ll n;
    	ll ans = 0;
    	cin >> n;
    	for (int i = 0; i < primes.size(); ++i) {
    		if(primes[i] > n) break;
    		ans = i + 1;
    	}
    	if(ans % 2 == 1) cout << "Alice" << endl;
    	else cout << "Bob" << endl;
    }
    return 0;
}