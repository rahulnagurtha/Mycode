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
#define Ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
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



inline void Refresh() {
    
}

VOII data;
int ans[100005];
int done[100005];
int blockSum[321];

int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
        fill(blockSum,0);
        fill(ans,0);
        fill(done,0);
        data.clear();
        int n,val;
        int blockSz;
        int curAns;
        cin >> n;
        blockSz = ceil(sqrt(n));
        assert(blockSz != 0);
        for (int i = 1; i <= n; ++i) {
            cin >> val;
            data.pb(mp(val,i));
        }
        sort(data.begin(),data.end());
        for (int i = 0,j; i < data.size(); ++i) {
            j = data[i].SS;
            while(j % blockSz != 1 && (j <= n)) {
                if(done[j]) ans[data[i].SS]++;
                j++;
            }
            for (int k = Ceil(j,blockSz) + (j > n ? 1 : 0); k <= Ceil(n,blockSz); ++k) {
                ans[data[i].SS] += blockSum[k];
            }
            done[data[i].SS] = 1;
            blockSum[Ceil(data[i].SS,blockSz)]++;
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }
        printf("\n");
    }
    return 0;
}