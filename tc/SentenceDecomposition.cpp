#include <bits/stdc++.h>

using namespace std;

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

int dX[] = {-1,0,1,0,-1,1,1,-1};
int dY[] = {0,1,0,-1,1,1,-1,-1};

class SentenceDecomposition
{
	string src;
	VS content;
	ll cnt[55][26];
	ll dp[55];
	ll sz;
public:
	void init(string sentence,VS validWords) {
		src = sentence;
		content = validWords;
		sz = sentence.size()-1;
		fill(dp,-1);
		fill(cnt,0);
		for (ll i = 0; i < content.size(); ++i) {
			for (ll j = 0; j < content[i].size(); ++j) {
				cnt[i][content[i][j]-'a']++;
			}
		}
		return;
	}
	bool areFeasible(ll cIdx,ll sIdx) {
		ll sCnt[26] = {0};
		bool possible = true;
		for (ll i = 0; i < content[cIdx].size(); ++i) {
			sCnt[src[sIdx+i] - 'a']++;
		}
		for (ll i = 0; i < 26; ++i) {
			if(cnt[cIdx][i] != sCnt[i]) possible = false;
		}
		return possible;
	}
	ll diff(ll cIdx,ll sIdx) {
		ll unMatches = 0;
		for (ll i = 0; i < content[cIdx].size(); ++i) {
			if(content[cIdx][i] != src[sIdx+i]) unMatches++;
		}
		return unMatches;
	}
	ll solve(ll idx) {
		if(idx > sz) return 0;
		if (dp[idx] != -1) return dp[idx];
		dp[idx] = INT_MAX;
		ll remaining = sz - idx + 1;
		for (ll i = 0; i < content.size(); ++i) {
			if((content[i].size() <= remaining) && areFeasible(i,idx)) {
				dp[idx] = min(dp[idx],diff(i,idx) + solve(idx + content[i].size()));
			}  
		}
		return dp[idx];
	}
	int decompose(string sentence,VS validWords) {
		init(sentence,validWords);
		if(solve(0) >= INT_MAX) return -1;
		else return (int)dp[0];
	}
};