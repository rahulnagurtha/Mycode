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

class MagicalStringDiv1
{
public:
	int getLongest(string S) {
		int ans = 0;
		int n1,n2;
		for (int k = 1; 2*k <= S.size(); ++k) {
			n1 = n2 = 0;
			for (int i = 0; i < S.size(); ++i) {
				if(S[i] == '>' && n1 < k) n1++;
				if(S[i] == '<' && n1 == k && n2 < k) n2++;
			}
			if(n1 == k && n2 == k) ans = 2*k;
		}
		return ans;
	}
};