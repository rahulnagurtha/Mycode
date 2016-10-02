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

class HappyLetterDiv2
{
public:
	char getHappyLetter(string letters) {
		int cnt[26];
        fill(cnt,0);
		string ans;
		for (int i = 0; i < letters.size(); ++i) {
			cnt[letters[i] - 'a']++;
		}
		for (int i = 0; i < 26; ++i) {
			if(cnt[i] == 0) continue;
			priority_queue<int,VI,less<int> > Q;
			for (int j = 0; j < 26; ++j) {
				if(j != i && cnt[j] > 0) Q.push(cnt[j]);
			}
			while(Q.size() >= 2) {
				int one = Q.top();
				Q.pop();
				int two = Q.top();
				Q.pop();

				if(one > 1) Q.push(one-1);
				if(two > 1) Q.push(two-1);
			}
			if((Q.size() == 0) || cnt[i] > Q.top()) ans += (char)('a' + i);
			else if(cnt[i] == Q.top()) ans += "..";
		}
		if(ans.size() == 0 || ans.size() > 1) return '.';
		else return ans[0];
	}	
};