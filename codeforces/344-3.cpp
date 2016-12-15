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



VI ans;
int n,m;
int t,r;
int a[N];
deque<PII> Q;
map<int,int> visited;

int main()
{
	priority_queue<int,VI,less<int> > maxHeap;
	priority_queue<int,VI,greater<int> > minHeap;
	si2(n,m);
	for (int i = 1; i <= n; ++i) {
		si(a[i]);
		visited[a[i]]++;
	}
	for (int i = 0; i < m; ++i) {
		si2(t,r);
		while(!Q.empty() && (Q.back().SS <= r)) {
			Q.pop_back();
		}
		Q.pb(mp(t,r));
	}
	for (int i = n; i >= Q.front().SS + 1; --i) {
		ans.pb(a[i]);
		visited[a[i]]--;
	}
	for (int i = 1; i <= Q.front().SS; ++i) {
		maxHeap.push(a[i]);
		minHeap.push(a[i]);
	}
	while(!Q.empty()) {
		PII tmp = Q.front();
		Q.pop_front();
		int lft = (Q.size() > 0 ? Q.front().SS + 1 : 1);
		int ryt = tmp.SS;
		int cnt = ryt - lft + 1;
		if(tmp.FF == 1) {
			while(cnt > 0) {
				if(visited[maxHeap.top()] > 0) {
					ans.pb(maxHeap.top());
					visited[maxHeap.top()]--;
					cnt--;
				}
				maxHeap.pop();
			}
		}
		else {
			while(cnt > 0) {
				if(visited[minHeap.top()] > 0) {
					ans.pb(minHeap.top());
					visited[minHeap.top()]--;
					cnt--;
				}
				minHeap.pop();
			}
		}
	}
	for (int i = ans.size() - 1; i >= 0; --i) {
		printf("%d ",ans[i]);
	}
	printf("\n");
    return 0;
}