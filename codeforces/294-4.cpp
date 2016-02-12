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

ll ans;
ll val[27];
string s;
ll pref[100005];
map<ll,ll> tree[26];

int main()
{
	SYNC;
	for (int i = 0; i < 26; ++i) {
		cin >> val[i];
	}
    cin >> s;
    pref[0] = val[s[0]-'a'];
    for (int i = 1; i < s.size(); ++i) {
    	pref[i] = pref[i-1] + val[s[i]-'a'];
    }
    tree[s[0]-'a'][pref[0]] = 1;
    for (int i = 1; i < s.size(); ++i) {
    	ans += tree[s[i]-'a'][pref[i-1]];
    	tree[s[i]-'a'][pref[i]]++;
    }
    cout << ans << endl;
    return 0;
}
