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

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define Ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
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

ll n,q,l,r,p,bsiz,total;

string temp;

ll bval[320],bdig[320],dig,val,type,bnum;
ll aval[100005],adig[100005];

ll lblock,rblock;


ll dp[2000005];



inline void bupdate(ll k) {
    ll lft,ryt;
    lft = bsiz*(k-1) + 1;
    ryt = min(bsiz*(k),n);
    bval[k] = 0;
    dig = 0;
    for (ll i = ryt; i >= lft; --i) {
        bval[k] += (dp[dig]*aval[i])%MOD;
        dig += adig[i];
        bval[k] = bval[k]%MOD;
    }
    return;
}


int main()
{
    dp[0] = 1;
    for (ll i = 1; i <= 2000005; ++i) {
        dp[i] = (dp[i-1]*10)%MOD;
    }
    slli(n);
    bsiz = ceil(sqrt(n));
    total = Ceil(n,bsiz);
    for (ll i = 1; i <= n; ++i) {
        cin >> temp;
        dig = 0;
        aval[i] = 0;
        for (ll j = temp.size()-1; j >= 0; --j) {
            aval[i] += ((ll)(temp[j]-'0')*dp[dig])%MOD;
            aval[i] = aval[i]%MOD;
            dig++;
        }
        adig[i] = temp.size();
        bdig[Ceil(i,bsiz)] += temp.size();
    }
    for (ll i = 1; i <= total; ++i) {
        bupdate(i);
    }
    slli(q);
    for (ll z = 0; z < q; ++z) {
        slli(type);
        if(type == 1) {
            slli(l);
            cin >> temp;
            aval[l] = 0;
            dig = 0;
            bnum = Ceil(l,bsiz);

            bdig[bnum] = bdig[bnum] - adig[l] + temp.size();
            
            adig[l] = temp.size();

            for (ll j = temp.size()-1; j >= 0; --j) {
                aval[l] += ((ll)(temp[j]-'0')*dp[dig])%MOD;
                aval[l] = aval[l]%MOD;
                dig++;
            }

            bupdate(bnum);
        }
        else {
            slli2(l,r);
            lblock = Ceil(l,bsiz);
            rblock = Ceil(r,bsiz);
            if(lblock == rblock || r - l + 1 <= 2 * bsiz) {
                val = 0;
                dig = 0;
                for (ll i = r;i >= l;--i) {
                    val += (dp[dig]*aval[i])% MOD;
                    val %= MOD;
                    dig += adig[i];
                }
                printf("%lld\n",val);
            }
            else {
                if(l % bsiz != 1) lblock++;
                val = 0;
                dig = 0;
                if(r % bsiz != 0) {
                    while(r%bsiz != 0) {
                        val += (aval[r]*dp[dig])%MOD;
                        val %= MOD;
                        dig += adig[r];
                        r--;
                    }
                    rblock--;
                }
                while(lblock <= rblock) {
                    val += (dp[dig]*bval[rblock])%MOD;
                    val %= MOD;
                    dig += bdig[rblock];
                    rblock--;
                }
                if(l%bsiz != 1) {
                    for (ll i = (lblock-1)*bsiz; i >= l; --i) {
                        val += (dp[dig]*aval[i])%MOD;
                        dig += adig[i];
                        val %= MOD;
                    }
                }
                printf("%lld\n",val);
            }
        }
    }
    return 0;
}
