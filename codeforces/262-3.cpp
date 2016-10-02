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

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                (((a)<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define INF                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;


ll n,m,w;
ll a[100005];
ll lft,ryt;
ll largest,smallest;
ll ans,mid,tans;
ll val[100005];


bool possible(ll req) {
    ll moves = 0;
    ll curval = 0;
    for (int i = 0; i < n; ++i) {
        curval -= ( (i >= w) ? val[i-w] : 0 );
        val[i] = max(0LL,req - (curval+a[i]));
        moves += val[i];
        curval += val[i];
    }
    return (moves <= m);
}



int main()
{
    ans = 0;
    largest = 0;
    smallest = INF;
    cin >> n >> m >> w;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        smallest = min(a[i],smallest);
        largest = max(a[i],largest);
    }
    lft = smallest;
    ryt = largest + m;
    while(lft <= ryt) {
        mid = (lft+ryt)/2;
        if(possible(mid)) {
            ans = max(ans,mid);
            lft = mid+1;
        }
        else ryt = mid-1;
    }
    cout << ans << endl;
    return 0;
}