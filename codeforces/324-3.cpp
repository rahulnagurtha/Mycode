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
    int n,t;
    cin >> n >> t;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    string ans = s1;
    for (int i = 0; i < s1.size(); ++i) {
    	if(s1[i] != s2[i]) {
			for (int j = 0; j < 26; ++j) {
				ans[i] = 'a' + j;
				if(ans[i] != s1[i] && ans[i] != s2[i]) break;
			}
		}
		else ans[i] = s1[i];
    }
    int same = n - t;
    int numSame = 0;
    int numDifferent;
    for (int i = 0; i < s1.size(); ++i) {
    	if(s1[i] == s2[i]) {
    		numSame++;
    	}
    }
    numDifferent = n - numSame;
    if(numDifferent%2 == 1) numDifferent--;
    if(same > numDifferent/2 + numSame) {
    	cout << "-1" << endl;
    	return 0;
    }

	for (int i = 0; i < s1.size(); ++i) {
		if(same <= numDifferent/2) {
			if(s1[i] == s2[i]) {
    			if(s1[i] != 'z') ans[i] = (char)(s1[i] + 1);
    			else ans[i] = 'y';
    		}
		}
		else {
			if(s1[i] == s2[i]) {
    			same--;
    		}
		}
	}
    int cnt1 = numDifferent/2;
    int cnt2 = numDifferent/2;
    for (int i = 0; i < s1.size(); ++i) {
		if(s1[i] != s2[i]) {
			if(cnt1 > 0) {
				ans[i] = s1[i];
				cnt1--;
			}
			else if(cnt2 > 0){
				ans[i] = s2[i];
				cnt2--;
			}
		}
    }
    cout << ans << endl;
    return 0;
}