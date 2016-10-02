#include <bits/stdc++.h>

using namespace std;

#define MOD                     1000000007
#define fill(a,v)               memset(a,v,sizeof a)

typedef long long int LL;

int n;
LL dp[1 << 10][102],temp,one;
bool tshirt[10][101];

void init() {
	fill(tshirt,false);
	fill(dp,-1);
	fill(dp[temp-1],1);
	return;
}

void readinput() {
	getchar();
	stringstream ss;
	int foo,k;
	string inp;
	k = 1;
	while (k <= n) {
		getline (cin, inp);
		ss.clear ();
		ss.str ("");
		ss << inp;
		while (ss >> foo) {
			tshirt[k][foo] = true;
		}
		k++;
	}
	return;
}

LL instance(int mask,int id) {
	if(id == 101)
    {
        if(mask == temp-1) return dp[mask][id]=1;
        else return dp[mask][id]=0;
    }
	if(dp[mask][id] != -1) return dp[mask][id];
	dp[mask][id] = 0;
	dp[mask][id] += (instance(mask,id+1))%MOD;
	for (int i = 0; i < n; ++i) {
		if( (!(mask & (1 << i))) && tshirt[i+1][id]) {
			dp[mask][id] += instance(mask|(1 << i),id+1);
			dp[mask][id] %= MOD;
		}
	}
	return dp[mask][id];
}

int main()
{
    int t;
    cin >> t ;
    while(t--) {
    	cin >> n;
    	temp = 1 << n;
    	init();
    	readinput();
		printf("%lld\n",instance(0,1));
    }
    return 0;
}