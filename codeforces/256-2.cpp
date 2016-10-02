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
#define INF 					INT_MAX
#define N                     	100007


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


int main()
{
    string s;
    string t;
    int cntS[30] = {0};
    int cntT[30] = {0};
    cin >> s >> t;
    for (int i = 0; i < s.size(); ++i) {
    	cntS[s[i] - 'a']++;
    }
    for (int i = 0; i < t.size(); ++i) {
    	cntT[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
    	if(cntS[i] < cntT[i]) {
    		cout << "need tree" << endl;
    		return 0;
    	}
    }
    int curPos = 0;
    for (int i = 0; i < s.size(); ++i) {
    	if(curPos < t.size() && t[curPos] == s[i]) curPos++;
    }
    if(curPos == t.size()) {
    	cout << "automaton" << endl;
    }
    else {
    	if(s.size() == t.size()) cout << "array" << endl;
    	else cout << "both" << endl;
    }
    return 0;
}