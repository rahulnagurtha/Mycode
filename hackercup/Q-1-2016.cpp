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

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;




int main()
{
    int t;
    int test = 1;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin >> t ;
    while(t--) {
    	map<ll,ll> cnt;
    	ll n,ans = 0,x,y;
    	cin >> n;
    	VOLL p;
    	for (ll i = 0; i < n; ++i) {
    		cin >> x >> y;
    		p.pb(mp(x,y));
    	}
    	for (ll i = 0; i < n; ++i) {
    		cnt.clear();
    		for (ll j = 0; j < i; ++j) {
    			cnt[(p[j].FF-p[i].FF)*(p[j].FF-p[i].FF) + (p[j].SS-p[i].SS)*(p[j].SS-p[i].SS)]++;
    		}
    		for (ll j = i+1; j < n; ++j) {
    			cnt[(p[j].FF-p[i].FF)*(p[j].FF-p[i].FF) + (p[j].SS-p[i].SS)*(p[j].SS-p[i].SS)]++;
    		}
    		for (auto it = cnt.begin(); it != cnt.end(); ++it) {
    			ans += ((it->SS)*((it->SS)-1))/2;
    		}
    	}
    	cout << "Case #" << test << ": " << ans << endl;
    	test++;
    }
    // fclose(stdout);
    return 0;
}
