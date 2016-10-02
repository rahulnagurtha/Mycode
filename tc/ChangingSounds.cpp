#include <bits/stdc++.h>

using namespace std;



#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define box(a,b)                ((a*b>=0)?((a/b)):((a%b==0)?(a/b):(a/b-1)))
#define rem(a,b)                (a-(box(a,b))*b)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem1(a,b)               ((a*b<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007

typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;



bool dp[51][1002];



class ChangingSounds
{
    
    int len;
public:
    int maxFinal(int[] changeIntervals, int beginLevel, int maxLevel) {
        len = sizeof(changeIntervals)/sizeof(changeIntervals[0]);
        fill(dp,false);
        dp[0][beginLevel]=true;
        for (int i = 1; i <=len ; ++i) {
            for (int j = 0; j <= maxLevel ; ++j) {
                if(dp[i-1][j]==true) {
                    if(j+changeIntervals[i-1] <= maxLevel) dp[i][j+changeIntervals[i-1]]=true;
                    if(j-changeIntervals[i-1] >= 0) dp[i][j-changeIntervals[i-1]]=true;
                }
            }
        }
        for (int i = maxlevel; i >=0 ; --i) {
            if(dp[len][i]==true) {
                return i;
            }
        }
        return -1;
    }
};