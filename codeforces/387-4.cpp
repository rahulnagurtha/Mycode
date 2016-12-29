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

#define SYNC                    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
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






bool cmp(PII lft,PII ryt) {
	if(lft.SS != ryt.SS) return lft.SS > ryt.SS;
	else return lft.FF < ryt.FF;
}


int main()
{
	SYNC;
	int n,k,tmp;
	VOII data;
	int ans = 0;
	int minRequired = 0;
	deque<int> Q;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if(tmp < 0) {
			minRequired++;
			Q.pb(0);
		}
		else {
			Q.pb(1);
		}
	}
	if(minRequired > k) {
		cout << "-1" << endl;
		return 0;
	}
	int cnt = 0;
	while(!Q.empty() && Q.front() == 1) {
		cnt++;
		Q.pop_front();
	}
	if(Q.size() > 0) ans++;
	cnt = 0;
	while(!Q.empty() && Q.back() == 1) {
		cnt++;
		Q.pop_back();
	}
	if(cnt > 0) data.pb(mp(cnt,1));
	while(!Q.empty()) {
		//remove all zeroes
		while(!Q.empty() && Q.front() == 0) {
			Q.pop_front();
		}
		int numOfOnes = 0;
		while(!Q.empty() && Q.front() == 1) {
			numOfOnes++;
			Q.pop_front();
		}
		if(numOfOnes > 0) data.pb(mp(numOfOnes,2));
	}
	sort(data.begin(),data.end(),cmp);
	int remaining = k - minRequired;
	for (int i = 0; i < data.size(); ++i) {
		if(remaining >= data[i].FF) {
			remaining -= data[i].FF;
		}
		else {
			ans += data[i].SS;
		}
	}
	cout << ans << endl;
    return 0;
}