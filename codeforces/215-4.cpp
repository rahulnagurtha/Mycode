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
#define N                     	200007


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

int a[N],b[N];
int tmp[2*N];
map<int,int> compress;
set<int> dis;
int n,m,p;
int aCnt[2*N];
int bCnt[2*N];
int numZeroes;
VOII level[N];
deque<PII> Q;
VI ans;


inline void add(int cur) {
	if(aCnt[cur] == bCnt[cur]) numZeroes--;
	aCnt[cur]++;
	if(aCnt[cur] == bCnt[cur]) numZeroes++;
}

inline void removE(int cur) {
	if(aCnt[cur] == bCnt[cur]) numZeroes--;
	aCnt[cur]--;
	if(aCnt[cur] == bCnt[cur]) numZeroes++;
}


int main()
{
    si3(n,m,p); 
    for (int i = 0; i < n; ++i) {
    	si(a[i]);
    	tmp[i] = a[i];
    }
    for (int i = 0; i < m; ++i) {
    	si(b[i]);
    	dis.insert(b[i]);
    	tmp[n+i] = b[i];
    }
    //compression start
    sort(tmp,tmp+n+m);
    compress[tmp[0]] = 1;
    int cur = 2;
    for (int i = 1; i < m+n; ++i) {
    	if(tmp[i] != tmp[i-1]) {
    		compress[tmp[i]] = cur;
    		cur++;
    	}
    }
    for (int i = 0; i < n; ++i) a[i] = compress[a[i]];
    for (int i = 0; i < m; ++i) b[i] = compress[b[i]];
    //compression over
    for (int i = 0; i < n; ++i) level[i%p].pb(mp(a[i],i+1));
    for (int i = 0; i < m; ++i) bCnt[b[i]]++;
    for (int i = 0; i < p; ++i) {
    	int j = 0;
    	while(j < m && j < level[i].size()) {
    		add(level[i][j].FF);
    		Q.pb(level[i][j]);
    		j++;
    	}
    	if(numZeroes == dis.size()) ans.pb(Q.front().SS);
    	for ( ; j < level[i].size(); ++j) {
    		removE(Q.front().FF);
    		Q.pop_front();
    		add(level[i][j].FF);
    		Q.pb(level[i][j]);
    		if(numZeroes == dis.size()) ans.pb(Q.front().SS);
    	}
    	while(!Q.empty()) {
    		removE(Q.front().FF);
    		Q.pop_front();
    	}
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for (int i = 0; i < ans.size(); ++i) {
    	printf("%d ",ans[i]);
    }
    return 0;
}