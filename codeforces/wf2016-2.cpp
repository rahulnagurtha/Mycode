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

typedef long long int ll;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII> VOII;
typedef vector<PLL> VOLL;
typedef vector<VI> VOVI;



int main()
{
    int n,cnt[100],tmp[55][55],outpt;
    cin >> n;
    outpt = n;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cin >> tmp[i][j];
    	}
    }
    for (int i = 1; i <= n; ++i) {
    	fill(cnt,0);
    	for (int j = 1; j <= n; ++j) {
    		cnt[tmp[i][j]]++;
    	}
    	bool flag = true;
    	for (int j = 1; j <= n; ++j) {
    		if(cnt[j] > 1) {
    			cout << j << " ";
    			flag = false;
    			break;
    		}
    	}
    	if(flag) {
    		cout << outpt << " ";
    		outpt--;
    	}
    }
    return 0;
}
