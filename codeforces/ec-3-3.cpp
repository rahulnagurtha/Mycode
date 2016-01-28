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


string rbs;
vector<char> opening;
deque<char> Q;
deque<int> Q1;

void init() {
	opening.pb('<');
	opening.pb('{');
	opening.pb('[');
	opening.pb('(');
	return;
}

inline char matchof(char tmp) {
	if(tmp == '[') return ']';
	if(tmp == '<') return '>';
	if(tmp == '{') return '}';
	if(tmp == '(') return ')';
}

bool possible() {
	for(int i = 0; i < rbs.size(); ++i) {
		if(find(opening.begin(),opening.end(),rbs[i]) == opening.end()) {
			if(Q1.empty()) return false;
			Q1.pop_back();
		}
		else Q1.pb(1);
	}
	if(!Q1.empty()) {
		return false;
	}
	else return true;
}

void solve() {
	int ans = 0;
	for(int i = 0; i < rbs.size(); ++i) {
		if(find(opening.begin(),opening.end(),rbs[i]) == opening.end()) {
			if(matchof(Q.back()) != rbs[i]) ans++;
			Q.pop_back();
		}
		else Q.pb(rbs[i]);
	}
	cout << ans << endl;
	return;
}

int main()
{
	SYNC;
	init();
    cin >> rbs;
    if(!possible) {
	    cout << "Impossible" << "\n";
    	return 0;
    }
    solve();
    return 0;
}