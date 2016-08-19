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

class Drbalance
{
public:
	int lesscng(string s, int k) {
		int balance[55] = {0};
		int ans = 0;
		int gain = 0;
		balance[0] = (s[0] == '+' ? 1 : -1 );
		for (int i = 1; i < s.size(); ++i) {
			balance[i] = balance[i-1] + (s[i] == '+' ? 1 : -1);
		}
		for (int i = 0; i < s.size(); ++i) {
			int toRyt = 0;
			for (int j = i; j < s.size(); ++j) {
				if(gain + balance[j] >= 0) toRyt++;
			}
			if(toRyt + i >= (s.size() - k)) break;
			if(balance[i] < 0) {
				ans++;
				gain += 2;
			} 
		}
		return ans;
	}
	
};