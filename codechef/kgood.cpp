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
    cin >> t ;
    while(t--) {
    	VI v;
    	string w;
    	int k,cnt[27] = {0};
    	int ans = 1000005;
    	cin >> w >> k;
    	for (int i = 0; i < w.size(); ++i) {
    		cnt[w[i]-'a']++;
    	}
    	for (int i = 0; i < 26; ++i) {
    		if(cnt[i] != 0) v.pb(cnt[i]);
    	}
    	sort(v.begin(),v.end());
    	if(v[v.size()-1]-v[0] <= k) ans = 0;
    	else {
    		int tp = 0;
    		for (int i = 0; i < v.size(); ++i) {
    			tp += ( (v[i]-v[0] <= k) ? (0): (v[i]-v[0]-k));
    		}
    		ans = min(tp,ans);
    	}
    	for (int i = 0; i < v.size() - 1; ++i) {
    		int tmp = 0;
    		for (int j = 0; j <= i; ++j) {
    			tmp += v[j];
    		}
    		for (int j = i+1; j < v.size(); ++j) {
    			tmp += ( (v[j]-v[i+1] <= k) ? (0) : (v[j]-v[i+1]-k));
    		}
    		ans = min(ans,tmp);
    	}
    	cout << ans << endl;
    }
    return 0;
}
