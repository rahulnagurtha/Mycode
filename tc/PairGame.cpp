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

class PairGame
{
	VOII one;
	VOII two;
public:
	int maxSum(int a, int b, int c, int d) {
		int ans = -1;
		while(true) {
			one.pb(mp(a,b));
			if(a > b) a -= b;
			else b -= a;
			if(a <= 0 || b <= 0) break;
		}
		while(true) {
			two.pb(mp(c,d));
			if(c > d) c -= d;
			else d -= c;
			if(c <= 0 || d <= 0) break;
		}
		int ptr1 = 0,ptr2 = 0;
		while(ptr1 < one.size() && ptr2 < two.size()) {
			if(one[ptr1] == two[ptr2]) {
				ans = one[ptr1].FF + one[ptr1].SS;
				break;
			}
			else if(one[ptr1] < two[ptr2]) ptr2++;
			else ptr1++;
		}
		return ans;
	}
};