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

vector<pair<PLL,int> >points;
ll n,x,y;
ll one,two,three;
ll xone,xtwo,xthree,yone,ytwo,ythree;

bool cmp(pair<PLL,int> a,pair<PLL,int> b) {
	if(a.FF.FF != b.FF.FF) return a.FF.FF < b.FF.FF;
	return a.FF.SS < b.FF.SS;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> x >> y;
    	points.pb(mp(mp(x,y),i));
    }
    sort(points.begin(),points.end(),cmp);
    xone = points[0].FF.FF;
    yone = points[0].FF.SS;
    xtwo = points[1].FF.FF;
    ytwo = points[1].FF.SS;
    for (int i = 2; i < n; ++i) {
    	xthree = points[i].FF.FF;
    	ythree = points[i].FF.SS;
    	if(((ytwo-yone)*(xthree-xone)) != ((ythree-yone)*(xtwo-xone))) {
    		cout << points[0].SS << " " << points[1].SS << " " << points[i].SS << endl;
    		break;
    	}
    }
    return 0;
}
