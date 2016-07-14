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


ll cnt[64];
ll ans;
map<char,ll> valof;

void init() {
	ans = 1;
	for (ll i = 0; i < 64; ++i) {
		for (ll j = 0; j < 64; ++j) {
			cnt[i&j]++;
		}
	}
	for (ll i = 0; i < 10; ++i) {
		valof[char('0'+i)] = i;
	}
	for (ll i = 0; i < 26; ++i) {
		valof[char('A'+i)] = 10+i;
	}
	for (ll i = 0; i < 26; ++i) {
		valof[char('a'+i)] = 36+i;
	}
	valof['-'] = 62;
	valof['_'] = 63;
	return;
}


int main()
{
	init();
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		ans = (ans*cnt[valof[s[i]]])%MOD;
	}
	cout << ans << endl;
    return 0;
}
