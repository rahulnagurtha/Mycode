#include <bits/stdc++.h>

using namespace std;

#define XX                      first
#define YY                      second.first
#define ZZ                      second.second
#define pb                      push_back


typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;


inline int toInt(string s) {
    int i;
    stringstream (s)>>i;
    return i;
}


class RGBStreet
{
	int cost[25][3];
	int dp[25][3];
public:
	int process(int n) {
		int toreturn;
		dp[0][0]=min(cost[0][1],cost[0][2]);
		dp[0][1]=min(cost[0][0],cost[0][2]);
		dp[0][2]=min(cost[0][1],cost[0][0]);
		for (int i = 1; i < n ; ++i) {
			dp[i][0] = min(cost[i][1]+dp[i-1][1],cost[i][2]+dp[i-1][2]);
			dp[i][1] = min(cost[i][0]+dp[i-1][0],cost[i][2]+dp[i-1][2]);
			dp[i][2] = min(cost[i][1]+dp[i-1][1],cost[i][0]+dp[i-1][0]);
		}
		toreturn = min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
		return toreturn;
	}
	int estimateCost(vector <string> houses) {
		int minimal;
		VI space;
		string temp1,temp2,temp3;
		for (int j = 0; j < houses.size(); ++j) {
			for (int i = 0; i < houses[j].size(); ++i) {
    			if(houses[j][i]==' ') space.push_back(i);
	    	}
	    	temp1 = houses[j].substr(0,space[0]);
	    	temp2 = houses[j].substr(space[0]+1,space[1]-space[0]-1);
	    	temp3 = houses[j].substr(space[1]+1);
	    	cost[j][0]=toInt(temp1);
	    	cost[j][1]=toInt(temp2);
	    	cost[j][2]=toInt(temp3);
	    	space.clear();
		}
		minimal = process(houses.size());
		return minimal;
	}		
};