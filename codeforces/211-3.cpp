#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../debug.hpp"
struct debugger dbg;
#else 
#define debug(args...)              // Just strip off all debug tokens
#endif

#define si(i)                   scanf("%d",&i)
#define si2(i,j)                scanf("%d %d",&i,&j)
#define si3(i,j,k)              scanf("%d %d %d",&i,&j,&k)
#define slli(i)                 scanf("%I64d",&i)
#define slli2(i,j)              scanf("%I64d %I64d",&i,&j)
#define slli3(i,j,k)            scanf("%I64d %I64d %I64d",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%I64d\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF 					INT_MAX
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


inline void Refresh() {
    
}


int main()
{
    string tmp;
    cin >> tmp;
    string ans;
    ans = tmp[0];
    int cnt = 1;
    for (int i = 1; i < tmp.size(); ++i) {
    	if(ans[ans.size()-1] == tmp[i]) {
    		if(cnt == 1) {
    			ans += tmp[i];
    			cnt++;
    		}
    	}
    	else {
    		ans += tmp[i];
    		cnt = 1;
    	}
    }
    VS data;
    for (int i = 0; i < ans.size(); ) {
    	tmp = "";
    	char cur = ans[i];
    	while(i < ans.size() && ans[i] == cur) {
    		tmp += ans[i];
    		i++;
    	}
    	data.pb(tmp);
    }
    string finalans;
    for (int i = 1; i < data.size(); ++i) {
    	if(data[i].size() != 1 && data[i-1].size() != 1) {
    		string nString;
    		for (int j = 1; j < data[i].size(); ++j) {
    			nString += data[i][j];
    		}
    		data[i] = nString;
    	}
    }
    for (int i = 0; i < data.size(); ++i) {
    	finalans += data[i];
    }
    cout << finalans << endl;
    return 0;
}