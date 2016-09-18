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
#define slli(i)                 scanf("%lld",&i)
#define slli2(i,j)              scanf("%lld %lld",&i,&j)
#define slli3(i,j,k)            scanf("%lld %lld %lld",&i,&j,&k)

#define pi(i)                   printf("%d\n",i)
#define plli(i)                 printf("%lld\n",i)

#define SYNC                    ios_base::sync_with_stdio(0)
#define mp                      make_pair
#define FF                      first
#define SS                      second
#define pb                      push_back
#define fill(a,v)               memset(a,v,sizeof a)
#define ceil(a,b)               (((a)%(b)==0)?((a)/(b)):((a)/(b)+1))
#define rem(a,b)                ((a<0)?((((a)%(b))+(b))%(b)):((a)%(b)))
#define MOD                     1000000007LL
#define INF                     INT_MAX
#define N                       100007


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

int cnt[N];

int main()
{
	priority_queue<int,VI,greater<int> > minHeap;
	priority_queue<int,VI,less<int> > maxHeap;
    int q,x;
    int type;
    cin >> q;
    for (int i = 0; i < q; ++i) {
    	cin >> type;
    	if(type == 1) {
    		cin >>x;
    		cnt[x]++;
    		minHeap.push(x);
    		maxHeap.push(x);
    	}
    	else if(type == 2) {
    		cin >> x;
    		if(cnt[x] > 0) cnt[x]--;
    		else cout << "-1" << endl;
    	}
    	else if(type == 3) {
    		while(!maxHeap.empty() && cnt[maxHeap.top()] <= 0) {
    			maxHeap.pop();
    		}
    		if(maxHeap.empty()) cout << "-1" << endl;
    		else cout << maxHeap.top() << endl;
    	}
    	else {
    		while(!minHeap.empty() && cnt[minHeap.top()] <= 0) {
    			minHeap.pop();
    		}
    		if(minHeap.empty()) cout << "-1" << endl;
    		else cout << minHeap.top() << endl;
    	}
    }
    return 0;
}