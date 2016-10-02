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

class BuildingHeights
{
public:
	int prefixSum[4005];
	void preProcess(VI &A) {
		prefixSum[0] = 0;
		for (int i = 1; i <= A.size(); ++i) {
			prefixSum[i] = prefixSum[i - 1] + A[i - 1];
		}
		return;
	}
	int getSum(int l,int r) {
		return prefixSum[r] - prefixSum[l - 1];
	}
	int minCostOfWindow(VI &A,int sz) {
		int ans = INT_MAX;
		for (int i = 0; i + sz - 1 < A.size(); ++i) {
			ans = min(ans,sz*A[i + sz - 1] - getSum(i + 1, i + sz));
		}
		return ans;
	}
	int minimum(VI heights) {
		sort(heights.begin(),heights.end());
		preProcess(heights);
		int ans = 0;
		for (int i = 1; i <= heights.size(); ++i) {
			ans ^= minCostOfWindow(heights,i);
		}
		return ans;
	}
};