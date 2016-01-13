#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              
#endif

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
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
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


int a[100005],b[100005],diff[100005];
VI buttons;

int main()
{
    int t;
    cin >> t ;
    while(t--) {
    	buttons.clear();
    	int n,m,k,tmp,cur;
    	cin >> n >> k >> m;
    	for (int i = 0; i < n; ++i) {
    		cin >> a[i];
    	}
    	for (int i = 0; i < n; ++i) {
    		cin >> b[i];
    		diff[i] = a[i] - b[i];
    	}
    	for (int i = 0; i < k; ++i) {
    		cin >> tmp;
    		buttons.pb(tmp);
    	}
    	for (int i = 0; i < m; ++i) {
    		cin >> tmp;
    		buttons.pb(tmp);
    	}
    	cur = k + m - 1;
    	sort(buttons.begin(),buttons.end());
    	sort(diff,diff + n);
    	for (int i = n-1; i >= 0; --i) {
    		while(cur >= 0 && diff[i] < buttons[cur]) cur--;
    		if(cur >= 0) {
    			diff[i] = diff[i] - buttons[cur];
    			cur--;
    		}
    	}
    	ll sum = 0;
    	for (int i = 0; i < n; ++i) {
    		sum += diff[i];
    	}
    	cout << sum << endl;
    }
    return 0;
}
