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
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

string key;
ll power[1000005];
bool lft[1000005],ryt[1000005];
ll a,b;

void init() {
	power[0] = 1;
	for(int i = 1; i < 1000005; ++i) power[i] = (power[i-1]*10) % b;
	return;
}

void lftdiv() {
	ll rem = 0;
	for(int i = 0; i < key.size(); ++i) {
		rem = (rem*10 + (ll)(key[i]-'0')) % a;
		if(rem == 0) lft[i] = true;
	}
	return;
}

void rytdiv() {
	ll rem = 0;
	for(int i = key.size()-1; i >= 0; --i) {
		rem = (rem + power[key.size()-i-1]*((ll)(key[i]-'0')))%b;
		if((rem == 0) && (key[i] != '0')) ryt[i] = true;
	}
	return;
}

int main()
{
    SYNC;
    bool found = false;
    cin >> key;
    cin >> a >> b;
    init();
    lftdiv();
    rytdiv();
    for(int i = 0; i < key.size()-1; ++i) {
    	if(lft[i] && ryt[i+1]) {
    		found = true;
    		cout << "YES" << "\n";
    		for(int j = 0; j <= i; ++j) {
    			cout << key[j];
    		}
    		cout << "\n";
    		for(int j = i+1; j < key.size(); ++j) {
    			cout << key[j];
    		}
    		cout << "\n";
    		break;
    	}
    }
    if(!found) cout << "NO" << "\n";
    return 0;
}