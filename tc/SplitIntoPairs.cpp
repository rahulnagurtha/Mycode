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

class SplitIntoPairs
{
public:
	int makepairs(VI A, int X) {
		VI negative;
		VI positive;
		int negSz,posSz,ans;
		for (int i = 0; i < A.size(); ++i) {
			if(A[i] < 0) negative.pb(A[i]);
			else positive.pb(A[i]);	
		}
		if(negative.size() > 0) sort(negative.begin(),negative.end());
		if(positive.size() > 0) sort(positive.begin(),positive.end());
		negSz = negative.size();
		posSz = positive.size();
		if(negSz % 2 == 0 || posSz%2 == 0) {
			ans = negSz/2 + posSz/2;
		}
		else {
			if((ll)negative[negSz-1]*positive[0] >= (ll)X) ans = A.size()/2;
			else ans = A.size()/2 - 1;
		}
		return ans;
	}
	
};