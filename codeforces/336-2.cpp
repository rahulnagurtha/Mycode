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

#define FOR(i,a,b)              for(int i=a;i<b;i++)
#define REP(i,n)                FOR(i,0,n)
#define foreach(v, c)           for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define SYNC                    ios_base::sync_with_stdio(0);
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               ((a%b==0)?(a/b):(a/b+1))
#define rem(a,b)                ((a<0)?(((a%b)+b)%b):(a%b))
#define MOD                     1000000007LL

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;

int pre_zero[200001],pre_one[200001];
ll ans;

int main()
{
	ans = 0;
    string a,b;
    cin >> a >> b;
    pre_zero[0] = 0;
    pre_one[0] = 0;
    for (int i = 0; i < b.size(); ++i) {
    	if(b[i] == '0') {
    		pre_zero[i+1] = pre_zero[i];
    		pre_one[i+1] = pre_one[i] + 1;
    	}
    	else {
    		pre_zero[i+1] = pre_zero[i] + 1;
    		pre_one[i+1] = pre_one[i];
    	}
    }
    for (int i = 0; i < a.size(); ++i) {
    	if(a[i] == '0') {
    		ans = ans + pre_zero[b.size()-a.size()+1+i] - pre_zero[i];
    	}
    	else {
    		ans = ans + pre_one[b.size()-a.size()+1+i] - pre_one[i];
    	}
    }
    cout << ans << endl;
    return 0;
}
