#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.hpp"
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


int main()
{
    int t;
    // freopen("in.txt", "r", stdin);
    cin >> t ;
    while(t--) {
    	int n,a[21];
    	deque<PII> Q;
    	PII temp;
    	bool visited[21];
    	fill(visited,false);
    	si(n);
    	for (int i = 0; i < n; ++i) si(a[i]);
		visited[0] = true;
		Q.pb(mp(0,0));
		while(!Q.empty()) {
			temp = Q.front();
			Q.pop_front();
			if(temp.FF == n) {
				printf("%d\n",temp.SS);
				break;
			}
			if(!visited[temp.FF + 1]) {
				visited[temp.FF + 1] = true;
				Q.pb(mp(temp.FF + 1,temp.SS + 1));
			}
			if( temp.FF + a[temp.FF] >= 0 && temp.FF + a[temp.FF] <= n && !visited[temp.FF + a[temp.FF]]) {
				visited[temp.FF + a[temp.FF]] = true;
				Q.pb(mp(temp.FF + a[temp.FF],temp.SS + 1));
			}
		}
    }
    return 0;
}
