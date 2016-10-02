#include <bits/stdc++.h>

using namespace std;



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

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


ll fact[100005];
ll a[100005];

void init() {
    fact[0] = 1;
    for (ll i = 1; i < 100005 ; ++i)
    {
        fact[i] = (fact[i-1]*i)%MOD;
    }
}


inline ll modulo(ll a,ll b){
    ll res = 1; 
    while(b > 0){
        if(b % 2 == 1){
            res = (res*a)%MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1;
    }
    return res % MOD;
}


int main()
{
    init();
    int t;
    cin >> t;
    while(t--) {
        ll n,k,cnt = 0;
        ll ans = 0;
        bool zeroThere = false;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] == 0) zeroThere = true;
            else cnt++;
        }
        if (!zeroThere) {
            for (ll i = 0; i <= min(cnt,k); ++i) {
                if ((k-i)%2 == 0) {
                    ans += (fact[cnt]*modulo((fact[cnt-i]*fact[i])%MOD,MOD-2))%MOD;
                    ans %= MOD;
                }
            }
        }
        else {
            for (ll i = 0; i <= min(cnt,k); ++i) {
                ans += (fact[cnt]*modulo((fact[cnt-i]*fact[i])%MOD,MOD-2))%MOD;
                ans %= MOD;
            }
        }
        cout << ans << endl;
    }    
    return 0;
}
