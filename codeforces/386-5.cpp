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

#define	forup(i,a,b) 			for(int i = (a); (i) < (b); ++(i))
#define fordn(i,a,b) 			for(int i = (a); (i) > (b); --(i))
#define rep(i,a) 				for(int i = 0; (i) < (a); ++(i))

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



set<ll> oddNumbers;
set<ll> evenNumbers;
VL auxOdd;
VL auxEven;

VL A;
VL ans;

int main()
{
	ll n,m,tmp;
	ll cnt;
	slli2(n,m);
	cnt = n;
	for (int i = 0; i < n; ++i) {
		slli(tmp);
		A.pb(tmp);
		if(tmp%2 == 0) evenNumbers.insert(tmp);
		else oddNumbers.insert(tmp);
	}
	for (int i = 0; i < n; ++i) {
		ans.pb(-1);
	}
	if(evenNumbers.size() > n/2) {
		for (auto it = evenNumbers.begin(); it != evenNumbers.end(); ++it) {
			auxEven.pb(*it);
			if(auxEven.size() == n/2) break;
		}
		evenNumbers.clear();
		for (int i = 0; i < auxEven.size(); ++i) {
			evenNumbers.insert(auxEven[i]);
		}
	}
	if(oddNumbers.size() > n/2) {
		for (auto it = oddNumbers.begin(); it != oddNumbers.end(); ++it) {
			auxOdd.pb(*it);
			if(auxOdd.size() == n/2) break;
		}
		oddNumbers.clear();
		for (int i = 0; i < auxOdd.size(); ++i) {
			oddNumbers.insert(auxOdd[i]);
		}
	}
	ll nxt = 1;
	while(nxt <= m && oddNumbers.size() + evenNumbers.size() < n) {
		if(nxt % 2 == 0 && evenNumbers.size() < n/2) {
			evenNumbers.insert(nxt);
		}
		else if(nxt % 2 == 1 && oddNumbers.size() < n/2) {
			oddNumbers.insert(nxt);
		}
		nxt++;
	}
	if(oddNumbers.size() + evenNumbers.size() < n) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if(A[i]%2 == 0) {
			if(evenNumbers.find(A[i]) != evenNumbers.end()) {
				//found
				cnt--;
				ans[i] = A[i];
				evenNumbers.erase(A[i]);
			}
		}
		else {
			if(oddNumbers.find(A[i]) != oddNumbers.end()) {
				//found
				cnt--;
				ans[i] = A[i];
				oddNumbers.erase(A[i]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if(ans[i] == -1) {
			if(oddNumbers.size() > 0) {
				auto it = oddNumbers.begin();
				ans[i] = *it;
				oddNumbers.erase(*it);
			}
			else if(evenNumbers.size() > 0) {
				auto it = evenNumbers.begin();
				ans[i] = *it;
				evenNumbers.erase(*it);	
			}
		}
	}
	printf("%I64d\n",cnt);
	for (int i = 0; i < n; ++i) {
		printf("%I64d ",ans[i]);
	}
	cout << endl;
    return 0;
}