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

class FixedDiceGameDiv1
{
public:
	double getExpectation(int a, int b, int c, int d) {
		double numOfWins = 0.0;
		double score = 0.0;
		for (int i = a; i <= a*b; ++i) {
			for (int j = c; j <= c*d; ++j) {
				if(i > j) {
					score += i;
					numOfWins += 1;
				}
			}
		}
		if(numOfWins == 0) return -1;
		else return score/numOfWins;
	}
	
};